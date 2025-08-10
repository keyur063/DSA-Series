#include <iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int rows, int cols){
    for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            if(arr[row][col] == target) return true;
        }
    }
    return false;
}

int main(){
    int arr[3][4] = {1, 3, 4, 18, 34, 46, 55, 76, 98, 71, 27, 64};

    if(isPresent(arr, 98, 3, 4)){
        cout << "Element is present in the array" << endl;
    } else{
        cout << "Element is not present in the array" << endl;
    }

    return 0;
}