#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    int cnt = 0;

    //sort elements
    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else{
            temp.push_back(arr[right]);
            cnt += (mid-left+1);
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
    return cnt;
}

int mergeSort(vector<int>& arr, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;

    int mid = (low+high)/2;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}
//TC- O(nlogn)
//SC- O(n)

int main(){
    vector<int> arr = {5,3,2,1,4};
    int n = arr.size();
    cout<<mergeSort(arr, 0, n-1)<<endl;
}