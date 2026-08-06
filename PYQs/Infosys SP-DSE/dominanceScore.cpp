#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using LL = long long;

/*
    Given an array A of N integers, divide A into exactly K non-empty contiguous subarrays.
    The dominance score of a subarray is the maximum frequency of any element in that subarray.
    The score of a partition is the sum of dominance scores of all K subarrays.
    Find maximum possible score.
*/

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N+1);
    for(int i=1; i<=N; i++)
        cin >> A[i];

    vector<vector<int>> mode(N+1, vector<int> (N+1));
    for(int l=1; l<=N; l++) {
        unordered_map<int, int> freq;
        
        for(int r=l; r<=N; r++) {
            freq[A[r]]++;
            mode[l][r] = max(mode[l][r-1], freq[A[r]]);
        }
    }

    const LL NEG = -(1LL << 60);
    vector<vector<LL>> dp(N+1, vector<LL> (K+1, NEG));

    dp[0][0] = 0;
    
    for(int groups=1; groups<=K; groups++) {
        for(int i=1; i<=N; i++) {
            for(int j=groups-1; j<i; j++) {
                if(dp[j][groups-1] == NEG) continue;

                dp[i][groups] = max(dp[i][groups], dp[j][groups-1] + mode[j+1][i]);
            }
        }
    }

    cout << dp[N][K];

    return 0;
}