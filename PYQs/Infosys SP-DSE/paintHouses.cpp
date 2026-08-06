#include<iostream>
#include<vector>
using namespace std;
using LL = long long;

/*
    There are N houses such that each hpuse must be painted with one of available C colors.
    The cost of painting ith house with jth color is given by cost[i][j]. 
    Following conditions should be satisfied:
        1. Every house must be painted with exactly one color.
        2. No two adjacent houses should have same color.
        3. The total painting cost must not exceed given budget B.
    Determine total painting cost, if impossible to paint all houses within B, print -1.
*/

int main() {
    int N, C;
    LL B;
    cin >> N >> C >> B;

    vector<vector<LL>> cost(N, vector<LL> (C));
    for(int i=0; i<N; i++) {
        for(int j=0; j<C; j++) {
            cin >> cost[i][j];
        }
    }

    const LL INF = 1e8;
    vector<LL> prev(C, INF);

    for(int j=0; j<C; j++) 
        prev[j] = cost[0][j];

    for(int i=1; i<N; i++) {
        vector<LL> curr(C, INF);

        for(int color=0; color<C; color++) {
            for(int prevColor=0; prevColor<C; prevColor++) {
                if(prevColor == color) // same color
                    continue;

                curr[color] = min(curr[color], prev[prevColor] + cost[i][color]);
            }
            cout << curr[color] << " ";
        }
        cout << endl;
        prev = curr;
    }

    LL ans = INF;
    for(int j=0; j<C; j++)
        ans = min(ans, prev[j]);

    if(ans > B) cout << -1;
    else cout << ans;

    return 0;
}