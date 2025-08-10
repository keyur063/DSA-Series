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
    for(int i=0; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool isPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArrToLL(arr);
    cout<<head->data<<endl;
    cout<<lengthLL(head)<<endl;
    cout<<isPresent(head, 6)<<" "<<isPresent(head, 8)<<endl;
}