#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int solveRec(int n, vector<int>& heights, int k){
    if(n==0) return 0;
    int minSteps = INT_MAX;

    for(int j=1; j<=k; j++){
        int jump = INT_MAX;
        if(n>=j) jump = solveRec(n-j, heights, k) + abs(heights[n] - heights[n-j]);
        minSteps = min(minSteps, jump);
    }
    return minSteps;
}

int solveMem(int n, vector<int>& heights, vector<int>& dp, int k){
    if(n==0) return 0;
    int minSteps = INT_MAX;

    if(dp[n] != -1)
        return dp[n];
    
    for(int j=1; j<=k; j++){
        int jump = INT_MAX;
        if(n>=j) jump = solveMem(n-j, heights, dp, k) + abs(heights[n] - heights[n-j]);
        minSteps = min(minSteps, jump);
    }
    return dp[n] = minSteps;
}
//TC- O(N*k)
//SC- O(N) + O(N) rec + dp

int solveTab(int n, vector<int>& heights, int k){
    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++){
            int jump = INT_MAX;
            if(i>=j) jump = dp[i-j] + abs(heights[i] - heights[i-j]);
            minSteps = min(minSteps, jump);
        }
        dp[i] = minSteps;
    }
    return dp[n];
}
//TC- O(N*k)
//SC- O(N) dp

//Can be SO to O(k) with a sliding window but worst case is still O(N)

int main(){
    vector<int> heights = {30,10,60,70,30,10,60,50};
    vector<int> dp(8, -1);
    cout<<solveTab(7, heights, 3)<<endl;;
}