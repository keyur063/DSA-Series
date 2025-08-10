#include <iostream>
using namespace std;

int bitLength(int n){
    int cnt = 0;
    while(n != 0){
        n >>= 1;
        cnt++;
    }
    return cnt;
}

int minBitFlips(int n, int k){
    int Xor = n^k; //no of 1s == no of bit flips
    int cnt = 0;
    for(int i=0; i<bitLength(Xor); i++){
        if((Xor>>i) & 1 != 0){ // 1&1 != 0
            cnt++;
        }
    }
    return cnt;
}

int main(){
    // cout << bitLength(13) << endl;
    cout << minBitFlips(10, 7) << endl;
}