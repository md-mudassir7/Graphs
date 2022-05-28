#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

class Solution{
public:
    void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it.first]) {
                findTopoSort(it.first, vis, st, adj); 
            }
        }
        st.push(node);
    }


    void shortestPath(int src, int N, vector<pair<int,int>> adj[]) 
    { 
        int vis[N] = {0};
        stack<int> st; 
        //find toposort
        for (int i = 0; i < N; i++) 
            if (!vis[i]) 
                findTopoSort(i, vis, st, adj); 
        //Intution behind Topological sorting and why haven't we use simple DFS or BFS from the source node instead .
        // lets say you want to do it using DFS
        // yes you can do it using DFS , but consider the case when you already updated a node's distance by a dfs() call and lets say its 7 and 
        // as it is DFS then its obvious that you also have updated all the nodes in its segment of DFS call . 
        // now you have reached to the same node from different dfs() call and now the distance is 4 , 
        // so in order to update all the nodes which were affected by the DFS call previously on the node considering distance as 7 , 
        // you now again have to do the same so that its updated with new min distance.
        // Same is the scenario for the simple BFS approach.
        // This multiple time calling DFS/BFS degrades the Time Complexity, 
        // hence Topological Ordering save you from that overhead as you already know which nodes will come after the current node , 
        // so you keep on updating it
        int dist[N]; 
        for (int i = 0; i < N; i++) 
            dist[i] = 1e9; 
        dist[src] = 0; 

        while(!st.empty()) 
        {  
            int node = st.top(); 
            st.pop(); 
    
            if (dist[node] != INF) {
                for(auto it : adj[node]) {
                    if(dist[node] + it.second < dist[it.first]) {
                        dist[it.first] = dist[node] + it.second; 
                    }
                }
            }
        } 

        for (int i = 0; i < N; i++) 
            (dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
    } 
};