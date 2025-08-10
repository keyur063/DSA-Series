#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int mem(int i, int n, vector<int>& nums, int sum, vector<vector<int>>& dp){
    if(sum==0) return 1;
    if(i==0) return (nums[0] == sum);

    if(dp[i][sum] != -1)
        return dp[i][sum];

    int incl = 0;
    if(sum >= nums[i]) incl += mem(i-1, n, nums, sum-nums[i], dp);
    int excl = mem(i-1, n, nums, sum, dp);

    return dp[i][sum] = incl + excl;
}
//O(2^n) -> O(n x sum)
//O(n) -> O(n) + O(n x sum)

int tab(int n, vector<int>& nums, int sum){
    vector<vector<int>> dp(n, vector<int> (sum+1, 0));
    for(int i=0; i<n; i++) dp[i][0] = 1;
    if(nums[0] <= sum) dp[0][nums[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            int incl = 0;

            if(j >= nums[i]) incl += dp[i-1][j-nums[i]];
            int excl = dp[i-1][j];

            dp[i][j] = incl + excl;
        }
    }
    return dp[n-1][sum];
}
//O(n x sum)
//O(n x sum)

int space(int n, vector<int>& nums, int sum){
    vector<int> prev(sum+1, 0);
    vector<int> curr(sum+1, 0);
    prev[0] = curr[0] = 1;
    if(nums[0] <= sum) prev[nums[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            int incl = 0;

            if(j >= nums[i]) incl += prev[j-nums[i]];
            int excl = prev[j];

            curr[j] = incl + excl;
        }
        prev = curr;
    }
    return prev[sum];
}
//O(n x sum)
//O(sum)

int memSpecialCase(int i, int n, vector<int>& nums, int sum, vector<vector<int>>& dp1){ //for leading zeros
    if(i==0){
        if(sum==0 && nums[0]==0) return 2; //incl & excl both
        if(sum==0 || sum==nums[0]) return 1; //either excl or incl
        return 0;
    }

    if(dp1[i][sum] != -1)
        return dp1[i][sum];

    int incl = 0;
    if(sum >= nums[i]) incl += memSpecialCase(i-1, n, nums, sum-nums[i], dp1);
    int excl = memSpecialCase(i-1, n, nums, sum, dp1);

    return dp1[i][sum] = incl + excl;
}

int main(){
    vector<int> nums = {1,2,2,3}; //12 12 3 -> 3
    int n = nums.size();
    int sum = 3;

    vector<vector<int>> dp(n, vector<int> (sum+1, -1));
    cout<<space(n, nums, sum)<<endl;

    vector<int> arr = {0,0,1}; //4 (1 for normal case)
    vector<vector<int>> dp1(3, vector<int> (2, -1));
    cout<<memSpecialCase(2, 3, arr, 1, dp1)<<endl;
}