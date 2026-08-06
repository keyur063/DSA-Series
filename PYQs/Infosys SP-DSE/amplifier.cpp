#include<bits/stdc++.h>
using namespace std;

/*
    The positions of N posts are given in a sorted array posts. There are 2 types:
        Normal Amplifier: unlimited, range: [x-r, x+r]
        Super Amplifier: K, range: [x-2r, x+2r]
    Find minimum number of amplifiers.
*/

int solve(int i, int n, int k, vector<int>& normalNext, vector<int>& superNext, vector<vector<int>>& dp) {
    if(i == n) return 0;
    if(dp[i][k] != -1) return dp[i][k];

    int pickNormal = solve(normalNext[i], n, k, normalNext, superNext, dp);
    int ans = 1 + pickNormal;

    if(k > 0) {      
        int pickSuper = solve(superNext[i], n, k-1, normalNext, superNext, dp);
        ans = min(ans, 1 + pickSuper);
    }

    return dp[i][k] = ans;
}

int minAmplifiers(vector<int>& posts, int r, int k) {
    int n = posts.size();
    vector<int> normalNext(n), superNext(n);

    for(int i=0; i<n; i++) {
        normalNext[i] = upper_bound(posts.begin(), posts.end(), posts[i] + 2*r) - posts.begin();
        superNext[i] = upper_bound(posts.begin(), posts.end(), posts[i] + 4*r) - posts.begin();
    }

    vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
    return solve(0, n, k, normalNext, superNext, dp);
}

int main() {
    int N, R, K;
    cin >> N >> R >> K;

    vector<int> posts(N);
    for(int i=0; i<N; i++)
        cin >> posts[i];

    cout << minAmplifiers(posts, R, K);

    return 0;
}