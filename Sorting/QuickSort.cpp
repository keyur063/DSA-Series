#include<iostream>
#include<vector>
using namespace std;

//DIVIDE AND CONQUER ALGORITHM

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int left = low;
    int right = high;

    while(left < right){
        while((arr[left] <= pivot) && (left < high)) left++;
        while((arr[right] > pivot) && (right > low)) right--;

        if(left < right) swap(arr[left], arr[right]);
    }

    swap(arr[low], arr[right]);
    return right;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
}
//TC- O(nlogn)
//SC- O(n) ASS

int main(){
    vector<int> arr = {3,1,2,4,1,5,2,6,4};
    quickSort(arr, 0, arr.size()-1);

    for(int val: arr){
        cout<<val<<" ";
    }
}