#include <iostream>
#include <set>
using namespace std;

int main(){
    //Set is a tree so O(logn) TC 
    set<int> s;

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

    cout << "Lower Bound: " << *(s.lower_bound(4)) << endl; //4
    //returns val not less than key or max_val if key doesn't exist
    //else returns val of s.end() if max_val is less than key
    
    cout << "Lower Bound: " << *(s.upper_bound(4)) << endl; //5
    //returns val just greater than key

    return 0;
}