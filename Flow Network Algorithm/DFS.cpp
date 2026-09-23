#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void DFS(vector<vector<int>>& graph,int src,vector<bool>& vis){

    int n = graph.size()-1;
    vis[src] = true;
    cout<<src<<" ";

    for(int j = 1;j<=n;j++){

        if(graph[src][j] != 0 && !vis[j]){

            DFS(graph,j,vis);

        }
    }
}
int main()
{
    int v,e;
    cin>>v>>e;

    vector<vector<int>>graph(v+1,vector<int>(v+1,0));

    for(int i = 0;i<e;i++){

        int u,v,w;
        cin>>u>>v>>w;

        graph[u][v] = w;
        graph[v][u] = w;

    }

    int src;
    cin>>src;

    vector<bool>vis(v+1,false);

    DFS(graph,src,vis);

    return 0;


}
