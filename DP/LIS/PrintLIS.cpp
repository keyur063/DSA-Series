#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){
    vector<int> nums = {5,4,11,1,16,8};
    int n = nums.size();

    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIdx = 0;

    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int prev=0; prev<i; prev++){
            if(nums[i] > nums[prev] && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }

        if(dp[i] > maxi){
            maxi = dp[i];
            lastIdx = i; //update max len index
        }
    }

    vector<int> ans(maxi);
    ans[0] = nums[lastIdx];
    int idx = 1;
    while(hash[lastIdx] != lastIdx){
        lastIdx = hash[lastIdx]; //update max len index
        ans[idx++] = nums[lastIdx]; //insert element 
    }

    for(int i=maxi-1; i>=0; i--)
        cout<<ans[i]<<" ";
    
}