#include<iostream>
#include<climits>
using namespace std;
using LL = long long;

/*
    There are N passengers who need to travel.
        1. A car carries 4 passengers at X units of pollution.
        2. A van carries 100 passengers at Y units of pollution.
    Transport atleast N passengers at total minumum pollution.
*/

int main() {
    int T;
    cin >> T;

    while(T--) {
        LL N, X, Y;
        cin >> N >> X >> Y;

        LL ans = LLONG_MAX;

        LL maxVans = (N + 99) / 100;
        for(LL vans=0; vans<=maxVans; vans++) {
            LL pax = vans * 100;
            LL rem = max(0LL, N - pax);
            LL cars = (rem + 3) / 4;
            LL pollution = cars * X + vans * Y;
            ans = min(ans, pollution);
        }

        cout << ans << " ";
    }
    
    return 0;
}
