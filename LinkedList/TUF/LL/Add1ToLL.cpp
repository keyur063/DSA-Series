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

Node* reverseList(Node* head) {
    if((head == NULL) || (head->next == NULL))
        return head;
        
    Node* newHead = reverseList(head->next);
    Node* next = head->next;
    next->next = head;
    head->next = NULL;
    return newHead;
}

Node* add1(Node* head){
    head = reverseList(head);
    Node* temp = head;
    int cy = 1;

    while(temp){
        temp->data += cy;
        if(temp->data < 10){
            cy = 0;
            break;
        } else{
            temp->data = 0;
            cy = 1;
        }
        temp = temp->next;
    }

    if(cy){
        Node* newNode = new Node(1);
        head = reverseList(head);
        newNode->next = head;
        return newNode;
    }

    head = reverseList(head);
    return head;
}
//TC- 3 x O(N) (2 rev + 1 while loop)

int getCarry(Node* temp){
    if(!temp)
        return 1;

    int cy = getCarry(temp->next);
    temp->data += cy;

    if(temp->data < 10)
        return 0;

    temp->data = 0;
    return 1;
}

Node* add1Optimal(Node* head){
    int cy = getCarry(head);
    if(cy){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

int main(){
    vector<int> arr1 = {9,9,9,9};
    Node* head1 = convertArrToLL(arr1);
    head1 = add1Optimal (head1);
    printLL(head1);

    vector<int> arr2 = {1,5,9};
    Node* head2 = convertArrToLL(arr2);
    head2 = add1Optimal (head2);
    printLL(head2);
}