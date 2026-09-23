#include<iostream>
#include<vector>
using namespace std;
vector<bool>flag;

void SOS(vector<int> &v,int idx,int currentSum,int remainingSum,int tar){

    int n = v.size();

    if(currentSum == tar){

        cout<<"{ ";

        for(int i = 0;i<n;i++){

            if(flag[i]) cout<<v[i]<<" ";

        }

        cout<<"}\n";

        return;

    }

    if(idx == n || currentSum > tar) return;

    if(currentSum + remainingSum < tar) return;

    //include
    flag[idx] = true;
    SOS(v,idx+1,currentSum+v[idx],remainingSum-v[idx],tar);

    //exclude
    flag[idx] = false;
    SOS(v,idx+1,currentSum,remainingSum-v[idx],tar);

    return;

}
int main()
{

    int n;
    cout<<"Enter array size : ";
    cin>>n;

    flag.resize(n,false);

    vector<int>v(n);
    int remainingSum = 0;
    int currentSum = 0;

    for(int i = 0;i<n;i++){

        cin>>v[i];
        remainingSum += v[i];


    }

    int tar;
    cout<<"Enter target : ";
    cin>>tar;

    SOS(v,0,currentSum,remainingSum,tar);

    return 0;

}