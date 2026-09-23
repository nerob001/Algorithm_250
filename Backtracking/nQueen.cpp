#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>soln;

bool isSafe(int row,int col){

    for(int i = 1;i<row;i++){

        if(soln[i] == col || abs(i-row) == abs(soln[i]-col)) return false;

    }

    return true;

}

void nQueen(int row){

    if(row>n){

        static int solution = 1;

        cout<<"Solution no : "<<solution++<<"\n";
        for(int i = 1;i<=n;i++){

            cout<<soln[i]<<" ";

        }

        cout<<"\n\n";
        return;

    }

    for(int col = 1;col<=n;col++){

        if(isSafe(row,col)){

            soln[row] = col;
            nQueen(row+1);
            soln[row] = 0;

        }
    }

    return;

}
int main()
{
    
    cout<<"Enter number of queens : ";
    cin>>n;

    soln.resize(n+1);
    nQueen(1);

    return 0;

}