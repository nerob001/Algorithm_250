#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
void Prims(int src,vector<vector<pair<int,int>>> &adj,int V){

    priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>>pq;

    vector<int>key(V,INT_MAX);
    vector<int>par(V,-1);
    vector<bool>visited(V,false);

    key[src] = 0;

    pq.push({key[src],src});

    while(!pq.empty()){

        int dist = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(visited[node]) continue;

        for(auto it : adj[node]){

            int neigh = it.first;
            int wt = it.second;

            if(!visited[neigh] && wt<key[neigh]){

                key[neigh] = wt;
                par[neigh] = node;
                pq.push({key[neigh],neigh});

            }

        }

        visited[node] = true;

    }

    cout<<"MST edges :\n";
    int tc = 0;

    for(int i = 0;i<V;i++){

        cout<<par[i]<<" -> "<<i<<" weight : "<<key[i]<<"\n";
        tc += key[i];

    }

    cout<<"Total costs : "<<tc<<"\n";

    return;



}
int main()
{
    int V,E;
    cout<<"ENter edges and vertices : \n";
    cin>>V>>E;

    vector<vector<pair<int,int>>>adj(V);

    for(int i = 0;i<E;i++){

        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }

    cout<<"Enter source : ";
    int src;
    cin>>src;

    Prims(src,adj,V);

    return 0;


}