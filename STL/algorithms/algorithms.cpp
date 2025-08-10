#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec = {1, 2, 3, 4, 5};
    reverse(vec.begin()+1, vec.end()-2);

    for(auto val: vec){
        cout << val << " ";
    }
    cout << endl;

    string s = "bca";
    
    next_permutation(s.begin(), s.end());
    cout << s << endl;

    prev_permutation(s.begin(), s.end());
    cout << s << endl;

    int a=5, b=4;
    cout << "min= " << min(a, b) << ", " << "max= " << max(a, b) << endl;
    swap(a, b);
    cout << "a= " << a << ", " << "b= " << b << endl;

    cout << "Max element: " << *(max_element(vec.begin(), vec.end())) << endl; //returns iterator
    cout << "Min element: " << *(min_element(vec.begin(), vec.end())) << endl;

    cout << binary_search(vec.begin(), vec.end(), 10) << endl; //target=4, returns bool

    int n1 = 15;
    long int n2 = 16;
    long long int n3 = 3;

    //returns no. of 1s
    cout << __builtin_popcount(n1) << endl;
    cout << __builtin_popcountl(n2) << endl;
    cout << __builtin_popcountll(n3) << endl;

    return 0;
}