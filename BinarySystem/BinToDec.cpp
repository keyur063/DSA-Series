#include <iostream>
using namespace std;

int binToDec(int binNum){
    int ans=0, pow=1;
    while(binNum>0){
        ans += (binNum%10)*pow;
        pow *= 2;
        binNum /= 10;
    }
    return ans;
}

int main(){
    cout<< binToDec(10101);
    return 0;
}