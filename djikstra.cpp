#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void djikstra(int source,int n,vector<pair<int,int> > g[]){
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
        vector<int> distTo(n+1,INT_MAX);//1-indexed array for calculating shortest paths
        distTo[source] = 0;
        pq.push(make_pair(0,source));	// (dist,source)
        while( !pq.empty() ){
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            vector<pair<int,int> >::iterator it;
            for( it = g[prev].begin() ; it != g[prev].end() ; it++){
                int next = it->first;
                int nextDist = it->second;
                if( distTo[next] > distTo[prev] + nextDist){
                    distTo[next] = distTo[prev] + nextDist;
                    pq.push(make_pair(distTo[next], next));
                }
            }
        }
        cout << "The distances from source " << source << " are : \n";
        for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
        cout << "\n";
    }
};