#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
    Given an array and integer T, count number of disjoint pairs such that:
        1. Sum of each part is an exact multiple of T
        2. Each element is used only once

    1. Compute remainder and complement remainder.
    2. If unpaired element with required remainder exists, make a pair or store remainder.
*/

int countPairs(vector<int>& arr, int T) {
    unordered_map<int, int> freq;
    int count = 0;

    for(int x: arr) {
        int rem = ((x % T) + T) % T; // remainder with neg integer handling
        int need = (T - rem) % T; // complement remainder

        if(freq[need] > 0) { // unpaired complement exists, make pair
            count++;
            freq[need]--;
        } else {
            freq[rem]++; // store remainder
        }
    }

    return count;
}

int main() {
    int N, T;
    cin >> N >> T;

    vector<int> arr(N);
    for(int i=0; i<N; i++)
        cin >> arr[i];

    cout << countPairs(arr, T);

    return 0;
}