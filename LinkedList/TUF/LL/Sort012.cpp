#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){ 
        data = data1;
        next = NULL;
    }

    Node(int data1, Node* next1){ 
        data = data1;
        next = next1;
    }
};

Node* convertArrToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* sort012(Node* head){
    if((head == NULL) || (head->next == NULL))
        return head;

    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* temp = head;
    while(temp){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next ? twoHead->next : NULL;
    two->next = NULL;
    Node* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

int main(){
    vector<int> arr = {1,0,1,2,0,2,1};
    Node* head = convertArrToLL(arr);
    printLL(head);
    head = sort012(head);
    printLL(head);
}