#include<bits/stdc++.h>
using namespace std;

/*
    Given two integers N & S, find Nth prime starting from S.
    Return sum of that prime and next two consecutive primes.
*/

bool isPrime(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i=2; i*i<=n; i++) {
        if(n % i == 0) return false;
    }

    return true;
}

int sumNth(int n, int s) {
    int cnt = 0, num = s, nthPrime = 0;

    while(cnt < n) {
        if(isPrime(num)) {
            cnt++;
            
            if(cnt == n) {
                nthPrime = num;
                break;
            }
        }

        num++;
    }

    int sum = nthPrime, i = 0;
    int nextNum = nthPrime + 1;

    while(i < 2) {
        if(isPrime(nextNum)) {
            sum += nextNum;
            i++;
        }

        nextNum++;
    }

    return sum;
}

int main() {
    int N, S;
    cin >> N >> S;
    cout << sumNth(N, S);
    return 0;
}