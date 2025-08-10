#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.size() << endl;

    stack<int> s2;
    s2.swap(s);

    cout << s.size() << endl;
    cout << s2.size() << endl;

    while(!s2.empty()){
        cout << s2.top() << endl;
        s2.pop();
    }
    cout << endl;

    return 0;
}