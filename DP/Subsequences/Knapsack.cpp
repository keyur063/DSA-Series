#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int mem(int i, int cap, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
    if(i==0)
        return (cap >= wt[0]) ? val[0] : 0;

    if(dp[i][cap] != -1)
        return dp[i][cap];
    
    int excl = 0 + mem(i-1, cap, wt, val, dp);
    int incl = INT_MIN;
    if(cap >= wt[i]) incl = val[i] + mem(i-1, cap-wt[i], wt, val, dp);

    return dp[i][cap] = max(incl, excl);
}
//2^n -> n^2
// n -> n + n^2

int tab(int& n, int& cap, vector<int>& wt, vector<int>& val){
    vector<vector<int>> dp(n, vector<int> (cap+1, 0));
    for(int i=wt[0]; i<=cap; i++) dp[0][i] = val[0];

    for(int i=1; i<n; i++){
        for(int j=0; j<=cap; j++){
            int excl = 0 + dp[i-1][j];

            int incl = INT_MIN;
            if(j >= wt[i]) incl = val[i] + dp[i-1][j-wt[i]];

            dp[i][j] = max(incl, excl);
        }
    }
    return dp[n-1][cap];
}
//n^2, n^2

int space(int& n, int& cap, vector<int>& wt, vector<int>& val){
    vector<int> prev(cap+1, 0);
    vector<int> curr(cap+1, 0);
    for(int i=wt[0]; i<=cap; i++) prev[i] = val[0];

    for(int i=1; i<n; i++){
        for(int j=0; j<=cap; j++){
            int excl = 0 + prev[j];

            int incl = INT_MIN;
            if(j >= wt[i]) incl = val[i] + prev[j-wt[i]];

            curr[j] = max(incl, excl);
        }
        prev = curr;
    }
    return prev[cap];
}
//n^2, n

int space2(int& n, int& cap, vector<int>& wt, vector<int>& val){
    vector<int> prev(cap+1, 0);
    for(int i=wt[0]; i<=cap; i++) prev[i] = val[0];

    for(int i=1; i<n; i++){
        for(int j=cap; j>=0; j--){ //reverse loop so index is not updated
            int excl = 0 + prev[j];

            int incl = INT_MIN;
            if(j >= wt[i]) incl = val[i] + prev[j-wt[i]];

            prev[j] = max(incl, excl);
        }
    }
    return prev[cap];
}

int main(){
    vector<int> wt = {3,2,4};
    vector<int> val = {30,40,20};
    int n = wt.size();
    int cap = 6;

    vector<vector<int>> dp(n, vector<int> (cap+1, -1));
    cout<<space2(n, cap, wt, val)<<endl;
}