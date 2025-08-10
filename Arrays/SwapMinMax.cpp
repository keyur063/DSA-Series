#include <iostream>
#include <climits>
using namespace std;

void swapMinMax(int arr[], int size){
    int min = INT_MAX;
    int max = INT_MIN;
    int minIndex = -1, maxIndex = -1;

    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }

        if(arr[i] < min){
            min = arr[i];
            minIndex = i;
        }
    }

    swap(arr[minIndex], arr[maxIndex]);
}

int main(){
    int arr[7] = {2, 34, 56, 74, -98, 23, -7};
    int size = 7;
    
    swapMinMax(arr, size);
    for(int i=0; i<size; i++){
        cout << arr[i] <<endl;
    }
    return 0;
}