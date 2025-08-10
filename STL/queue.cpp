#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    //priority_queue<int> pq; 
    priority_queue<int, vector<int>, greater<int>> pq; //For reverse order functor(func obj) is used

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    cout << endl;

    pq.push(5);
    pq.push(3);
    pq.push(10);
    pq.push(4);

    //top- O(1) push,pop- O(logn) TC
    //O(1) for stack & queue

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
    cout << endl;

    return 0;
}