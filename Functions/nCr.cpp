#include <iostream>
using namespace std;

int fact(int n){
    int fact = 1;
    for(int i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}

int nCr(int n, int r){
    if(r>n-r) r = n-r;
    return fact(n)/(fact(r)*fact(n-r));
}

int main(){
    cout<<nCr(12, 3)<<endl;
    cout<<nCr(10, 6)<<endl;
    return 0;
}