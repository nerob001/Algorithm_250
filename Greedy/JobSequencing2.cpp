#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct Job{

    char id;
    int deadline;
    int profit;

};

bool compare(Job a,Job b){

    return a.deadline<b.deadline;

}

struct Compare{

    bool operator()(Job a,Job b){

        return a.profit>b.profit;

    }
};

int main()
{

    int n;
    cout<<"Enter nummber of Jobs : \n";
    cin>>n;

    vector<Job>jobs(n);

    for(int i = 0;i<n;i++){

        cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;

    }

    sort(jobs.begin(),jobs.end(),compare);

    priority_queue<Job,vector<Job>,Compare>pq;

    for(int i = 0;i<n;i++){

        pq.push(jobs[i]);

        if(pq.size()>jobs[i].deadline){

            pq.pop();

        }
    }

    int ans = 0;

    while(!pq.empty()){

        Job job = pq.top();
        pq.pop();

        cout<<job.id<<" ";
        ans += job.profit;

    }

    cout<<"Total Profit : "<<ans<<"\n";

    return 0;
    

}
