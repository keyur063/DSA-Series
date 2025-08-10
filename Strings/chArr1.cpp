#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[] = {'a', 'b', 'c', '\0'}; //null character takes 1 byte, used to end string
    char str1[] = {'a', 'b', 'c'};
    char str2[] =  "hello";

    cout << str1 << endl; //prints garbage values until null character is encountered
    cout << str << endl;

    cout << strlen(str1) << endl;
    cout << strlen(str) << endl;

    cout << str2[2] << endl;
    cout << str2[5] << endl; //points to null char

    return 0;
}