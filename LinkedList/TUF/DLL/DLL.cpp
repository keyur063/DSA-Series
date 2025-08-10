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
    for(int i=0; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArrToLL(arr);
}