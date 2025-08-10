#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4); 
    vec.push_back(5); //assumes data type is correct
    vec.emplace_back(6); //creates data type inplace

    vec.pop_back();

    cout << "The size of vector is " << vec.size() << endl; //no. of elements(n)
    cout << "The capacity of vector is " << vec.capacity() << endl; //capacity increases by 2 bits on addn of element capacity=2**(n-1)
    cout << endl;

    cout << "Printing elements..." << endl;
    for(int val: vec){
        cout << val << " ";
    }

    cout << endl;
    cout << "Val at idx 2 is " << vec[2] << " or " << vec.at(2) << endl;
    cout << endl;

    cout << "Front: " << vec.front() << endl;
    cout << "Back: " << vec.back() << endl;

    return 0;
} 