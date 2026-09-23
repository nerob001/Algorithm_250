#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    int n;
    cout<<"Enter number of items : ";
    cin>>n;

    cout<<"Enter profit & weight of each items : \n";
    vector<int>profit(n+1),weight(n+1),ratio(n+1);

    for(int i = 1;i<=n;i++){

        cin>>profit[i]>>weight[i];
        ratio[i] = double(profit[i])/weight[i];

    }

    double capacity;
    cout<<"Enter capacity : ";
    cin>>capacity;

    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){

            if(ratio[i]<ratio[j]){

                swap(ratio[i],ratio[j]);
                swap(profit[i],profit[j]);
                swap(weight[i],weight[j]);

            }

        }
    }

    double ans = 0;

    for(int i = 1;i<=n;i++){

        if(weight[i]<=capacity){

            ans += profit[i];
            capacity -= weight[i];

            cout<<"Item : "<<i<<" -> 100%\n";

        }

        else{

            double ratio = (double)capacity/weight[i];
            ans += profit[i]*ratio;
            cout<<"Item : "<<i<<" -> "<<ratio*100<<"\n";
            break;

        }

    }

    cout<<"Total profit : "<<ans <<"\n";
    
    return 0;
    

}

//O(n^2) time complexity
