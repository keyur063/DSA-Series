#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
using LL = long long;

/*
    Given a binary string S, find minimum adjacent swaps required to make all
    identical characters appear together in one contiguous block.
    Either group all '1's together or all '0's and return minimum between both.

    1001 -> '0's together -> 0 swaps
    1001 -> 0101 -> 0110 -> 2 swaps -> min(0, 2) = 0
*/

LL solve(string& S, char ch) {
    vector<int> pos, targetPos;

    for(int i=0; i<S.size(); i++) {
        if(S[i] == ch) 
            pos.push_back(i);
    }

    int n = pos.size();
    if(n <= 1) return 0; // already grouped

    for(int i=0; i<n; i++)
        targetPos.push_back(pos[i] - i);

    int median = targetPos[n / 2];
    LL swaps = 0;

    for(int x: targetPos) 
        swaps += abs(x - median);
    
    return swaps;
}

int main() {
    string S;
    cin >> S;

    cout << min(solve(S, '1'), solve(S, '0'));

    return 0;
}