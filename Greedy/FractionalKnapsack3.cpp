#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Item{

    int id;
    int profit;
    int weight;

};

struct compare{

    bool operator()(Item a,Item b){

        double r1 = (double)a.profit/a.weight;
        double r2 = (double)b.profit/b.weight;

        return r1<r2;

    }
};

int main()
{

    int n;
    cout<<"Enter number of items : ";
    cin>>n;

    priority_queue<Item,vector<Item>,compare>pq;
    
    cout<<"Enter profit & weight of each items : \n";

    for(int i = 1;i<=n;i++){

        int profit,weight;
        cin>>profit>>weight;
        pq.push({i,profit,weight});

    }

    double capacity;
    cout<<"Enter capacity : ";
    cin>>capacity;

    double ans = 0.0;

    while(!pq.empty() && capacity>0){

        Item res = pq.top();
        pq.pop();

        if(res.weight<=capacity){

            ans += res.profit;
            capacity -= res.weight;
            cout<<"Item :"<<res.id<<" -> 100%\n";

        }

        else{

            double ratio = (double)capacity/res.weight;
            ans += res.profit*ratio;
            cout<<"Item :"<<res.id<<" -> "<<ratio*100<<"\n";
            break;

        }
    }

    cout<<"Total profit : "<<ans<<"\n";

    return 0;

}

