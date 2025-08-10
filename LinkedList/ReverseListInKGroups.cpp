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

Node* kReverse(Node* head, int k) {
    if(head == NULL || k == 1) return head;

    // Reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count ++;
    }

    // Recursion
    if(next != NULL){
        head -> next = kReverse(next, k);
    }

    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    cout << "Original List: ";
    printList(head);

    int k = 4;
    head = kReverse(head, k);

    cout << "Reversed List in groups of " << k << ": ";
    printList(head);
}