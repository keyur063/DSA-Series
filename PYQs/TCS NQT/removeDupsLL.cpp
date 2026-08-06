#include<iostream>
#include<unordered_set>
using namespace std;

/*
    1. Create LL from given input.
    2. Remove dups keeping first occurence.
    3. Reverse and print list.
*/

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void insert(Node* &head, int val) {
    Node* newNode = new Node(val);

    if(!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp -> next)
        temp = temp -> next;

    temp -> next = newNode;
}

Node* removeDups(Node* head) {
    unordered_set<int> vis;

    Node* curr = head;
    Node* prev = NULL;

    while(curr) {
        if(vis.find(curr -> data) != vis.end()) {
            Node* nextNode = curr -> next;
            prev -> next = nextNode;
            delete curr;
            curr = nextNode;
        } else {
            vis.insert(curr -> data);
            prev = curr;
            curr = curr -> next;
        }
    }

    return head;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* nextNode = NULL;

    while(curr) {
        nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

void printList(Node* head) {
    while(head) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

int main() {
    int N;
    cin >> N;

    Node* head = NULL;
    for(int i=0; i<N; i++) {   
        int x;     
        cin >> x;
        insert(head, x);
    }

    head = removeDups(head);
    head = reverse(head);
    printList(head);

    return 0;
}