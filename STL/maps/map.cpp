#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> m;

    m["TV"] = 100;
    m["Laptop"] = 100;
    m["Headphone"] = 50;
    m["Tablet"] = 120;
    m["Watch"] = 50;

    m.insert({"Camera", 25});
    m.emplace("Mobile", 120);

    m.erase("TV");

    for(auto p: m){
        cout << p.first << " " << p.second << endl; //sorted lexicographically
    }

    cout << "Count: " << m.count("Laptop") << endl; //Returns no. of keys
    cout << "Count: " << m["Laptop"] << endl; //Returns value of key

    //find- if found returns iterator, else returns m.end()
    if(m.find("Camera") != m.end()){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    return 0;
}