#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>&arr,int low,int mid,int high){

    vector<int>temp;
    int i = low;
    int j = mid+1;

    while(i<=mid && j<=high){

        if(arr[i]<=arr[j]){

            temp.push_back(arr[i]);
            i++;

        }

         else{

            temp.push_back(arr[j]);
            j++;
            
        }
    }

    while(i<=mid){

        temp.push_back(arr[i]);
        i++;

    }

    while(j<=high){

        temp.push_back(arr[j]);
        j++;

    }

    for(int k = 0;k<temp.size();k++){

        arr[k+low] = temp[k];

    }

    return;

}
void MergeSort(vector<int>&arr,int low,int high){

    if(low<high){

        int mid = low+(high-low)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);

        return;

    }
}
int main()
{
    int n;
    cout<<"Enter array size : ";
    cin>>n;

    vector<int>arr(n);

    for(int i = 0;i<n;i++){

        cin>>arr[i];

    }

    MergeSort(arr,0,n-1);
    cout<<"Sorted array : \n";

    for(int x : arr){

        cout<<x<<" ";

    }

    return 0;

}