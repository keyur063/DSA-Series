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
};

bool isCircular(Node* &head){
    if(head == NULL) return true; // empty list

    Node* temp = head -> next;

    while(temp != head && temp != NULL){
        temp = temp -> next;
    }

    if(temp == head) return true;

    return false;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    if(isCircular(head)){
        cout << "The linked list is circular" << endl;
    } else{
        cout << "The linked list is not circular" << endl;
    }
}