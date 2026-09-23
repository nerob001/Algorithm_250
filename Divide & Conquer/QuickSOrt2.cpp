#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int partition(vector<int> &v,int low,int high,int pivotChoice){

    int pivotIdx;

    if(pivotChoice == 1){

        pivotIdx = low;
        
    }

    else if(pivotChoice == 2){

        pivotIdx = high;

    }

    else if(pivotChoice == 3){

        pivotIdx = (low+high)/2;

    }

    else{

        pivotIdx = low + rand() % (high - low + 1);

    }

    swap(v[pivotIdx],v[high]);

    int pivot = v[high];
    int idx = low-1;

    for(int j = low;j<=high-1;j++){

        if(v[j]<=pivot){

            idx++;
            swap(v[idx],v[j]);

        }
    }

    idx++;
    swap(v[idx],v[high]);

    return idx;

}

void QuickSort(vector<int> &v,int low,int high,int pivotChoice){

    if(low<high){

        int pivot = partition(v,low,high,pivotChoice);
        QuickSort(v,low,pivot-1,pivotChoice);
        QuickSort(v,pivot+1,high,pivotChoice);

    }

    return;

}
int main()
{
    int n,pivotChoice;
    cin>>n>>pivotChoice;

    vector<int>v(n);

    for(int i = 0;i<n;i++){

        cin>>v[i];

    }

    QuickSort(v,0,v.size()-1,pivotChoice);

    for(int x : v){

        cout<<x<<" ";

    }

    return 0;

}