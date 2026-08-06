#include<iostream>
#include<stack>
using namespace std;

/*
    Push N strings into a stack and pop M strings. Print output as:
    stack_status top_element remaining_elements
*/

int main() {
    int N, M;
    cin >> N >> M;

    stack<string> st;
    while(N--) {
        string S;
        cin >> S;
        st.push(S);
    }

    while(!st.empty() && M--) st.pop();

    if(st.empty())
        cout << "True - 0" << endl;
    else cout << "False " << st.top() << " " << st.size() << endl;

    return 0;
}