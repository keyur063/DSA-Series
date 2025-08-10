#include <iostream>
#include <vector>
using namespace std;

pair<int, int> getDiagonalSum(int matrix[][4], int n, pair<int, int>& p){
    for(int i = 0; i < n; i++){
        p.first += matrix[i][i];
    }
    for(int i = 0; i < n; i++){
        p.second += matrix[i][n - i - 1];
    }
    return p;
}

int main(){
    int matrix[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int n = 4;
    pair<int, int> p;

    getDiagonalSum(matrix, n, p);
    cout << p.first << " " <<p.second << endl;
}