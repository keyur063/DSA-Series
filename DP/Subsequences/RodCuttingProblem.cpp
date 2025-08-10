#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int mem(int i, int len, vector<int>& cost, vector<vector<int>>& dp){
    if(i==0)
        return len*cost[0]; //rodLen=1

    if(dp[i][len] != -1)
        return dp[i][len];

    int excl = mem(i-1, len, cost, dp);

    int incl = INT_MIN;
    int rodLen = i+1;
    if(len > rodLen) incl = cost[i] + mem(i, len-rodLen, cost, dp);

    return dp[i][len] = max(excl, incl);
}

int tab(int n, int len, vector<int>& cost){
    vector<vector<int>> dp(n, vector<int> (len+1, 0));

    for(int i=0; i<=len; i++) dp[0][i] = i*cost[0];

    for(int i=1; i<n; i++){
        for(int j=0; j<=len; j++){
            int excl = dp[i-1][j];

            int incl = INT_MIN;
            int rodLen = i+1;
            if(j > rodLen) incl = cost[i] + dp[i][j-rodLen];

            dp[i][j] = max(incl, excl);
        }
    }
    return dp[n-1][len];
}

int space(int n, int len, vector<int>& cost){
    vector<int> prev(len+1, 0); //2 row also works

    for(int i=0; i<=len; i++) prev[i] = i*cost[0];

    for(int i=1; i<n; i++){
        for(int j=0; j<=len; j++){
            int excl = prev[j];

            int incl = INT_MIN;
            int rodLen = i+1;
            if(j > rodLen) incl = cost[i] + prev[j-rodLen];

            prev[j] = max(incl, excl);
        }
    }
    return prev[len];
}

int main(){
    vector<int> cost = {2,5,7,8,10}; //cost corresponding to length (index+1)
    int n = cost.size();
    int len = 10;

    vector<vector<int>> dp(n, vector<int> (len+1, -1));
    cout<<space(n, len, cost)<<endl;
}