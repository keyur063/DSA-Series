#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int> arr, int target){ //arr[i] >= k
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

int upperBound(vector<int> arr, int target){ //arr[i] > k
    int n = arr.size();
    int low=0, high=n-1, ans=n;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid-1;
        } else
            low = mid+1;
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,3,4,5,6,7,8,8,9,10};

    cout << lowerBound(arr, 2) << endl;
    cout << upperBound(arr, 9) << endl;
}