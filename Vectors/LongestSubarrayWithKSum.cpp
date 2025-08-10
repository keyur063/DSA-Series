#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int better(vector<int> arr, long long k){
    unordered_map<long long, int> prefixSum;
    long long sum = 0;
    int maxLen = 0;

    for(int i=0; i<arr.size(); ++i){
        sum += arr[i];

        if(sum == k) 
            maxLen = max(maxLen, i+1);

        if(prefixSum.find(sum-k) != prefixSum.end())
            maxLen = max(maxLen, i-prefixSum[sum-k]);
        
        //check for zeros [2 0 0 3]
        if(prefixSum.find(sum) == prefixSum.end()) 
            prefixSum[sum] = i;
    }
    return maxLen;
}
//O(N), O(N)

//2-pointer: only for zero & positive
int optimal(vector<int> arr, long long k){
    int l=0, r=0, maxLen=0;
    int n = arr.size();
    long long sum = arr[0];

    while(r < n){
        while(l<=r && sum>k){
            sum -= arr[l];
            l++;
        }

        if(sum == k) 
            maxLen = max(maxLen, r-l+1);

        r++;
        if(r<n) sum += arr[r];
    }
    return maxLen;
}
//O(2N), O(1)

int main(){
    vector<int> arr = {1,2,3,1,1,1,4,2,3};
    long long k = 3;
    cout<<optimal(arr, k)<<endl;
}