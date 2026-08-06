#include<iostream>
using namespace std;

/*
    Quick Sort Singly Linked List
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

Node* getTail(Node* &head) {
    while(head && head -> next) 
        head = head -> next;
    return head;
}

Node* partition(Node* &head, Node* &tail) {
    Node* pivot = head;
    Node* prev = head;
    Node* curr = head;

    while(curr != tail -> next) {
        if(curr -> data < pivot -> data) {
            swap(curr -> data, prev -> next -> data);
            prev = prev -> next;
        }

        curr = curr -> next;
    }

    swap(pivot -> data, prev -> data);
    return prev;
}

void quickSortHelper(Node* &head, Node* &tail) {
    if(head == NULL || head == tail) return;

    Node* pivot = partition(head, tail);
    quickSortHelper(head, pivot);
    quickSortHelper(pivot -> next, tail);
}

Node* quickSort(Node* &head) {
    Node* tail = getTail(head);
    quickSortHelper(head, tail);
    return head;
}

void printList(Node* &head) {
    while(head) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

int main() {
    Node* head = new Node(30);
    head -> next = new Node(3);
    head -> next -> next = new Node(4);
    head -> next -> next -> next = new Node(20);
    head -> next -> next -> next -> next = new Node(5);

    //head = quickSort(head);
    printList(head);

    return 0;
}