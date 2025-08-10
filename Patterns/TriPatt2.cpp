#include <iostream>
using namespace std;

/*For n=4
1
1 2
1 2 3
1 2 3 4
*/
void triPatt(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout<<endl;
    }
}

/*For n=4
1
2 1
3 2 1
4 3 2 1
*/
void revTriPatt(int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j>0; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

/*For n=4
1
2 3
4 5 6 
7 8 9 10
*/
void FloydTriPatt(int n){
    int num = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

int main(){
    triPatt(5);
    cout<<endl;
    revTriPatt(5);
    cout<<endl;
    FloydTriPatt(5);
    return 0;
}