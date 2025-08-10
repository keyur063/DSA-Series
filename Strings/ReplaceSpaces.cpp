#include <iostream>
using namespace std;

string replaceSpaces(string s){
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            s.replace(i, 1, "@40");
            i += 2;
        }
    }
    return s;
}

int main(){
    string str = "My name is xyz";

    cout << replaceSpaces(str) << endl;
    cout << str << endl;
    return 0;
}