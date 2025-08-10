#include <iostream>
using namespace std;

int& func(int a){ //bad practice as scope is not defined outside function
    int num = a;
    int& ans = a;
    return ans;
}

int main() {
    int i = 5;
    int& j = i; // ref variable

    cout << i << endl; //5
    i++;
    cout << i << endl; //6
    j++;
    cout << i << endl; //7
    cout << j << endl; //7

    return 0;
}