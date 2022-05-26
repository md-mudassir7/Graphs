#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> topoSort(int N, vector <int> adj[]) {
      queue<int> q;
      vector<int> indegree(N,0);
      for(int i=0;i<N;i++){
          for(auto it: adj[i]){
              indegree[it]++;
          }
      }
      for(int i=0;i<N;i++){
          if(indegree[i]==0)
          {
              q.push(i);
          }
      }
      vector<int> topo;
      while(!q.empty()){
          int node = q.front();
          q.pop();
          topo.emplace_back(node);
          for(auto it : adj[node]){
              indegree[it]--;
              if(indegree[it]==0)
                q.push(it);
          }
      }
      return topo;
    }
};

// { Driver Code Starts.
int main() {

  int N = 6;

  vector < int > adj[5 + 1];

  adj[5].push_back(2);
  adj[5].push_back(0);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  Solution obj;
  vector < int > res = obj.topoSort(6, adj);

  cout << "Toposort of the given graph is:" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
} 