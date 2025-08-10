#include <iostream>
#include <map>
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

bool isCyclePresent(Node* head){
    if(head == NULL) return false;

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL){
        if(visited[temp] == true){
            cout << "Cycle present at " << temp -> data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

Node* floydDetectLoop(Node* head){
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        slow = slow -> next;
        fast = fast -> next;

        if(fast != NULL){
            fast = fast -> next;
        }

        if(slow == fast){
            cout << "Cycle present at " << slow -> next -> data << endl;
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head){
    if(head == NULL) return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}

void removeLoop(Node* head){
    if(head == NULL) return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }

    temp -> next = NULL;
}

void printLL(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;

    // if(isCyclePresent(head)){
    //     cout << "Cycle is present" << endl;
    // } else{
    //     cout << "Cycle is not present" << endl;
    // }

    //  if(floydDetectLoop(head) != NULL){
    //     cout << "Cycle is present" << endl;
    // } else{
    //     cout << "Cycle is not present" << endl;
    // }

    int value = getStartingNode(head) -> data;
    cout << "Starting Node of Loop is " << value << endl;

    removeLoop(head);
    printLL(head);
}