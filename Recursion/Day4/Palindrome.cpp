#include <iostream>
using namespace std;

bool isPalindrome(string s, int st){
    int end = s.length()-1-st;

    if(st > end) return true;

    if(s[st] != s[end]){
        return false;
    } else{
        return isPalindrome(s, st+1);
    }
}

int main(){
    string s = "abcda";

    if(isPalindrome(s, 0)){
        cout << "String is palindrome" << endl;
    } else{
        cout << "String is not palindrome" << endl;
    }
}