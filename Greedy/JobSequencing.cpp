#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Job{

    char id;
    int deadline;
    int profit;

};

bool compare(Job a,Job b){

    return a.profit>b.profit;

}

int main()
{

    int n;
    cout<<"Ener number of jobs : ";
    cin>>n;

    vector<Job>jobs(n);

    cout<<"Enter Job id, Deadline,Profit : \n";

    for(int i = 0;i<n;i++){

        cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;

    }

    sort(jobs.begin(),jobs.end(),compare);

    int maxDeadline = 0;

    for(int i = 0;i<n;i++){

        maxDeadline = max(maxDeadline,jobs[i].deadline);

    }

    vector<char>slots(maxDeadline+1,'\0');
    vector<bool>flag(maxDeadline+1,false);

    int ans = 0;

    for(int i = 0;i<n;i++){
        for(int j = jobs[i].deadline;j>=1;j--){

            if(!flag[j]){

                flag[j]  = true;
                slots[j] = jobs[i].id;
                ans += jobs[i].profit;
                break;

            }
        }
    }

    cout<<"\nSelected Jobs : \n";
    for(int i = 1;i<=maxDeadline;i++){

        if(flag[i]){

            cout<<"Time slot : "<<i<<" -> Job "<<slots[i]<<"\n";

        }
    }

    cout<<"\nMaximum Profit : "<<ans<<"\n";

    return 0;

}

// O(n^2) time complexity