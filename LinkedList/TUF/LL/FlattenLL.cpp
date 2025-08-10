#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    Node(int data1){ 
        data = data1;
        next = NULL;
        child = NULL;
    }

    Node(int data1, Node* next1, Node* child1){ 
        data = data1;
        next = next1;
        child = child1;
    }
};

void printByLevels(Node* head) {
    if (!head) return;

    queue<Node*> q;
    q.push(head);
    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        cout << "Level " << level++ << ": ";

        for (int i = 0; i < size; ++i) {
            Node* curr = q.front(); q.pop();

            while (curr) {
                cout << curr->data << " ";
                if (curr->child)
                    q.push(curr->child);
                curr = curr->next;
            }
        }
        cout << endl;
    }
}

void printLL(Node* head) {
    while(head){
        cout<<head->data<<" ";
        head = head->child;
    }
    cout<<endl;
}

Node* convertToLL(vector<int> arr){
    if(arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        temp->child = newNode;
        temp = temp->child;
    }
    return head;
}

Node* bruteForce(Node* head){
    Node* temp = head;
    vector<int> arr;

    while(temp){ //O(N)
        Node* t2 = temp;
        while(t2){ //O(M)
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end()); //O((N*M)log(N*M))
    head = convertToLL(arr); //O(N*M)

    return head;
}
//TC- 2*O(X) + O(XlogX) X=N*M
//SC- 2*O(X) arr+LL

Node* merge2Lists(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(list1 && list2){ //O(2M)
        if(list1->data < list2->data){
            temp->child = list1;
            temp = list1;
            list1 = list1->child;
        } else{
            temp->child = list2;
            temp = list2;
            list2 = list2->child;
        }
        temp->next = NULL;
    }

    if(list1) temp->child = list1;
    if(list2) temp->child = list2;

    if(dummyNode->child) dummyNode->child->next = NULL;
    return dummyNode->child;
}

Node* optimalSoln(Node* head){
    if(!head || !head->next)
        return head;

    Node* mergedHead = optimalSoln(head->next); //O(N)
    return merge2Lists(head, mergedHead);
}
//TC- O(2*N*M)
//SC- O(N) recursive space

int main(){
    Node* n1 = new Node(3);
    Node* n2 = new Node(2);
    Node* n3 = new Node(1);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(10);
    Node* n7 = new Node(7);
    Node* n8 = new Node(9);
    Node* n9 = new Node(6);
    Node* n10 = new Node(11);
    Node* n11 = new Node(8);
    Node* n12 = new Node(12);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    
    n2->child = n6;
    n3->child = n7;
    n7->child = n10;
    n10->child = n12;
    n4->child = n8;
    n5->child = n9;
    n9->child = n11;

    // printByLevels(n1);

    // Node* head = bruteForce(n1);
    Node* head = optimalSoln(n1);
    printLL(head);
}