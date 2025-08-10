#include <iostream>
using namespace std;

int fibNum(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return fibNum(n-1) + fibNum(n-2);
}

int main(){
    cout<< fibNum(10)<< endl;
    cout<< fibNum(11)<< endl;
    return 0;
}