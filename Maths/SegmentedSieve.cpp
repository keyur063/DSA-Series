#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> simpleSieve(int n){
    vector<int> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=i*i; j<n; j+=i){
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

int countPrimesInRange(long long L, long long R) {
    int n = sqrt(R);

    vector<int> primes = simpleSieve(n);

    vector<bool> isPrime(R - L + 1, true);

    if (L == 1) isPrime[0] = false;

    for (int prime : primes) {
        // Find the minimum number in [L, R] that is a multiple of 'prime'
        long long start = max((long long)(prime * prime), (L + prime - 1) / prime * (long long)prime);

        // Mark multiples of 'prime' in range [L, R] as non-prime
        for (long long j = start; j <= R; j += prime) {
            isPrime[j - L] = false;
        }
    }

    int count = 0;
    for (long long i = 0; i <= R - L; i++) {
        if (isPrime[i]) count++;
    }
    return count;
}

int main(){
    long long L, R;

    cout << "Enter range: " << endl;
    cin >> L >> R;

    cout << countPrimesInRange(L, R);

    return 0;
}