#include<iostream>
#include<vector>
using namespace std;

//DIVIDE AND MERGE ALGORITHM

void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    //sort elements
    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    //right array exhausted
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    } 

    //left array exhausted
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int>& arr, int low, int high){
    if(low >= high) return;

    int mid = (low+high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
//TC- O(nlogn)
//SC- O(n) + O(n) temp + ASS

int main(){
    vector<int> arr = {3,1,2,4,1,5,2,6,4};
    mergeSort(arr,0, arr.size()-1);

    for(int val: arr){
        cout<<val<<" ";
    }
}