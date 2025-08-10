#include <iostream>
using namespace std;

void print(int *arr, int st, int end){
    for(int i=st; i<end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearch(int *arr, int st, int end, int target){
    print(arr, st, end);

    if (st > end) return -1;

    int mid = st + (end-st)/2;

    if(arr[mid] == target) return mid;

    if(arr[mid] > target){
        return binarySearch(arr, st, mid-1, target);
    } else{
        return binarySearch(arr, mid+1, end, target);
    }
}

int main(){
    int arr[6] = {2, 4, 6, 10, 14, 16};

    int target;
    cin >> target;

    cout << "Element is present at index " << binarySearch(arr, 0, 5, target) << endl;
}