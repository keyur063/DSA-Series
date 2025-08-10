#include <iostream>
using namespace std;

void merge(int *arr, int st, int end){
    int mid = st + (end-st)/2;

    int len1 = mid-st+1;
    int len2 = end-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int k = st;
    for(int i = 0; i < len1; i++){
        first[i] = arr[k++];
    }

    k = mid+1;
    for(int i = 0; i < len2; i++){
        second[i] = arr[k++];
    }

    // merge 2 sorted arrays
    int index1=0, index2=0;
    k = st;
    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[k++] = first[index1++];
        } else{
            arr[k++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[k++] = first[index1++];
    }
    while(index2 < len2){
        arr[k++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int st, int end){
    if(st>=end) return;

    int mid = st + (end-st)/2;

    mergeSort(arr, st, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, st, end);
}

int main(){
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr, 0, 6);

    for(int i=0; i<7; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}