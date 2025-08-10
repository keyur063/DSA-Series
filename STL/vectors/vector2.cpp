#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> vec1(10, -1); //10 times -1
    vector<int> vec2(vec); //prints elements of vec

    //erase and insert are costly functions, ie. have O(n) complexity

    vec.erase(vec.begin() + 1, vec.end() - 2); //1 4 5
    vec.insert(vec.begin() + 2, 100); // 1 4 100 5

    for(int val: vec){
        cout<< val << " ";
    }
    cout << endl;

    // vec.clear(); //size is 0 but capacity remains same
    cout << "Is empty? " << vec.empty() << endl;

    return 0;
}