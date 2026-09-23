#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Item{

    int id;
    double profit;
    double weight;

};

bool compare(Item a,Item b){
    

    double r1 = (double)a.profit/a.weight;
    double r2 = (double)b.profit/b.weight;

    return r1>r2;
    
}

int main()
{
    int n;
    cout<<"Enter number of items : ";
    cin>>n;

    vector<Item> items(n);

    for(int i = 0;i<n;i++){

       items[i].id = i+1;
       cin>>items[i].profit>>items[i].weight;

    }

    double capacity;
    cout<<"Enter Capacity : ";
    cin>>capacity;

    sort(items.begin(),items.end(),compare);

    double ans = 0.0;

    for(int i = 0;i<n;i++){

        if(items[i].weight<=capacity){

            ans += items[i].profit;
            capacity -= items[i].weight;
            cout<<"Item : "<<items[i].id<<" -> 100%\n";

        }

        else{

            double ratio = (double)capacity/items[i].weight;
            ans += ratio*items[i].profit;
            cout<<"Item : "<<items[i].id<<" -> "<<ratio*100<<"\n";
            break;
            
        }
    }

    cout<<"Total Profit : "<<ans<<"\n";

    return 0;

}
//O(nlogn) time complexity