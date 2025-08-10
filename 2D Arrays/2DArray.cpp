#include <iostream>
using namespace std;

int main(){
    int arr[3][4];
    // int arr[2][2] = {0, 1, 2, 3};
    // int arr[2][2] = {{0, 1}, {2, 3}};

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin >> arr[i][j];
        }
    }

    cout << "Printing Array: " << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}