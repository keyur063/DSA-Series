#include <iostream>
using namespace std;

int partition(int *arr, int st, int end){
    int pivot = arr[st], count = 0;

    for(int i=st+1; i<=end; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    // place pivot at right place
    int pivotIndex = st + count;
    swap(arr[pivotIndex], arr[st]);

    int i=st, j=end;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }

    }
    return pivotIndex;
}

void quickSort(int *arr, int st, int end){
    if(st>=end) return;

    int p = partition(arr, st, end);

    quickSort(arr, st, p-1);
    quickSort(arr, p+1, end);
}

int main(){
    int arr[5] = {3, 1, 4, 5, 2};

    quickSort(arr, 0, 4);

    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}