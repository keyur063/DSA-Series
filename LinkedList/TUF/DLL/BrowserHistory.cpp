#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node* prev;

    Node(string data1){ 
        data = data1;
        next = NULL;
        prev = NULL;
    }

    Node(string data1, Node* next1, Node* prev1){ 
        data = data1;
        next = next1;
        prev = prev1;
    }
};

class Browser{
    public:
    Node* curr;

    Browser(string homepage){ //O(1)
        curr = new Node(homepage);
    }

    void visit(string url){ //O(1)
        Node* newNode = new Node(url);
        newNode->prev = curr;
        curr->next = newNode;
        curr = newNode;
    }

    string back(int steps){ //O(steps)
        while(steps){
            if(curr->prev)
                curr = curr->prev;
            else break;
            steps--;
        }
        return curr->data;
    }

    string forward(int steps){ //O(steps)
        while(steps){
            if(curr->next)
                curr = curr->next;
            else break;
            steps--;
        }
        return curr->data;
    }
};

void printLL(Node* head) {
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}


int main(){
    Node* head = new Node("abc.com");
    Node* n1 = new Node("google.com");
    Node* n2 = new Node("def.com");
    Node* n3 = new Node("leetcode.com");
    Node* n4 = new Node("pqr.com");

    head->next = n1;
    n1->prev = head;

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    printLL(head);

    Browser browser("abc.com");
    browser.visit("google.com");
    browser.visit("def.com");
    browser.visit("leetcode.com");
    browser.visit("pqr.com");
    cout<<browser.back(2)<<endl;
    cout<<browser.forward(1)<<endl;
}