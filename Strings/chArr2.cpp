#include <iostream>
using namespace std;

int main(){
    char str[] = "hello world";
    int len = 0;

    // cout << "Enter string: ";
    // cin.getline(str, 13, '$'); //cin stores until space is encountered

    // cout << str << endl;

    for(char ch: str){
        cout << ch << " ";
    }
    cout << endl;

    for(int i=0; str[i] != '\0'; i++){
        len++;
    }

    cout << "Length of string: " << len << endl;

    return 0;
}