#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> keys(n+1);
    vector<bool> mst(n+1);
    vector<int> par(n+1);
    for(int i=0;i<=n;i++){
        keys[i]=INT_MAX;
        mst[i]=false;
        par[i]=-1;
    }
    keys[1]=0;
    par[1]=-1;
    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        int u;
        for(int v=1;v<=n;v++){
            if(mst[v]==false and keys[v]<mini){
                mini = keys[v];
                u = v;
            }
        }
        mst[u]=true;
        for(auto node : adj[u]){
            int v = node.first;
            int weight = node.second;
            if(mst[v]==false and keys[v]>weight){
                par[v]=u;
                keys[v]=weight;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for(int i=2;i<=n;i++){
        result.push_back({{par[i],i},keys[i]});
    }
    return result;
}
