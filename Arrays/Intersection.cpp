#include <iostream>
using namespace std;

int main(){
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {2, 3, 4};
    int size1 = 3, size2 = 3;

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(arr1[i] == arr2[j]){
                cout<<arr1[i]<<endl;;
                break;
            }
        }
    }
    return 0;
}