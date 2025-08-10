#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

bool isOperand(char ch){
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
}

int priority(char ch){
    if(ch=='+' || ch=='-') return 1;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='^') return 3;
    else return -1;
}

string infixToPostfix(string& s){
    int i=0;
    stack<char> st;
    string ans = "";

    while(i<s.length()){
        if(isOperand(s[i])) ans += s[i];

        else if(s[i] == '(') st.push(s[i]);

        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); //pop '('
        } 
        
        else{ //operator
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}
//O(N) + O(N) while + inner while

string infixToPrefix(string& s){
    //Reverse s -> Switch Parentheses -> Infix to Postfix w/ conditions -> Reverse ans
    reverse(s.begin(), s.end());
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }

    int i=0;
    stack<char> st;
    string ans = "";

    while(i<s.length()){
        if(isOperand(s[i])) ans += s[i];

        else if(s[i] == '(') st.push(s[i]);

        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); //pop '('
        } 
        
        else{ //operator
            if(s[i] == '^'){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
            } else{
                while(!st.empty() && priority(s[i]) < priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
//O(N) + O(N) + 2*O(N/2) while + inner while + reverse

string postfixToInfix(string& s){
    int i=0;
    stack<string> st;

    while(i<s.length()){
        if(isOperand(s[i])) st.push(string(1, s[i]));
        else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            string t = '(' + top2 + s[i] + top1 + ')';
            st.push(t);
        }
        i++;
    }

    return st.top();
}
//O(N) + O(N) while + str addn

string prefixToInfix(string& s){
    int i=s.length()-1;
    stack<string> st;

    while(i>=0){
        if(isOperand(s[i])) st.push(string(1, s[i]));
        else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            string t = '(' + top1 + s[i] + top2 + ')';
            st.push(t);
        }
        i--;
    }

    return st.top();
}
//O(N) + O(N) while + str addn

string postfixToPrefix(string& s){
    int i=0;
    stack<string> st;

    while(i<s.length()){
        if(isOperand(s[i])) st.push(string(1, s[i]));
        else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            string t = s[i] + top2 + top1;
            st.push(t);
        }
        i++;
    }

    return st.top();
}
//O(N) + O(N) while + str addn

string prefixToPostfix(string& s){
    int i=s.length()-1;
    stack<string> st;

    while(i>=0){
        if(isOperand(s[i])) st.push(string(1, s[i]));
        else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            string t = top1 + top2 + s[i];
            st.push(t);
        }
        i--;
    }

    return st.top();
}


int main(){
    // string s1 = "a+b*(c^d-e)";
    // cout<<infixToPostfix(s1)<<endl;
    // cout<<infixToPrefix(s1)<<endl;

    string s2 = "AB-DE+F*/";
    cout<<postfixToInfix(s2)<<endl;
    cout<<postfixToPrefix(s2)<<endl;

    string s3 = "*+PQ-MN";
    cout<<prefixToInfix(s3)<<endl;
    cout<<prefixToPostfix(s3)<<endl;
}