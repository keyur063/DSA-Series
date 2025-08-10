#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int mem(int i, int cap, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
    if(i==0)
        return (cap/wt[0])*val[0];

    if(dp[i][cap] != -1)
        return dp[i][cap];

    int excl = mem(i-1, cap, wt, val, dp);
    int incl = INT_MIN;
    if(cap >= wt[i]) incl = val[i] + mem(i, cap-wt[i], wt, val, dp);

    return dp[i][cap] = max(incl, excl);
}

int tab(int n, int cap, vector<int>& wt, vector<int>& val){
    vector<vector<int>> dp(n, vector<int> (cap+1, 0));

    for(int i=0; i<=cap; i++) dp[0][i] = (i/wt[0])*val[0];

    for(int i=1; i<n; i++){
        for(int j=0; j<=cap; j++){
            int excl = dp[i-1][j];

            int incl = INT_MIN;
            if(j >= wt[i]) incl = val[i] + dp[i][j-wt[i]];

            dp[i][j] = max(incl, excl);
        }
    }
    return dp[n-1][cap];
}

int space(int n, int cap, vector<int>& wt, vector<int>& val){
    vector<int> prev(cap+1, -1);

    for(int i=0; i<=cap; i++) prev[i] = (i/wt[0])*val[0];

    for(int i=1; i<n; i++){
        for(int j=0; j<=cap; j++){
            int excl = prev[j];

            int incl = INT_MIN;
            if(j >= wt[i]) incl = val[i] + prev[j-wt[i]];

            prev[j] = max(incl, excl);
        }
    }
    return prev[cap];
}

int main(){
    vector<int> wt = {2,4,6};
    vector<int> val = {5,13,11};
    int n = wt.size();
    int cap = 10;

    vector<vector<int>> dp(n, vector<int> (cap+1, -1));
    cout<<space(n, cap, wt, val)<<endl;
}