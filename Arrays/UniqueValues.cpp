#include <iostream>
using namespace std;

void printUnique(int arr[], int size){
    for(int i = 0; i < size; i++){
        bool isUnique = true;

        for(int j = 0; j < size; j++){
            if(i != j && arr[i] == arr[j]){
                isUnique = false;
                break;
            }
        }

        if(isUnique)
            cout << arr[i] << " ";
    }
    
}

int main(){
    int arr[9] = {1, 2, 2, 3, 4, 4, 5, 6, 6};
    int size = 9;
  
    printUnique(arr, size);
    
    return 0;
}