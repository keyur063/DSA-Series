#include <iostream>
#include <climits>
using namespace std;

void rowSum(int arr[][4], int rows, int cols){
    for(int row=0; row<rows; row++){ //switch row and col loop to print colSum 
        int sum = 0;

        for(int col=0; col<cols; col++){
            sum += arr[row][col];
        }
        cout << sum << endl;
    }
}

int largestRowSum(int arr[][4], int rows, int cols){
    int maxi = INT_MIN, rowIndex = -1;

    for(int row=0; row<rows; row++){
        int sum = 0;

        for(int col=0; col<cols; col++){
            sum += arr[row][col];
        }
        if(sum > maxi){
            maxi = sum;
            rowIndex = row;
        }
    }
    cout << "The maximum sum of row is " << maxi << endl;
    return rowIndex;
}

int main(){
    int arr[3][4] = {1, 3, 4, 18, 34, 46, 55, 186, 98, 71, 27, 64};

    rowSum(arr, 3, 4);
    cout << endl;

    int ansIndex = largestRowSum(arr, 3, 4);
    cout << "Maximum sum is at row: " << ansIndex+1 << endl;

    return 0;
}