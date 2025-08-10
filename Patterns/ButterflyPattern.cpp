#include <iostream>
using namespace std;

/*For n=4
*      *
**    **
***  ***
********
********
***  ***
**    **
*      *
*/
void butterflyPatt(int n){
    //top
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            cout<<"*";
        }
        for(int j=0; j<2*(3-i); j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    butterflyPatt(5);
    return 0;
}