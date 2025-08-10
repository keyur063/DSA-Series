#include <iostream>
#include <vector>
using namespace std;

int recBinarySearch(vector<int> &arr, int target, int start, int end){
    if(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]<target)
            return recBinarySearch(arr, target, mid+1, end);
        else if(arr[mid]>target){
            return recBinarySearch(arr, target, start, mid-1);
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {-1, 0, 3, 4, 5, 9, 12};
    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};
    int tar, st=0, end=arr.size()-1;

    cout<< recBinarySearch(arr, 9, st, end)<< endl;
    cout<< recBinarySearch(arr, 10, st, end)<< endl;
    return 0;
}