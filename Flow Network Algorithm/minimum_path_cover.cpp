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

    int V,E;
    cin>>V>>E;

    int s = 0;
    int ls = 1;
    int rs = V+1;
    int t = 2*V+1;

    vector<vector<int>>graph(2 * V + 2,vector<int>(2 * V + 2, 0));

    for(int i = 1;i<=V;i++){

        graph[s][ls+i-1] = 1;
        graph[rs+i-1][t] = 1;

    }

    for(int i = 0;i<E;i++){

        int u,v;
        cin>>u>>v;

        graph[ls+u-1][rs+v-1] = 1;

    }

    int matching = EdmondsKarp(graph,s,t);
    int minimumPathCover = V-matching;

    cout << "Minimum Path Cover = "
         << minimumPathCover << endl;

    return 0;


}