#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //creation
    unordered_map<char, int> um;

    //insertion
    //1
    pair<char, int> p1 = make_pair('a', 1);
    um.insert(p1);

    //2
    pair<char, int> p2('b', 2);
    um.insert(p2);

    //3
    um['c'] = 3;
    um['d'] = 4;

    //updation
    um['e'] = 4;
    um['e'] = 5;

    //search
    cout << um['e'] << endl;
    cout << um.at('d') << endl;

    // cout << um.at('f') << endl; //error
    cout << um['f'] << endl; //automatically stores 0
    cout << um.at('f') << endl; //0

    //size
    cout << "Size: " << um.size() << endl << endl;

    //check if present
    cout << "Check if element is present: " << endl;
    cout << um.count('b') << endl; //1
    cout << um.count('h') << endl << endl; //0

    //erase
    um.erase('e');
    cout << "Size after erasing key: " << um.size() << endl << endl;

    //traversal
    for(auto i: um){
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    //iterator
    unordered_map<char, int> :: iterator it = um.begin();
    while(it != um.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
}
