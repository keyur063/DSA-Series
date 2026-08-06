#include<iostream>
#include<unordered_map>
using namespace std;
using LL = long long;

/*
    Given an array A of N integers and two integers D and M, find total number
    of unordered pairs(i, j) such that:
        0 <= i < j < N
        (A[i] + A[j]) % D == 0
        |A[i] - A[j]| % M == 0

    1 <= N <= 1e5
    1 <= D, M <= 1e9
    -1e9 <= A[i] <= 1e9
*/

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int main() {
    int N, D, M;
    cin >> N >> D >> M;

    int A[N] = {};
    for(int i=0; i<N; i++) 
        cin >> A[i];

    unordered_map<pair<int, int>, int, PairHash> m;
    LL ans = 0;

    for(int i=0; i<N; i++) {
        int remD = ((A[i] % D) + D) % D;
        int remM = ((A[i] % M) + M) % M;
        int needD = (D - remD) % D;

        ans += m[{remM, needD}]; 
        m[{remM, remD}]++;
    }

    cout << ans;

    return 0;
}