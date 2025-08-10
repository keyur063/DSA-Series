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

void printLL(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* deleteOcc(Node* head, int key){
    Node* temp = head;
    while(temp){
        if(temp->data == key){
            if(temp == head)
                head = temp->next;
             
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            
            if(nextNode) nextNode->prev = prevNode;
            if(prevNode) prevNode->next = nextNode;          

            delete temp;
            temp = nextNode;
        } else
            temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {10,4,10,16,5,10};
    Node* head = convertArrToLL(arr);
    head = deleteOcc(head, 10);
    printLL(head);
}