#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target){
    int st=0, end=arr.size()-1;
    
    while(st<=end){
        int mid = st + (end-st)/2;
        if(arr[mid]<target)
            st=mid+1;
        else if(arr[mid]>target){
            end=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};
    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};
    int tar1, tar2;

    cout<< binarySearch(arr1, 9)<< endl;
    cout<< binarySearch(arr2, 3)<< endl;
    cout<< binarySearch(arr1, 10)<< endl;
    return 0;
}