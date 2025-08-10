#include <iostream>
#include <vector>
using namespace std;

vector<int> reverseArray(vector<int> &vec, int size){
    int start = 0, end = size - 1;
    while(start <= end){
        swap(vec[start], vec[end]);
        start ++;
        end --;
    }
    return vec;
}

int main(){
    vector<int> vec = {1, 2, 3, 6, 5, 4, 7};
    int size = 7;

    reverseArray(vec, size);
    for(int val: vec){
        cout<< val<<endl;
    }
    return 0;
}