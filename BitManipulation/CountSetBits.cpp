#include <iostream>
using namespace std;

int countSetBits(int n){
    int cnt = 0;
    while(n > 1){
        cnt += n&1;
        n >>= 1;
    }

    if(n==1) cnt++;
    return cnt;
}

int method2(int n){
    int cnt = 0;
    while(n != 0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

int main(){
    cout << countSetBits(16) << endl;
    cout << countSetBits(13) << endl;
    cout << method2(13) << endl;
}