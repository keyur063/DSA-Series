#include <iostream>
#include <climits>
using namespace std;

int minIndex(int arr[], int size){
    int min = INT_MAX, minIndex = -1;
    for(int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int maxIndex(int arr[], int size){
    int max = INT_MIN, maxIndex = -1;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main(){
    int arr[7] = {2, 34, 56, 74, -98, 23, -7};
    int size = 7;

    cout<< minIndex(arr, size)<< endl;
    cout<< maxIndex(arr, size)<< endl;
    return 0;
}