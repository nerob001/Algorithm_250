#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
void Prims(int src,vector<vector<int>> &adj,int V){

    priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>> pq;

    vector<int>key(V,INT_MAX);
    vector<int>par(V,-1);
    vector<bool>vis(V,false);

    key[src] = 0;
    pq.push({key[src],src});

    while(!pq.empty()){

        int node = pq.top().second;
        pq.pop();

        if(vis[node]) continue;

        vis[node]  = true;

        for(int neigh = 0;neigh<V;neigh++){

            int wt = adj[node][neigh];

            if(!vis[neigh] && wt != 0 && wt<key[neigh]){

                key[neigh] = wt;
                par[neigh] = node;
                pq.push({key[neigh],neigh});

            }
        }
    }

    cout<<"MST edges : \n";
    int tc = 0;

    for(int i = 0;i<V;i++){

        cout<<par[i] <<" -> "<<i<<" Weight : "<<key[i]<<"\n";
        tc += key[i];

    }

    cout<<"Total cost : "<<tc<<"\n";

    return;

}
int main()
{
    cout<<"Enter edges and vertices :\n";
    int V,E;
    cin>>V>>E;

    vector<vector<int>> adj(V,vector<int>(V));

    for(int i = 0;i<E;i++){

        int u,v,w;
        cin>>u>>v>>w;

        adj[u][v] = w;
        adj[v][u] = w;

    }

    cout<<"Enter source :\n";
    int src;
    cin>>src;

    Prims(src,adj,V);

    return 0;


}