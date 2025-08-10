#include <iostream>
using namespace std;

void printCounting(int n){
    if (n == 0) return; 

    cout << n << " "; //54321

    printCounting(n-1);

    cout << n << " "; //12345
}

int main(){
    int n;
    cin >> n;

    printCounting(n);
    cout << endl;
}