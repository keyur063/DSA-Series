#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int> arr, int target){ //arr[i] >= k
    int n = arr.size();
    int low=0, high=n-1, ans=n;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        } else
            low = mid+1;
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>>& matrix, int n, int m){
    int maxCnt = 0;
    int idx = -1;

    for(int i=0; i<n; i++){
        int cnt = m - lowerBound(matrix[i], 1);
        if(cnt > maxCnt){
            maxCnt = cnt;
            idx = i;
        }
    }
    return idx;
}

//TC- O(n * logm)

int main(){
    vector<vector<int>> matrix = {{0,0,1,1,1}, {0,0,0,0,0}, {0,1,1,1,1}, {0,0,0,0,0}, {0,1,1,1,1}};
    cout<<rowWithMax1s(matrix, 5, 5)<<endl;
}