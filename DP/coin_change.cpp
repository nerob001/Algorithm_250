#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    int n,amount;
    cout<<"Enter number of coins and amount : ";
    cin>>n>>amount;

    vector<int>coins(n+1);

    cout<<"Enter coins : \n";

    for(int i = 1;i<=n;i++){

        cin>>coins[i];

    }

    const int INF = INT_MAX;

    vector<vector<int>>dp(n+1,vector<int>(amount+1,INF));

    for(int i = 0;i<=n;i++){

        dp[i][0] = 0;

    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=amount;j++){

            if(coins[i]<=j){

                dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i]]);

            } 

            else{

                dp[i][j] = dp[i-1][j];

            }
        }
    }

    cout<<"DP Table : "<<"\n";

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=amount;j++){

            cout<<dp[i][j]<<" ";

        }

        cout<<"\n";

    }

    if(dp[n][amount] == INF){

        cout<<"No solution exists\n";
        return 0;

    }

    cout<<"Minimum number of coins : "<<dp[n][amount]<<"\n";

    vector<int>selected;

    int i = n;
    int j = amount;

    while(i>0 && j>0){

        if(dp[i][j] == dp[i-1][j]){

            i--;

        }

        else{

            selected.push_back(coins[i]);
            j -= coins[i];

        }
    }

    reverse(selected.begin(),selected.end());

    for(int it : selected){

        cout<<it<<" ";

    }

    return 0;

}