#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 1e9;
void Dijstra(int src,int dest,vector<vector<int>> &adj,int V){

    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>>pq;

    vector<int>dis(V,INF);
    vector<int>par(V,-1);
    vector<bool>visited(V,false);

    dis[src] = 0;
    pq.push({0,src});

    while(!pq.empty()){

        int dist = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(visited[node]) continue;

        visited[node] = true;

        for(int neigh = 0;neigh<V;neigh++){
            int wt = adj[node][neigh];
            if(!visited[neigh] && wt != 0 && dist+wt<dis[neigh]){

                dis[neigh] = dist+wt;
                par[neigh] = node;
                pq.push({dis[neigh],neigh});


            }

        }
    }

    cout<<"Shortest distance : \n";

    for(int i = 0;i<V;i++){

        cout<<i<<" -> "<<dis[i]<<"\n";

    }

    cout<<"\nParents : \n";

    for(int i = 0;i<V;i++){

        cout<<par[i]<<" -> "<<i<<"\n";
        
    }

    vector<int>path;

    while(dest != -1){

        path.push_back(dest);
        dest = par[dest];

    }

    cout<<"Shortest path : ";
    for(int i = path.size()-1;i>=0;i--){

        cout<<path[i];

        if(i != 0) cout<<" -> ";

    }

}
int main()
{

    cout<<"Enter vertices & edges : \n";
    int V,E;
    cin>>V>>E;

    vector<vector<int>>adj(V,vector<int>(V));

    for(int i = 0;i<E;i++){

        int u,v,w;
        cin>>u>>v>>w;

        adj[u][v] = w;
        // adj[v][u] = w;

    }

    int src;
    cout<<"Enter source : ";
    cin>>src;

    int dest;
    cout<<"Enter destination : ";
    cin>>dest;

    Dijstra(src,dest,adj,V);

    return 0;

}
