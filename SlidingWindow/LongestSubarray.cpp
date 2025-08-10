#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& arr, int k){
    int l=0, r=0, sum=0, maxLen=0;
    int n = arr.size();

    while(r < n){
        sum += arr[r];
        while(sum > k){
            sum -= arr[r];
            l++;
        }

        if(sum <= k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}

int optimalSoln(vector<int>& arr, int k){
    int l=0, r=0, sum=0, maxLen=0;
    int n = arr.size();

    while(r < n){
        sum += arr[r];
        if(sum > k){ //no contraction
            sum -= arr[r];
            l++;
        }

        if(sum <= k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}

int main(){
    vector<int> arr = {2,5,1,7,10,10};
    int maxSum = 14;

    cout << longestSubarray(arr, maxSum) << endl; //[2 5 1] = 3
    cout << optimalSoln(arr, maxSum) << endl; 
}