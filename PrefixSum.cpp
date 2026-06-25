#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();

    vector<int> ans(n, 0);

    for(int i=1; i<n; i++) {
        ans[i] = ans[i-1] + arr[i-1];
    }

    for(int val: ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}