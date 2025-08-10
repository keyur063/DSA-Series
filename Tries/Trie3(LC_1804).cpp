#include<iostream>
using namespace std;

struct Node {
    Node* links[26];
    int countWord = 0;
    int countPrefix =0;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void increaseEnd() {
        countWord++;
    }

    void increasePrefix() {
        countPrefix++;
    }

    void deleteEnd() {
        countWord--;
    }

    void reducePrefix() {
        countPrefix--;
    }

    int getEnd() {
        return countWord;
    }

    int getPrefix() {
        return countPrefix;
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
        for(int i=0; i<word.length(); i++) {
            if(!(node -> containsKey(word[i]))) 
                node -> put(word[i], new Node());

            node = node -> get(word[i]);
            node -> increasePrefix();
        }
        node -> increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(node -> containsKey(word[i])) 
                node = node -> get(word[i]);
            else
                return 0;
        }
        node -> getEnd();
    }

    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.length(); i++) {
            if(node -> containsKey(prefix[i])) 
                node = node -> get(prefix[i]);
            else
                return 0;
        }
        node -> getPrefix();
    }

    void erase(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(node -> containsKey(word[i])) {
                node = node -> get(word[i]);
                node -> reducePrefix();
            }
            else
                return;
        }
        node -> deleteEnd();
    }
};

int main() {
    Trie* t = new Trie();
    t -> insert("apple");
    t -> insert("apple");
    t -> insert("apps");
    t -> insert("ape");

    cout << "How many 'apple' present? " << t -> countWordsEqualTo("apple") << endl;
    cout << "How many 'app' prefix present? " << t -> countWordsStartingWith("app") << endl;

    t -> erase("apple");

    cout << "How many 'apple' present? " << t -> countWordsEqualTo("apple") << endl;
    cout << "How many 'app' prefix present? " << t -> countWordsStartingWith("app") << endl;
    cout << "How many 'ap' prefix present? " << t -> countWordsStartingWith("ap") << endl;
}