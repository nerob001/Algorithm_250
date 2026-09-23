#include<iostream>
#include<vector>
using namespace std;
int V,C;
vector<int>soln;
vector<vector<int>>adj;

bool isSafe(int vertex,int color){

    for(int i = 1;i<=V;i++){

        if(adj[vertex][i] == 1 && soln[i] == color) return false;

    }

    return true;

}

void mcoloring(int vertex){

    if(vertex>V){

        static int solution = 1;
        cout<<"Enter solution no - "<<solution++<<" : ";

        for(int i = 1;i<=V;i++){

            cout<<soln[i]<<" ";

        }

        cout<<"\n\n";

        return;

    }

    for(int color = 1;color<=C;color++){

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
    cout<<"Enter number of vertices & colors : ";
    cin>>V>>C;

    adj.resize(V+1,vector<int>(V+1));

    for(int i = 1;i<=V;i++){
        for(int j = 1;j<=V;j++){

            cin>>adj[i][j];

        }
    }

    soln.resize(V+1);

    mcoloring(1);

    return 0;

}