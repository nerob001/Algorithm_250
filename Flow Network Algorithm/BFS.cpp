#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void BFS(vector<vector<int>>& graph,int src){

    int n = graph.size()-1;
    vector<bool>vis(n+1,false);
    queue<int>q;

    vis[src]  = true;
    q.push(src);

    while(!q.empty()){

        int front = q.front();
        cout<<front<<" ";
        q.pop();
        for(int j = 1;j<=n;j++){
            if(graph[front][j] != 0 && vis[j] == false){

                q.push(j);
                vis[j] = true;


            }
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

    BFS(graph,src);

    return 0;


}
