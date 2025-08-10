#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSubarrays(vector<int> arr, int k){
    int n = arr.size();
    int cnt=0, xr=0;
    unordered_map<int, int> m;
    m[xr]++;

    for(int i=0; i<n; ++i){
        xr ^= arr[i];
        int x = xr^k;
        cnt += m[x];
        m[xr]++;
    }
    return cnt;
}
//O(N x map), O(N)

int main(){
    vector<int> arr = {4,2,2,6,4};
    int k = 6;
    cout<<countSubarrays(arr, k)<<endl;
}