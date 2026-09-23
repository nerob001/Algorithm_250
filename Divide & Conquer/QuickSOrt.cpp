#include<iostream>
#include<vector>
using namespace std;
int Partition(vector<int> &v,int low,int high){

    int pivotIdx = low;
    swap(v[pivotIdx],v[high]);

    int idx = low-1;
    int pivot = v[high];

    for(int j = low;j<=high-1;j++){

        if(v[j]<=pivot){

            idx++;
            swap(v[j],v[idx]);

        }
    }

    idx++;
    swap(v[idx],v[high]);

    return idx;

}
void QuickSort(vector<int> &v,int low,int high){

    if(low<high){

        int pivotIdx = Partition(v,low,high);
        QuickSort(v,low,pivotIdx-1);
        QuickSort(v,pivotIdx+1,high);

        return;

    }
}
int main()
{
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i = 0;i<n;i++){

        cin>>v[i];

    }

    QuickSort(v,0,n-1);

    cout<<"Sorted array : \n";
    for(int x : v){

        cout<<x<<" ";

    }

    return 0;

}
