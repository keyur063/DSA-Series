#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){ //Constructor to create new node
        this->data = data;
        this->next = NULL;
    }

    //free memory
    ~Node(){
        int value = this -> data;

        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }

        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d); //new node creation

    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);

    if(tail == NULL){
        head = temp;
        tail = temp;
        return;
    }

    tail -> next = temp;
    tail = tail -> next;
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
    temp -> next = nodeToInsert;
}

void printLL(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteNode(Node* &head, Node* &tail, int position){
    if(position == 1){
        Node* temp = head;
        head = head -> next;
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

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    // Node* node = new Node(10);
    // cout << node -> data << endl;
    // cout << node -> next << endl;

    // head pointed to node
    Node* head = NULL;
    Node* tail = NULL;

    // insertAtHead(head, 12);
    insertAtTail(head, tail, 12);

    // insertAtHead(head, 15);
    insertAtTail(head, tail, 15);
    printLL(head);

    insertAtIndex(head, tail, 2, 22);
    insertAtIndex(head, tail, 1, 25);
    insertAtIndex(head, tail, 4, 27);
    printLL(head);

    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;

    deleteNode(head, tail, 4);
    deleteNode(head, tail, 5); //5th element is last

    printLL(head);
    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;
}