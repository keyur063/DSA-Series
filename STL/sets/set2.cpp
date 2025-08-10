#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main(){
    //Set is a tree so O(logn) TC 
    multiset<int> s;
    unordered_set<int> us; //not sorted so no lb/ub O(1) TC

    cout << "Multi Set" << endl;

    for(int i=1; i<6; i++){
        s.insert(i);
    }

    cout << "Size: " << s.size() << endl;

    s.insert(1);
    s.insert(2);

    cout << "After inserting repeated elements..." <<endl;
    cout << "Size: " << s.size() << endl;

    for(auto val: s){
        cout << val << " ";
    }
    cout << endl;

    cout << "Unordered Set" << endl;

    for(int i=1; i<6; i++){
        us.insert(i);
    }

    cout << "Size: " << us.size() << endl;

    us.insert(1);
    us.insert(2);

    cout << "After inserting repeated elements..." <<endl;
    cout << "Size: " << us.size() << endl;

    for(auto val: us){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}