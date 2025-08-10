#include <iostream>
using namespace std;

/*For n=4
1111
 222
  33
   4
 */
void invTriPatt(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << " ";
        }
        for(int k = 1; k <= n-i; k++){
            cout<<i+1;
        }
        cout<<endl;
    }
}

void invTriPattChar(int n){
    char ch = 'A';
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << " ";
        }
        for(int k = 1; k <= n-i; k++){
            cout<<ch;
        }
        ch ++;
        cout<<endl;
    }
}

int main(){
    invTriPatt(5);
    cout<<endl;
    invTriPattChar(4);
    cout<<endl;
    return 0;
}