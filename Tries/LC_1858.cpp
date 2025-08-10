#include<iostream>
#include<vector>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }  

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    bool setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i<word.length(); i++) {
            if (!node -> containsKey(word[i]))
                node -> put(word[i], new Node());
            
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }

    bool checkIfPrefixExists(string word) {
        bool flag = true;
        Node* node = root;
        
        for(int i=0; i<word.length(); i++) {
            if(!node -> containsKey(word[i])) 
                return false;

            node = node -> get(word[i]);

            if(!node -> isEnd())
                return false;
        }
        return true;
    }
};

string completeString(vector<string> &s) {
    Trie t;
    string ans = "";

    for(auto &it: s) 
        t.insert(it);

    for(auto &it: s) {
        if(t.checkIfPrefixExists(it)) {
            if(it.length() > ans.length())
                ans = it;
            else if((it.length() == ans.length()) && (it < ans))
                ans = it;
        }
    }

    if(ans == "") return "None";
    return ans;
}

int main() {
    vector<string> s = {"n", "ni", "nin", "ninj" , "ninja" , "nil"};
    cout << completeString(s);
}