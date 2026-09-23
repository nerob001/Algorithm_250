#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, target;

    cout << "Enter number of elements and target sum" << endl;
    cin >> n >> target;

    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for(int i = 0;i<=n;i++){

        dp[i][0]  = true;

    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=target;j++){

            if(arr[i]<=j){

                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];

            }


            else{

                dp[i][j] = dp[i-1][j];

            }
        }
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=target;j++){

            cout<<dp[i][j]<<" ";
        }

        cout<<"\n";

    }

    if(!dp[n][target]){

        cout<<"No subset exists";
        return 0;

    }

    cout<<"subset exists";

    vector<int>ans;

    int i = n;
    int j = target;

    while(i>0 && j>0){

        if(dp[i][j] != dp[i-1][j]){

            ans.push_back(arr[i]);
            j -= arr[i];

        }

        i--;

    }

    reverse(ans.begin(),ans.end());

    for(int x : ans){

        cout<<x<<" ";

    }

    return 0;
}
