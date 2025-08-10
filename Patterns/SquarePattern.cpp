/*for n=4
1234
1234
1234
1234*/
#include <iostream>
using namespace std;

void sqPatt(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout <<j<<" ";
        }
        cout<<endl;
    }
}
int main(){
    sqPatt(4);
    cout<<'\n';
    sqPatt(3);
    return 0;
}