#include<iostream>
#include<vector>
using namespace std;

/*
    Given a string S, return minimum number of palindromic substrings required to 
    partition the string such that:
        1. Each character belongs to only one substring
        2. Consider both even and odd-length substrings
*/

bool isPalindrome(string&s, int l, int r) {
    while(l <= r) {
        if(s[l++] != s[r--])
            return false;
    }
    return true;
}

int minPartitions(string& s, int i, vector<int>& dp) {
    int n = s.length();
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int minCost = 1e9;
    for(int j=i; j<n; j++) {
        if(isPalindrome(s, i, j)) {
            minCost = min(minCost, 1 + minPartitions(s, j+1, dp));
        }
    }

    return dp[i] = minCost;
}

int main() {
    string S;
    cin >> S;

    vector<int> dp(S.length(), -1);
    cout << minPartitions(S, 0, dp) << endl;
    for(int x: dp)
        cout << x << " ";

    return 0;
}