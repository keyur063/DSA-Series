#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int arr[5] = {3, 5, 1, 8, 2};
    sort(arr, arr+5);

    for(int val: arr){
        cout << val << " ";
    }
    cout << endl;

    vector<int> vec = {3, 5, 1, 8, 2};
    sort(vec.begin(), vec.end(), greater<int> ()); //functor/comparator

    for(int val: vec){
        cout << val << " ";
    }

    return 0;
}