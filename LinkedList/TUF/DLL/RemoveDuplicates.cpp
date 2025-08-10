#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1){ 
        data = data1;
        next = NULL;
        prev = NULL;
    }

    Node(int data1, Node* next1, Node* prev1){ 
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* convertArrToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        temp->prev = prev;
        prev = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* removeDuplicates(Node* head){
    Node* temp = head;
    while(temp && temp->next){ //O(N-duplicates)
        Node* nextNode = temp->next;
        while(nextNode && (nextNode->data == temp->data)){ //O(duplicates)
            Node* delNode = nextNode;
            nextNode = nextNode->next;
            delete delNode;
        }

        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;

        temp = temp->next;
    }
    return head;
}
//TC- O(N)

int main(){
    vector<int> arr = {1,1,2,2,3,4,4,5};
    Node* head = convertArrToLL(arr);
    head = removeDuplicates(head);
    printLL(head);
}