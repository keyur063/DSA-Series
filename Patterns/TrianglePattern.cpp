/*For n=3
*
* *
* * * 
*/
#include <iostream>
using namespace std;

void triPatt(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout << i+1<<" ";//use cout<<"* " to print stars
        }
        cout<<endl;
    }
}

void triPattChar(int n){
    char ch = 'A';
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout << ch<<" ";
        }
        ch ++;
        cout<<endl;
    }
}

int main(){
    triPatt(4);
    cout<<endl;
    triPattChar(5);
    return 0;
}