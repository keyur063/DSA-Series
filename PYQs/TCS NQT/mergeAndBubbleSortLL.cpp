#include<iostream>
#include<vector>
using namespace std;

/*
    Merge 2 LL alternately until one list finishes.
    Sort even positioned elements using Bubble Sort.

    1. Create LL structure
    2. Insert into LL
    3. Alternate Merge Function
    4. Bubble Sort
*/

struct Node {
public:
    int data;
    Node* next = NULL;

    Node(int x) {
        this->data = x;
        this->next = NULL;
    }
};

void insert(Node* &head, int x) {
    if(!head) {
        head = new Node(x);
        return;
    }

    Node* temp = head;
    while(temp->next)
        temp = temp->next;

    temp->next = new Node(x);
}

Node* mergeAlternate(Node* a, Node* b) {
    Node dummy(-1);
    Node* tail = &dummy;

    while(a && b) {
        tail->next = a;
        a = a->next;
        tail = tail->next;

        tail->next = b;
        b = b->next;
        tail = tail->next;
    }

    tail->next = a ? a : b;
    return dummy.next;
}

void sortEven(Node* head) {
    vector<Node*> evenNodes;
    int pos = 1;
    Node* temp = head;

    while(temp) {
        if(pos % 2 == 0)
            evenNodes.push_back(temp);

        temp = temp->next;
        pos++;
    }

    int n = evenNodes.size();

    // Bubble Sort
    for(int i=n-1; i>0; i--) {
        bool isSwap = false;

        for(int j=0; j<i; j++) {
            if(evenNodes[j]->data > evenNodes[j+1]->data){
                swap(evenNodes[j]->data, evenNodes[j+1]->data);
                isSwap = true;
            }
        }
        if(!isSwap) return; // all sorted 
    }
}

void print(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n1, n2, x;
    Node* list1 = NULL;
    Node* list2 = NULL;

    cin >> n1;
    while(n1--) {
        cin >> x;
        insert(list1, x);
    }

    cin >> n2;
    while(n2--) {
        cin >> x;
        insert(list2, x);
    }

    Node* merged = mergeAlternate(list1, list2);
    sortEven(merged);
    print(merged);

    return 0;
}