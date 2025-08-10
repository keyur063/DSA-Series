#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //free memory
    ~Node(){
        int value = this -> data;

        if(this -> next != NULL){
            delete next;
            next = NULL;
        }

        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertNode(Node* &tail, int el, int d){
    Node* temp = new Node(d);

    // Empty List
    if(tail == NULL){
        tail = temp;
        temp -> next = temp;
        return;
    }

    // Assuming element is present in LL
    Node* curr = tail;

    while(curr -> data != el){
        curr = curr -> next;
    } 

    // curr is pointing to element
    temp -> next = curr -> next;
    curr -> next = temp;
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout << "List is empty" << endl;
        return;
    }

    Node* prev = tail;
    Node* curr = prev -> next;

    while(curr -> data != value){
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;

    // 1 node LL
    if(curr == prev) tail = NULL;

    // >=2 nodes LL
    if(tail == curr) tail = prev;

    curr -> next = NULL;

    delete curr;
}

void printLL(Node* &tail){
    Node* temp = tail;

    if(tail == NULL){
        cout << "List is empty" << endl;
        return;
    }

    // while loop won't print 1st node
    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 3, 4);
    insertNode(tail, 5, 6);
    insertNode(tail, 6, 7);
    insertNode(tail, 7, 8);

    deleteNode(tail, 5);
    deleteNode(tail, 3);
    deleteNode(tail, 8);

    printLL(tail);

    cout << "Tail: " << tail -> data << endl;
}