#include<iostream>
#include<vector>
using namespace std;
struct Pair{

    int mini;
    int maxi;

};

Pair MinMax(vector<int> &v,int low,int high){

    Pair res;

    if(low == high){

        res.mini = v[low];
        res.maxi = v[low];

        return res;

    }

    else if(low+1 == high){

        if(v[low]<v[high]){

            res.mini = v[low];
            res.maxi = v[high];

        }

        else{

            res.mini = v[high];
            res.maxi = v[low];
            
        }

        return res;

    }

    else{

        int mid = low+(high-low)/2;
        Pair left = MinMax(v,low,mid);
        Pair right = MinMax(v,mid+1,high);

        res.mini = min(left.mini,right.mini);
        res.maxi = max(left.maxi,right.maxi);

        return res;

    }
    
}
int main()
{
    vector<int>v = {12,45,3,89,2,21,7,1};
    int n = v.size();
    

    Pair result = MinMax(v,0,n-1);

    cout<<result.mini<<" "<<result.maxi<<"\n";

    return 0;

}

//O(n) time complexity
//O(logn) space complexity due to recursion stack
