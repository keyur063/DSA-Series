#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

using ll = long long;
int mod = 1e9 + 7;

ll mem(int i, int j, int isTrue, string& exp, vector<vector<vector<ll>>>& dp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }

    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    ll ways = 0;
    for(int k=i+1; k<j; k++){
        ll lT = mem(i, k-1, 1, exp, dp); //left partition is true
        ll lF = mem(i, k-1, 0, exp, dp);
        ll rT = mem(k+1, j, 1, exp, dp);
        ll rF = mem(k+1, j, 0, exp, dp);

        if(exp[k] == '&'){
            if(isTrue) ways = (ways + (lT*rT) % mod) % mod;
            else ways = (ways + (lF*rT) % mod + (lF*rF) % mod + (lT*rF) % mod) % mod;
        } else if(exp[k] == '|'){
            if(isTrue) ways = (ways + (lF*rT) % mod + (lT*rT) % mod + (lT*rF) % mod) % mod;
            else ways = (ways + (lF*rF) % mod) % mod;
        } else{
            if(isTrue) ways = (ways + (lT*rF) % mod + (lF*rT) % mod) % mod;
            else ways = (ways + (lT*rT) % mod + (lF*rF) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int tab(string& exp){
    int s = exp.length();
    vector<vector<vector<int>>> dp(s+1, vector<vector<int>> (s+1, vector<int> (2, 0)));

    for(int i=0; i<s; i++){
        if(exp[i] == 'T') dp[i][i][1] = 1;
        if(exp[i] == 'F') dp[i][i][0] = 1;
    }

    for(int i=s-1; i>=0; i--){
        for(int j=0; j<s; j++){
            if(i==j) continue;
            for(int t=0; t<=1; t++){
                ll ways = 0;
                for(int k=i+1; k<j; k++){
                    ll lT = dp[i][k-1][1]; //left partition is true
                    ll lF = dp[i][k-1][0];
                    ll rT = dp[k+1][j][1];
                    ll rF = dp[k+1][j][0];

                    if(exp[k] == '&'){
                        if(t) ways = (ways + (lT*rT) % mod) % mod;
                        else ways = (ways + (lF*rT) % mod + (lF*rF) % mod + (lT*rF) % mod) % mod;
                    } else if(exp[k] == '|'){
                        if(t) ways = (ways + (lF*rT) % mod + (lT*rT) % mod + (lT*rF) % mod) % mod;
                        else ways = (ways + (lF*rF) % mod) % mod;
                    } else{
                        if(t) ways = (ways + (lT*rF) % mod + (lF*rT) % mod) % mod;
                        else ways = (ways + (lT*rT) % mod + (lF*rF) % mod) % mod;
                    }
                }
                dp[i][j][t] = ways;
            }
        }
    }
    return dp[0][s-1][1];
}

int main(){
    string exp = "T^F|T&F^T|F";
    int s = exp.length();

    vector<vector<vector<ll>>> dp(s, vector<vector<ll>> (s, vector<ll> (2, -1)));
    //cout<<mem(0, s-1, 1, exp, dp)<<endl;
    cout<<tab(exp)<<endl;
}