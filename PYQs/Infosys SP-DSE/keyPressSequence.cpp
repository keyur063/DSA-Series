#include<bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    In a traditional mobile keypad, a user records only sequence of key presses 
    instead of intended message. Find number of different messages that could be 
    produced from a string of digits 2-9.

    2,3,4,5,6,8 -> 3 letters
    7,9 -> 4 letters
*/

const int MOD = 1e9 + 7;
string s;

LL solve(int i, vector<LL>& dp) {
    if(i == s.length()) return 1;

    if(dp[i] != -1) return dp[i];

    LL ways = 0;
    char digit = s[i];
    int sz = (digit == '7' || digit == '9') ? 4 : 3;

    for(int len=1; len<=sz; len++) {
        if(i + len > s.length()) break;

        bool same = true;

        for(int j=i; j<i+len; j++) {
            if(s[j] != digit) {
                same = false;
                break;
            }
        }

        if(!same) break;

        ways = (ways + solve(i + len, dp)) % MOD;
    }

    return dp[i] = ways;
}

int main() {
    cin >> s;

    vector<LL> dp(s.length(), -1);
    cout << solve(0, dp) << endl;
    for(int val: dp) cout << val << " ";

    return 0;
}