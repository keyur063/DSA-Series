#include<iostream>
using namespace std;

/*
    TCS NQT 8th July
    Given a positive integer N, print all its prime factors in increasing order.
    Print multiple times if factor is repeated.

    2 <= N <= 1e9
*/

int main() {
    int N;
    cin >> N;

    for(int i=2; i*i<=N; i++) {
        while(N % i == 0) {
            cout << i << " ";
            N /= i;
        }
    }

    // prime number
    if(N > 1) 
        cout << N;

    return 0;
}