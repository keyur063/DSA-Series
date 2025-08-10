#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){}

void selectionSort(int arr[], int n){}

void insertionSort(int arr[], int n){}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {4, 1, 5, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Bubble Sorting..."<<endl;
    bubbleSort(arr, n);
    printArray(arr, n);
    cout<<endl;

    cout<<"Selection Sorting..."<<endl;
    selectionSort(arr, n);
    printArray(arr, n);
    cout<<endl;

    cout<<"Insertion Sorting..."<<endl;
    insertionSort(arr, n);
    printArray(arr, n);
    cout<<endl;
    return 0;
}