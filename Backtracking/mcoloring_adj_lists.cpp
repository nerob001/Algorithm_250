#include<iostream>
#include<vector>
using namespace std;
int v,c,e;
vector<vector<int>>adj;
vector<int>soln;

bool isSafe(int vertex,int color){

    for(int neigh : adj[vertex]){

        if(soln[neigh] == color) return false;

    }

    return true;

}

void mcoloring(int vertex){

    if(vertex>v){

        static int solution = 1;
        cout<<"Solution no - "<<solution++<<" : ";

        for(int i = 1;i<=v;i++){

            cout<<soln[i]<<" ";

        }

        cout<<"\n\n";

        return;

    }
    
    for(int color = 1;color<=c;color++){

        if(isSafe(vertex,color)){

            soln[vertex] = color;
            mcoloring(vertex+1);
            soln[vertex] = 0;

        }
    }

    return;

}
int main()
{

    cout<<"Enter number of vertices and edges : ";
    cin>>v>>e;
    cout<<"Enter number of colors : ";
    cin>>c;

    adj.resize(v+1);
    soln.resize(v+1,0);

    cout<<"Enter egdes : ";
    for(int i = 1;i<=e;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    mcoloring(1);

    return 0;

}