#include <iostream>
using namespace std;

void print(int *arr, int size){
    cout << "Size of array is " << size << endl;

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isPresent(int *arr, int size, int target){
    print(arr, size);

    if(size==0) return false;

    if(arr[0]==target){
        return true;
    } else{
        bool remainingPart = isPresent(arr+1, size-1, target);
        return remainingPart;
    }
}

int main(){
    int arr[5] = {3, 5, 1, 2, 6};

    int target;
    cin >> target;

    if(isPresent(arr, 5, target)){
        cout << "Element is present" << endl;
    } else{
        cout << "Element is not present" << endl;
    }
}