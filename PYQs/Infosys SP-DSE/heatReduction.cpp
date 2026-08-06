#include<bits/stdc++.h>
using namespace std;
using LL = long long; 

/*

*/

LL processQuery(vector<int>& heat, int l, int r, int k, int d, int critical) {
    vector<pair<int, int>> arr;

    for(int i=l; i<=r; i++) {
        int val = heat[i];
        if(val >= critical) val *= 4;
        arr.push_back({val, i});
    }

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    LL total = 0;
    vector<int> selected;

    for(auto& it: arr) {
        int val = it.first;
        int idx = it.second;
        bool valid = true;

        for(int prev: selected) {
            if(abs(prev - idx) < d) {
                valid = false;
                break;
            }

            if(valid) {
                if(selected.size() <= k) {
                    total += val;
                    selected.push_back(idx);
                }
            }
        }
    }

    return total;
}

int main() {
    int n, d, q;
    cin >> n >> d >> q;

    vector<int> heat(n);
    for(int i=0; i<n; i++)
        cin >> heat[i];

    LL ans = 0;

    while(q--) {
        int type;
        cin >> type;

        // update query
        if(type == 1) {
            int pos, value;
            cin >> pos >> value;

            heat[pos] = value;
        } else { // normal query
            int l, r, k, critical;
            cin >> l >> r >> k >> critical;

            ans += processQuery(heat, l, r, k, d, critical);
        }
    }

    cout << ans;

    return 0;
}