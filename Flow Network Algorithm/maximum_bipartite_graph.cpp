#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
bool BFS(vector<vector<int>>& graph, int s, int t, vector<int>& par){

    int n = graph.size();

    vector<bool>vis(n,false);
    queue<int>q;
    vis[s] = true;
    par[s] = -1;
    q.push(s);

    while(!q.empty()){

        int front = q.front();
        q.pop();

        for(int j = 0;j<n;j++){

            if(!vis[j] && graph[front][j]>0){

                vis[j] = true;
                par[j] = front;

                if(j == t) return true;
                q.push(j);

            }
        }
    }

    return false;
    
}
int EdmondsKarp(vector<vector<int>>& graph, int s, int t){

    int n = graph.size();
    int maxflow = 0;

    vector<int>par(n);

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

    return maxflow;


}
int main()
{

    int l,r;
    cin>>l>>r;

    int V = l+r+2;
    int s = 0;
    int t = V-1; 

    vector<vector<int>>graph(V,vector<int>(V,0));

    for(int i = 1;i<=l;i++){
        graph[s][i] = 1;

    }

    for(int j = 1;j<=r;j++){
        graph[l+j][t] = 1;
        
    }

    int E;
    cin>>E;

    for(int i = 0; i < E; i++){

        int u,v;
        cin>>u>>v;

        graph[u][l + v] = 1;
    }

    cout << "Maximum Bipartite Matching = "
         << EdmondsKarp(graph,s,t);

    return 0;


}