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

Node* getTail(Node* head){
    if(!head) return NULL;

    Node* tail = head;
    while(tail->next)
        tail = tail->next;
    return tail;
}

vector<pair<int, int>> findPairs(Node* head, int k){
    vector<pair<int, int>> ans;
    Node* left = head;
    Node* right = getTail(head); //O(N)

    while(left->data < right->data){ //O(N)
        if(left->data + right->data == k){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if(left->data + right->data < k)
            left = left->next;
        else
            right = right->prev;
    }
    return ans;
}

int main(){
    vector<int> arr ={1,2,3,4,9}; //sorted
    Node* head = convertArrToLL(arr);

    vector<pair<int, int>> ans = findPairs(head, 5);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i].first<<","<<ans[i].second<<endl;
}