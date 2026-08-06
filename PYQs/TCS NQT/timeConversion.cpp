#include<iostream>
#include<string>
using namespace std;

/*
    TCS NQT July 7th    
    Given a time in 12 hour format, convert t to 24 hour format
*/

string timeConversion(string s) {
    int hour = stoi(s.substr(0, 2));

    if(s[8] == 'A') { // AM
        hour %= 12;
    } else { // PM
        if(hour != 12) hour += 12;
    }

    string hr;
    if(hour < 10) hr = "0" + to_string(hour);
    else hr = to_string(hour);

    return hr + s.substr(2, 6);
}

int main() {
    string s;
    cin >> s;
    cout << timeConversion(s);

    return 0;
}