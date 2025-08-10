#include <iostream>
#include <vector>
using namespace std;

int main(){
    pair<int, int> p1 = {1, 5};
    pair<string, int> p2 = {"KeyM", 19};
    pair<int, pair<char, int>> p3 = {1, {'a', 3}};

    vector<pair<int, int>> vec = {{1, 2}, {3, 4}, {5, 6}};
    vec.push_back({7, 8}); //insert pair
    vec.emplace_back(9, 10); //create objects inplace


    cout << p1.first << endl;
    cout << p1.second << endl;
    cout << endl;
    
    cout << p2.first << endl;
    cout << p2.second << endl;
    cout << endl;

    cout << p3.first << endl;
    cout << p3.second.first  << endl;
    cout << p3.second.second << endl;
    cout << endl;

    for(pair<int, int> p: vec){
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}