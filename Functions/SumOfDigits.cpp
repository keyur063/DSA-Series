#include <iostream>
using namespace std;

int sumOfDigits(int num){
    int sum = 0;
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(){
    cout<< sumOfDigits(1256)<< endl;
    cout<< sumOfDigits(123)<< endl;
    return 0;
}