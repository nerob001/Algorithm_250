#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
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
    cin>>src;

    int dest;
    cin>>dest;

    vector<int>dist(V,INT_MAX);
    vector<int>par(V,-1);

    priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>>pq;


    dist[src] = 0;
    pq.push({0,src});
    int best = INT_MAX;

    while(!pq.empty()){

        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        
        //bound
        if(dis >= best) continue;

        if(node == dest){

            best = dis;
            continue;

        }

        // branch
        for(auto it : adj[node]){

            int neigh = it.first;
            int wt = it.second;

            if(dis+wt<dist[neigh]){

                dist[neigh] = dis+wt;
                par[neigh] = node;
                pq.push({dist[neigh],neigh});

            }

        }

    }

    cout<<"Shortest path cost : "<<dist[dest]<<" "<<best<<" \n";
    vector<int>path;

    int i = dest;
    while(i != -1){

        path.push_back(i);
        i = par[i];

    }

    cout<<"Path : ";
    for(int i = path.size()-1;i>=0;i--){

        cout<<path[i];

        if(i != 0) cout<<" -> ";

    }

    return 0;

}