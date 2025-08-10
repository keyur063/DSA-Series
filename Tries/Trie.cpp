#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++) children[i] = NULL;
            isTerminal = false;
        }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        //assume uppercase letters
        int index = word[0] - 'A';
        TrieNode* child;

        //char is present
        if(root -> children[index] != NULL){
            //next character present
            child = root -> children[index];
        } else{
            //next character absent
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word); // O(length)
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0) 
            return root -> isTerminal;

        int index = word[0] - 'A';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        } else{
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool removeUtil(TrieNode* root, string word){
        if(word.length() == 0){
            //mark node as non-terminal
            root -> isTerminal = false;

            //no child should be present
            for(int i=0; i<26; i++){
                if(root -> children[i] != NULL) 
                    return false;
            }
            return true;
        }

        int index = word[0] - 'A';
        TrieNode* child = root -> children[index];

        //word not found
        if(child == NULL) return false;
    }

    void removeWord(string word){
        removeUtil(root, word); // O(length)
    }

    bool searchWord(string word){
        return searchUtil(root, word); // O(length)
    }

    bool prefixUtil(TrieNode* root, string prefix){
        if(prefix.length() == 0) 
            return true;

        int index = prefix[0] - 'A';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        } else{
            return false;
        }

        return prefixUtil(child, prefix.substr(1));
    }

    bool prefixWord(string prefix){
        return prefixUtil(root, prefix);
    }
};

int main(){
    Trie* t = new Trie();
    t -> insertWord("TIME");
    t -> insertWord("MONEY");
    t -> insertWord("TIMEOUT");

    cout << "Is word present? " << t -> searchWord("TIME") << endl;

    cout << "Is prefix present? " <<  t -> prefixWord("TI") << endl;
}