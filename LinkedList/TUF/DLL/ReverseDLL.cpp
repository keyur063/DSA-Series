#include <iostream>
#include <vector>
#include <stack>
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
        prev = temp;
    }
    return head;
}

Node* bruteForce(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node* optimalSoln(Node* head) {
    if (!head || !head->next)
        return head;

    Node* curr = head;
    Node* prev1 = NULL;

    while (curr != NULL) {
        prev1 = curr->prev;
        curr->prev = curr->next;
        curr->next = prev1;
        curr = curr->prev;
    }
    return prev1;
}


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArrToLL(arr);

    // Node* reversedDLL = bruteForce(head);
    // cout<<reversedDLL->data<<endl;

    Node* reversedDLL = optimalSoln(head);
    cout<<reversedDLL->data<<endl;
}