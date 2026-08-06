#include<iostream>
#include<vector>
using namespace std;

/*
    TCS NQT 8th July
    Given a sorted array and key. If key is found, print.
    Else print element closest to key (min abs diff).
    If two elements are eqaully close, print smaller.

    
*/

int main() {
    int N, key;
    cin >> N;

    vector<int> arr(N);
    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    cin >> key;

    int low = 0, high = N-1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == key) {
            cout << arr[mid];
            return 0;
        }

        if(arr[mid] < key) 
            low = mid + 1;
        else high = mid - 1;    
    }

    if(high < 0) cout << arr[0];
    else if(low >= N) cout << arr[N-1];
    else {
        int leftDiff = abs(arr[high] - key);
        int rightDiff = abs(arr[low] - key);

        if(leftDiff <= rightDiff) cout << arr[high];
        else cout << arr[low];
    }

    return 0;
}