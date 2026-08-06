#include<iostream>
using namespace std;

string encode(string& s) {
    for(char ch: s) {
        if(ch == ' ') return "Error";
    }

    for(int i=0; i<s.length(); i++) {
        if(i & 1) {
            if(s[i] == 'A') s[i] = 'Z';
            else if(s[i] == 'a') s[i] = 'z';
            else if(s[i] == '0') s[i] = '9';
            else s[i] = s[i] - 1;
        } else {
            if(s[i] == 'Z') s[i] = 'B';
            else if(s[i] == 'z') s[i] = 'b';
            else if(s[i] == '8') s[i] = '0';
            else if(s[i] == '9') s[i] = '1';
            else s[i] = s[i] + 2;
        }
    }

    return s;
}

int main() {
    string s;
    cin >> s;
    cout << encode(s);
    return 0;
}