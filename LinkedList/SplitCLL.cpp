#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
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

int getLength(Node* &tail){
    int len = 0;
    Node* curr = tail;
    Node* temp = tail;

    while(curr != temp){
        curr = curr -> next;
        len++;
    }
    return len;
}

void splitCLL(Node* &tail){
    int len = getLength(tail);
    int mid = len / 2;
    
    
}


void printLL(Node* &tail){
    Node* temp = tail;

    if(tail == NULL){
        cout << "List is empty" << endl;
        return;
    }

    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;
}

int main(){
    Node* tail = new Node(10);
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 30, 40);

    printLL(tail);
}