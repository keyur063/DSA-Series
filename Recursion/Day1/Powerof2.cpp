#include <iostream>
using namespace std;

int powOf2(int n){
    if (n == 0) return 1; 

    return 2 * powOf2(n-1);
}

int main(){
    int n;
    cin >> n;

    int ans = powOf2(n);
    cout << ans << endl;
}