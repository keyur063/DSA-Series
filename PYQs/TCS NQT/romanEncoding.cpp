#include<iostream>
#include<vector>
using namespace std;

/*
    Given integer N, convert it into its Roman numeral representation.
*/

int main() {
    int N;
    cin >> N;

    string res = "";
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, 
        {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for(auto& p: roman) {
        while(N >= p.first) {
            res += p.second;
            N -= p.first;
        }
    }

    cout << res;

    return 0;
}