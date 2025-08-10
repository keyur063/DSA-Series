#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    multimap<string, int> m;
    unordered_map<string, int> um;

    //Map is self balancing tree so TC is O(logn) and TC of unordered map is O(1)
    //Unordered map cannot have repeated keys
    //Keys not sorted lexicographically

    m.emplace("TV", 100);
    m.emplace("TV", 100);
    m.emplace("TV", 100);
    m.emplace("TV", 100);

    m.erase(m.find("TV"));//using erase deletes all keys

    for(auto p: m){
        cout << p.first << " " << p.second << endl; //sorted lexicographically
    }
}