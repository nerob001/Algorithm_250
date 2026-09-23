#include<iostream>
#include<vector>
using namespace std;

int n,capacity;
vector<int>weight;
vector<int>profit;
int maxProfit = 0;

void Knapsack(int item,int wt,int pft){

    if(item > n+1){

        maxProfit = max(maxProfit,pft);
        return;

    }

    //take item
    if(wt+weight[item]<=capacity){

        Knapsack(item+1,wt+weight[item],pft+profit[item]);

    }

    //dont take item
    Knapsack(item+1,wt,pft);

}

int main()
{
    cin>>n>>capacity;

    weight.resize(n+1);
    profit.resize(n+1);

    for(int i = 1;i<=n;i++){

        cin>>weight[i]>>profit[i];

    }

    Knapsack(1,0,0);

    cout<<"Maximum profit : "<<maxProfit<<"\n";

    return 0;

}