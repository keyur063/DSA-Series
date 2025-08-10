#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int mem(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
    if(i==j) return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;
    for(int k=i; k<j; k++){
        int steps = nums[i-1] * nums[k] * nums[j] + mem(i, k, nums, dp) + mem(k+1, j, nums, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}
//TC ~ O(2^n) ~> O(n^2 x n)
//SC ~ O(n) ~> O(n^2) + O(n)

int tab(int n, vector<int>& nums){
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int i=n-1; i>0; i--){
        for(int j=i+1; j<n; j++){
            int mini = 1e9;
            for(int k=i; k<j; k++){
                int steps = nums[i-1] * nums[k] * nums[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}
//TC ~ O(n^3)
//SC ~ O(n^2)

int main(){
    vector<int> nums = {10,20,30,40,50};
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int> (n, -1));
    // cout<<mem(1, n-1, nums, dp)<<endl;
    cout<<tab(n, nums)<<endl;
}