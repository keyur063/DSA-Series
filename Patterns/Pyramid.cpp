#include <iostream>
using namespace std;

/*For n=4
   1
  121
 12321
1234321
*/
void pyramid(int n){
    for(int i=0; i<n; i++){
        //spaces: n-i-1
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
        }

        //nums1: i+1
        for(int j=1; j<=i+1; j++){
            cout<<j;
        }
        //nums2
        for(int j=i; j>0; j--){
            cout<<j;
        }
        cout<<endl;
    }
}

int main(){
    pyramid(6);
    return 0;
}