#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
bool BFS(vector<vector<int>>& graph,int s,int t,vector<int>& par){

    int n = graph.size();
    vector<bool>vis(n,false);
    queue<int>q;

    vis[s] = true;
    q.push(s);
    par[s] = -1;

    while(!q.empty()){

        int front = q.front();
        q.pop();

        for(int j = 0;j<n;j++){

            if(!vis[j] && graph[front][j] != 0){

                vis[j] = true;
                par[j] = front;

                if(j == t) return true;
                q.push(j);


            }
        }
    }

    return false;
    
}
int main()
{
    int V,E;
    cin>>V>>E;

    vector<vector<int>>graph(V,vector<int>(V+1));

    for(int i = 0;i<E;i++){

        int u,v,w;
        cin>>u>>v>>w;

        graph[u][v] = w;

    }

    int s,t;
    cin>>s>>t;

    int maxflow = 0;

    vector<int>par(V);

    while(BFS(graph,s,t,par)){

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