#include <iostream>
#include <list>
#include <deque>
using namespace std;

//list is doubly linked list so l[idx] is not accessible
//deque is dynamic array so d[idx] is accessible
int main(){
    list<int> l;
    deque<int> d = {1, 2, 3, 4, 5}; //Double ended queue

    l.emplace_back(1);
    l.push_back(2);
    l.emplace_front(3);
    l.push_front(5);

    l.pop_back();
    l.pop_front();

    cout << "Printing elements of list..." << endl;
    for(int val: l){
        cout << val << " "; //3 1
    }
    cout << endl;

    cout << "Printing elements of deque..." << endl;
    for(int val: d){
        cout << val << " ";
    }
    cout << endl;

    cout << d[2] << endl;
    //cout << l[2] << endl;

    return 0;
}