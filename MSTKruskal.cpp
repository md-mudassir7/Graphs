#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
int findParent(int node,vector<int> &parent){
    if(parent[node]==node){
        return node;
    }
    return parent[node] = findParent(parent[node],parent);
}
void Union(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findParent(u,parent);
    v = findParent(v,parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(),edges.end(),compare);
    int ans = 0;
    vector<int> rank(n);
    vector<int> parent(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    for(int i=0;i<edges.size();i++){
        if(findParent(edges[i][0],parent)!=findParent(edges[i][1],parent)){
            Union(edges[i][0],edges[i][1],parent,rank);
            ans+= edges[i][2];
        }
    }
    return ans;
}