#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool isCycle(int N, vector <int> adj[]) {
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
      int cnt = 0;
      while(!q.empty()){
          int node = q.front();
          q.pop();
          cnt++;
          for(auto it : adj[node]){
              indegree[it]--;
              if(indegree[it]==0)
                q.push(it);
          }
      }
      return cnt!=N;
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
  bool res = obj.isCycle(6, adj);
  if(res)
    cout<<"There is a cycle is the graph\n";
  else
    cout<<"There is No cycle in the graph\n";
  cout << "Toposort of the given graph is:" << endl;
  return 0;
} 