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

    //free memory
    ~Node(){
        int value = this -> data;

        if(next != NULL){
            delete next;
            next = NULL;
        }

        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);

    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);

    if(tail == temp){
        head = temp;
        tail = temp;
        return;
    }

    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtIndex(Node* &head, Node* &tail, int position, int d){

    // as temp is pointed to head, insertAtIndex function is not applicable to insert at start
    if(position == 1){ 
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp -> next;
        count ++;
    }

    // to update tail
    if(temp -> next == NULL){
        insertAtTail(head, tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void printLL(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head){
    Node* temp = head;
    int len = 0;

    while(temp -> next != NULL){
        len ++;
        temp = temp -> next;
    }
}

void deleteNode(Node* &head, Node* &tail, int position){
    if(position == 1){
        Node* temp = head;

        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;

        delete temp;
    } else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count ++;
        }

        if(curr -> next == NULL) tail = prev;

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    //Node* node = new Node(10);

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 7);
    insertAtTail(head, tail, 13);
    insertAtTail(head, tail, 21);
    insertAtTail(head, tail, 26);
    insertAtIndex(head, tail, 2, 16);
    printLL(head);

    deleteNode(head, tail, 1);
    deleteNode(head, tail, 4);
    deleteNode(head, tail, 2);

    printLL(head);
    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;
}