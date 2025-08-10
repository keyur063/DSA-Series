#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int minElem(vector<vector<int>>& mat, int n, int col){
    int minElem = INT_MAX;
    for(int i=0; i<n; i++){
        if(mat[i][col] < minElem)
            minElem = mat[i][col];    
    }
    return minElem;
}

int maxElem(vector<vector<int>>& mat, int n, int col){
    int maxElem = -1;
    for(int i=0; i<n; i++){
        if(mat[i][col] > maxElem)
            maxElem = mat[i][col];    
    }
    return maxElem;
}

int upperBound(vector<int> arr, int target){ //arr[i] > k
    int n = arr.size();
    int low=0, high=n-1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > target)
            high = mid-1;
        else
            low = mid+1;
    }
    return low;
}

int countSmallerNum(vector<vector<int>>& mat, int n, int target){ //O(nlogm)
    int cnt = 0;
    for(int i=0; i<n; i++)
        cnt += upperBound(mat[i], target);
    return cnt;
}

int findMedian(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();

    int low = minElem(mat, n, 0);
    int high = maxElem(mat, n, m-1);
    int req = (n*m)/2;

    while(low <= high){
        int mid = (low+high)/2;
        int smallerNums = countSmallerNum(mat, n, mid);

        if(smallerNums <= req)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}
//TC- O(log(1e9) × n × log m) -> BS x countSmallerNums 

int main(){
    vector<vector<int>> mat = {{1, 3, 8}, {2, 3, 4}, {1, 2, 5}};
    cout<<findMedian(mat)<<endl;
}