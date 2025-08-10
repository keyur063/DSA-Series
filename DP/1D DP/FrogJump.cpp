#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int solveRec(int n, vector<int>& heights){
    if(n==0) return 0;
    int opt1 = solveRec(n-1, heights) + abs(heights[n] - heights[n-1]);
    int opt2 = INT_MAX;
    if(n>1) opt2 = solveRec(n-2, heights) + abs(heights[n] - heights[n-2]);
    return min(opt1, opt2);
}

int solveMem(int n, vector<int>& heights, vector<int>& dp){
    if(n==0) return 0;
    if(dp[n] != -1)
        return dp[n];
    
    int opt1 = solveMem(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int opt2 = INT_MAX;
    if(n>1) opt2 = solveMem(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
    return dp[n] =  min(opt1, opt2);
}

int solveTab(int n, vector<int>& heights){
    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        int opt1 = dp[i-1] + abs(heights[i] - heights[i-1]);
        int opt2 = INT_MAX;
        if(i>1) opt2 = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(opt1, opt2);
    }
    return dp[n];
}

int solveSO(int n, vector<int>& heights){
    int prev1 = 0;
    int prev2 = 0;
    for(int i=1; i<=n; i++){
        int opt1 = prev1 + abs(heights[i] - heights[i-1]);
        int opt2 = INT_MAX;
        if(i>1) opt2 = prev2 + abs(heights[i] - heights[i-2]);
        int curr = min(opt1, opt2);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    vector<int> heights = {30,10,60,10,60,50};
    vector<int> dp(6, -1);
    cout<<solveTab(5, heights)<<endl;;
}