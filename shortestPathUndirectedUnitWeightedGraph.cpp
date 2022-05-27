#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void BFS(vector<int> adj[], int N, int src) 
    { 
        int dist[N];
        for(int i = 0;i<N;i++) 
            dist[i] = INT_MAX; 
        queue<int>  q;
        dist[src] = 0;
        q.push(src); 
        while(!q.empty()) 
        { 
            int node = q.front(); 
            q.pop();
            
            for(auto it:adj[node]){
                if(dist[node] + 1 < dist[it]){
                    //If the previous reachable distance of any node is less than the current reachable distance, then push it in the queue
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            } 
        } 
        for(int i = 0;i<N;i++) 
            cout << dist[i] << " ";
    } 
};