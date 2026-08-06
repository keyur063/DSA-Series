#include<bits/stdc++.h>
using namespace std;

/*
    Given two binary strings, return its sum in binary format
    1010 + 1011 = (21)10 = 10101
*/

string addBinary(string& a, string& b) {
    string res = "";
    int i = a.length() - 1, j = b.length() - 1, cy = 0;

    while(i >= 0 || j >= 0 || cy) {
        int sum = cy;

        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';

        res += (sum % 2) + '0';
        cy = sum / 2;

    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << addBinary(a, b);

    return 0;
}