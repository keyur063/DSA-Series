#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
    Create a class Stack that implements with foll. methods: 
        push(value: string), pop(), evaluate()
    The class should be encapsulated(private) accessible only through these methods.
    Use this class to evaluate a postfix expression.
*/

class Stack {
private:
    vector<int> st;

public:
    void push(string value) {
        st.push_back(stoi(value));
    }

    int pop() {
        int val = st.back();
        st.pop_back();
        return val;
    }

    int evaluate(int n) {
        vector<string> tokens(n);
        string s;
        cin >> s;

        for(int i=0; i<n; i++) 
            tokens[i] = s[i];

        for(string token: tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int b = pop();
                int a = pop();

                int ans;
                if(token == "+")
                    ans = a + b;
                else if(token == "-")
                    ans = a - b;
                else if(token == "*")
                    ans = a * b;
                else ans = a / b;

                st.push_back(ans);
            } 
            else push(token);
        }

        return pop();
    }
};

int main() {
    int n;
    cin >> n;

    Stack s;
    cout << s.evaluate(n);

    return 0;
}