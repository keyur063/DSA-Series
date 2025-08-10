#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int mod = (int)(1e9 + 7);

/*
Count partitions into 2 arrays such that s1 >= s2 and |s1 - s2| = diff
|s1 - s2| = diff
|sum-s2-s2| = diff
s2 = |sum - diff| / 2 -> always integer so sum-diff always even & +ve
revised target from previous Qn 
*/

int mem(int i, int n, vector<int>& nums, int sum, vector<vector<int>>& dp){ 
    if(i==0){
        if(sum==0 && nums[0]==0) return 2; //incl & excl both
        if(sum==0 || sum==nums[0]) return 1; //either excl or incl
        return 0;
    }

    if(dp[i][sum] != -1)
        return dp[i][sum];

    int incl = 0;
    if(sum >= nums[i]) incl += mem(i-1, n, nums, sum-nums[i], dp);
    int excl = mem(i-1, n, nums, sum, dp);

    return dp[i][sum] = (incl + excl) % mod;
}

int tab(int n, vector<int>& nums, int sum){
    vector<vector<int>> dp(n, vector<int> (sum+1, 0));

    if(nums[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(nums[0] != 0 && nums[0] <= sum) dp[0][nums[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            int incl = 0;

            if(j >= nums[i]) incl += dp[i-1][j-nums[i]];
            int excl = dp[i-1][j];

            dp[i][j] = (incl + excl) % mod;
        }
    }
    return dp[n-1][sum];
}

int space(int n, vector<int>& nums, int sum){
    vector<int> prev(sum+1, 0);
    vector<int> curr(sum+1, 0);

    if(nums[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if(nums[0] != 0 && nums[0] <= sum) prev[nums[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            int incl = 0;

            if(j >= nums[i]) incl += prev[j-nums[i]];
            int excl = prev[j];

            curr[j] = (incl + excl) % mod;
        }
        prev = curr;
    }
    return prev[sum];
}

int main(){
    vector<int> nums = {5,2,6,4};
    int n = nums.size();
    int diff = 3;

    int sum = 0;
    for(int num: nums) sum += num;

    if((diff > sum) || ((sum-diff) & 1)) return 0;

    int target = (sum-diff) / 2;
    vector<vector<int>> dp(n, vector<int> (sum+1, -1));
    cout<<space(n, nums, target)<<endl;
}