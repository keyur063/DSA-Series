#include <iostream>
using namespace std;

int decToBin(int decNum){
    int ans=0, pow=1;
    while(decNum>0){
        ans += (decNum%2)*pow;
        pow *= 10;
        decNum /= 2;
    }
    return ans;
}

int main(){
    cout<< decToBin(20);
    return 0;
}