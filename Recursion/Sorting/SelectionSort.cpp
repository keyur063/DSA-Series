#include <iostream>
using namespace std;

void sortArray(int *arr, int size, int index=0){
    if(index==size-1) return;

    int minIndex = index;

    for (int j = index + 1; j < size; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }

    swap(arr[minIndex], arr[index]);

    sortArray(arr, size, index+1);
}

int main(){
    int arr[5] = {64, 25, 12, 22, 11};

    sortArray(arr, 5);

    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}