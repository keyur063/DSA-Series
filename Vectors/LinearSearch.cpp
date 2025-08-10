#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> &vec, int size, int target){
    for(int i = 0; i < size; i++){
        if(target == vec[i])
            return i;
    }
    return -1;
}

int main(){
    vector<int> vec = {1, 2, 3, 6, 5, 4, 7};
    int size = 7;

    cout<< linearSearch(vec, size, 5);
    return 0;
}