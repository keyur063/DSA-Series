#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str = "hello world"; //dynamic => runtime resize
    cout << str << endl;

    // str = "hello"; //chArr cannot be modified once assigned
    // cout << str << endl;

    // Operators like +,==,<,> can be used (lexicographic order for <,>)

    string str1;

    // cout << "Enter string: ";
    // getline(cin, str1);

    // cout << str1 << endl;
    // cout << str1.length() << endl;

    for(char ch: str){ //i < str.length()
        cout << ch << " ";
    }
    cout << endl;

    reverse(str.begin(), str.end());
    cout << str << endl;

    return 0;
}