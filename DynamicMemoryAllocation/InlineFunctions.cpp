#include <iostream>
using namespace std;

inline int getMax(int& a, int& b){
    return (a>b) ? a: b;
}

// No extra memory
// No function call overhead

int main(){
    int a = 1, b = 2;

    int ans = getMax(a, b);
    cout << ans << endl;

    a = a+3;
    b = b+1;

    ans = getMax(a, b);
    cout << ans << endl;

    return 0;
}