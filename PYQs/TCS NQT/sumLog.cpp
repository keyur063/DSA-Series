#include<bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Given L and R, return sum of floor of its binary logarithm.
*/

int main() {
    LL L, R, sum = 0;
    cin >> L >> R;

    for(LL i=L; i<=R; i++)
        sum += __lg(i);
    
    cout << sum;

    return 0;
}