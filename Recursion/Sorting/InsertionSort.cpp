#include <iostream>
using namespace std;

void sortArray(int *arr, int size, int index=1){
    if (index == size) return;

    int curr = arr[index], prev = index-1;

    while(prev>=0 && arr[prev]>curr){
        arr[prev+1] = arr[prev];
        prev--;
    }
    arr[prev+1] = curr;

    sortArray(arr, 7, index+1);
}

int main(){
    int arr[7] = {10, 1, 7, 4, 8, 2, 11};

    sortArray(arr, 7);

    for(int i=0; i<7; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}