#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

/*
    Andy can take only one continuous N-day vacation, days numbered from 1 to N.
    He has already M obligations such that ith obligation is scheduled at day D[i].
    He can cancel at most K obligations. Determine maximum number of consecutive vacation 
    days he can take after cancelling at most K obligations.
*/

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> D(M);
    for(int i=0; i<M; i++)
        cin >> D[i];

    sort(D.begin(), D.end());

    int left = 0, ans = 0;
    for(int right=0; right<M; right++) {
        while(right - left + 1 > K) left++;

        int prev = (left == 0) ? 0 : D[left-1];
        int next = (right == M-1) ? N+1 : D[right+1];

        ans = max(ans, next - prev - 1);
    }

    cout << ans << endl;

    return 0;
}
