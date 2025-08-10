#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<char>& s, int left, int right){
    while (left < right) {
        swap(s[left++], s[right--]);
    }
}

int main(){
    cout << "Enter a sentence: ";
    string input;
    getline(cin, input);

    vector<char> s(input.begin(), input.end());

    int left=0;
    for(int i=0; i<=s.size(); i++){
        if(s[i] == ' ' || i==s.size()){
            reverse(s, left, i-1);
            left = i+1;
        }
    }
    reverse(s, 0, s.size()-1);
    
    for(char ch: s){
        cout << ch << " ";
    }
    return 0;
}