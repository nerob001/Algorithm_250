#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{

    string s1;// columns
    cin>>s1; 
    int m = s1.length();


    string s2; // rows
    cin>>s2;
    int n = s2.length();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    //Build Table
    for(int i = 1;i<=n;i++){// s2
        for(int j = 1;j<=m;j++){ // s1

            if(s2[i-1] == s1[j-1]){

                dp[i][j] = dp[i-1][j-1] + 1;

            }

            else{

                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

            }

        }

    }

    //Print table
    for(int i = 1;i<=n;i++){ // s2
        for(int j = 1;j<=m;j++){ // s1

            cout<<dp[i][j]<<" ";

        }

        cout<<"\n";

    }

    cout<<"Length pf LCS : "<<dp[n][m]<<"\n";

    string lcs = "";

    int i = n; // s2
    int j = m; // s1

    while(i>0 && j>0){

        if(s2[i-1] == s1[j-1]){

            lcs += s2[i-1];
            i--;
            j--;

        }

        else if(dp[i-1][j] >dp[i][j-1]){

            i--;

        }

        else{

            j--;

        }
    }

    reverse(lcs.begin(),lcs.end());

    cout<<"LCS = "<<lcs<<"\n";

    return 0;


}
