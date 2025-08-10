#include <iostream>
using namespace std;

// void reverse(string& s, int st, int end){
//     cout << "Call received for " << s << endl;

//     if(st > end) return;

//     swap(s[st], s[end]);
//     st++; end--;

//     reverse(s, st, end);
// }

void reverse(string& s, int st){
    cout << "Call received for " << s << endl;

    int end = s.length()-1-st;

    if(st > end) return;

    swap(s[st], s[end]);
    st++; end--;

    reverse(s, st);
}

int main(){
    string s = "abcde";

    // reverse(s, 0, s.length()-1);
    reverse(s, 0);
    cout << s << endl;
}