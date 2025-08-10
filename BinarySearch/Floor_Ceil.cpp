#include<iostream>
#include<vector>
using namespace std;

int floorVal(vector<int> arr, int target){ //smallest arr[i] >= k
    int n = arr.size();
    int low=0, high=n-1, ans=n;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        } else
            low = mid+1;
    }
    return ans;
}

int ceilVal(vector<int> arr, int target){ //largest arr[i] <= k
    int n = arr.size();
    int low=0, high=n-1, ans=-1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] <= target){
            ans = mid;
            low = mid+1;
        } else
            high = mid-1;
    }
    return ans;
}

int main(){
    vector<int> arr = {10,20,20,30,30,40,50};

    cout << floorVal(arr, 25) << endl;
    cout << ceilVal(arr, 25) << endl;
}