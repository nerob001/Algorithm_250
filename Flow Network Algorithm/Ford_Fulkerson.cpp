#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
bool DFS(vector<vector<int>>& graph,int s,int t,vector<int>& par,vector<bool>& vis){

    vis[s] = true;
    if(s == t) return true;

    for(int j = 0;j<graph.size();j++){

        if(!vis[j] && graph[s][j] != 0){

            par[j] = s;

            if(DFS(graph,j,t,par,vis)) return true;

        }
    }


    return false;

}
int main()
{

    int V,E;
    cin>>V>>E;

    vector<vector<int>>graph(V,vector<int>(V,0));

    for(int i = 0;i<E;i++){

        int u,v,w;
        cin>>u>>v>>w;

        graph[u][v] = w;

    }

    int s,t;
    cin>>s>>t;

    int maxflow = 0;

    vector<int>par(V);
    
    while(true){

        vector<bool>vis(V,false);

        if(!DFS(graph,s,t,par,vis)) break;

        int flow = INT_MAX;

        int v = t;

        while(v != s){

            int u = par[v];
            flow = min(flow,graph[u][v]);

            v = u;

        }

        v = t;
        while(v != s){

            int u = par[v];
            graph[u][v] -= flow;
            graph[v][u] += flow;

            v = u;

        }

        maxflow += flow;

    }

    cout<<"Maximum flow : "<<maxflow<<"\n";


    return 0;

}
