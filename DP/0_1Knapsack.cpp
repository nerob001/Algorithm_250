#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,W;
    cout<<"Enter number of objects and capacity : "<<"\n";
    cin>>n>>W;

    vector<int>weight(n+1);
    vector<int>profit(n+1);

    for(int i = 1;i<=n;i++){

        cout<<"Enter weight and profit of object - "<<i<<" : "<<"\n";
        cin>>weight[i]>>profit[i];

    }

    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    // Build DP Table
    for(int i = 1;i<=n;i++){
        for(int w = 1   ;w<=W;w++){

            if(weight[i] <= w){

                dp[i][w] = max(dp[i-1][w],profit[i] + dp[i-1][w-weight[i]]);

            }

            else{

                dp[i][w] = dp[i-1][w];

            }
        }
    }

    // Print DP Table

    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=W;w++){

            cout<<dp[i][w]<<" ";

        }

        cout<<"\n";

    }

    cout<<"Maximum Profit : "<<dp[n][W]<<"\n";

    vector<int>selected;
    int c = W;

    for(int i = n;i>0;i--){

        if(dp[i][c] != dp[i-1][c]){

            selected.push_back(i);
            c -= weight[i];

        }
    }
    
    reverse(selected.begin(),selected.end());

    cout<<"Selected item : \n";

    for(int it : selected){

        cout<<"item no : "<<it<<" weight : "<<weight[it]<<" profit : "<<profit[it]<<"\n";

    }


    return 0;

}