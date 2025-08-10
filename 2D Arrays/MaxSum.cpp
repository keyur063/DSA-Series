#include <iostream>
#include <climits>
using namespace std;

int maxRowSum(int matrix[][4], int n){
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += matrix[i][j];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int maxColSum(int matrix[][4], int n){
    int maxSum = INT_MIN;
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[j][i];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main(){
    int matrix[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int n = 4;

    cout << maxRowSum(matrix, n) << endl;
    cout << maxColSum(matrix, n) << endl;
}