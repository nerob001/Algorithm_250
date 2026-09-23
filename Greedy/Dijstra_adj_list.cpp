#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 1e9;
void Dijstra(int src,int dest,vector<vector<pair<int,int>>> &adj,int V){

    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>>pq;

    vector<int>dist(V,INF);
    vector<int>par(V,-1);
    vector<bool>visited(V,false);

    dist[src] = 0;
    pq.push({0,src});

    while(!pq.empty()){

        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(visited[node]) continue;

        for(auto it : adj[node]){

            int neigh = it.first;
            int wt = it.second;

            if(!visited[neigh] && dis+wt<dist[neigh]){

                dist[neigh] = dis+wt;
                par[neigh] =  node;
                pq.push({dist[neigh],neigh});

            }

        }

        visited[node] = true;

    }

    cout<<"Shortest distance : \n";

    for(int i = 0;i<V;i++){

        cout<<i<<" -> "<<dist[i]<<"\n";

    }

    cout<<"\nParents :\n";
    for(int i = 0;i<V;i++){

        cout<<par[i]<<" -> "<<i<<"\n";

    }

    vector<int>Path;

    while(dest != -1){

        Path.push_back(dest);
        dest = par[dest];

    }

    for(int i = Path.size()-1;i>=0;i--){

        cout<<Path[i];

        if(i != 0) cout<<" -> ";

    }

}
int main()
{
    int V,E;
    cin>>V>>E;

    vector<vector<pair<int,int>>>adj(V);

    for(int i = 0;i<E;i++){

        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }

    int src;
    cout<<"Enter a source : \n";
    cin>>src;

     int dest;
    cout<<"Enter detination : \n";
    cin>>dest;

    Dijstra(src,dest,adj,V);


    return 0;

}