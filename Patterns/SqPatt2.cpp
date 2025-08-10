/*for n=3
123
456
789*/
#include <iostream>
using namespace std;

void sqPatt(int n){
    int num = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n-1; j++){
            cout <<num<<" ";
            num ++;
        }
        cout<<endl;
    }
}

void sqPattChar(int n){
    char ch = 'A';
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n-1; j++){
            cout <<ch<<" ";
            ch ++;
        }
        cout<<endl;
    }
}

int main(){
    sqPatt(3);
    cout<<endl;
    sqPatt(4);
    cout<<endl;
    sqPattChar(3);
    return 0;
}