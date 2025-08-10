#include <iostream>
using namespace std;

int factorial(int n){
    if (n == 0) return 1; //to avoid stack overfloe dur to infinite recursive calls, return compulsory

    return n * factorial(n-1);
}

int main(){
    int n;
    cin >> n;

    int ans = factorial(n);
    cout << ans << endl;
}

//BC --> Processing --> Rec Reln == Tail Rec
//BC --> Rec Reln --> Processing == Head Rec