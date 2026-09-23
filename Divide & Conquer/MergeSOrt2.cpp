#include<iostream>
#include<vector>
using namespace std;
void Merge(int arr[],int low,int mid,int high){

    int temp[high-low+1];
    int i = low;
    int j = mid+1;

    int k = 0;

    while(i<=mid && j<=high){

        if(arr[i]<=arr[j]){

            temp[k++] = arr[i++];
        }

        else{

            temp[k++] = arr[j++];

        }
    }

    while(i<=mid){

        temp[k++] = arr[i++];

    }

     while(j<=high){

        temp[k++] = arr[j++];
        
    }

    for(int p = 0;p<k;p++){

        arr[p+low] = temp[p];
    
    }
}
void MergeSort(int arr[],int low,int high){

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
    cin>>n;

    int arr[n];

    for(int i = 0;i<n;i++){

        cin>>arr[i];

    }

    MergeSort(arr,0,n-1);

    cout<<"Sorted array is : \n";

    for(int x : arr){

        cout<<x<<" ";

    }

    return 0;
    
}
