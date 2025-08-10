#include <iostream>
using namespace std;

int method1(int n){
    int Xor = 0;
    for(int i=1; i<=n; i++){
        Xor ^= i;
    }
    return Xor;
}

int XORinRange(int n){
    if(n%4 == 1) return 1;
    if(n%4 == 2) return n+1;
    if(n%4 == 3) return 0;
    else return n;
}

int XORin2Range(int st, int end){
    return XORinRange(st-1) ^ XORinRange(end);
}

int main(){
    cout << method1(8) << endl;
    cout << XORinRange(6) << endl;

    cout << XORin2Range(4, 7) <<endl;
}