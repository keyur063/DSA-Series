#include <iostream>
#include <vector>
#include <unordered_map>
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

int getLoopLen(Node* head){ //TC- O(N*1) unordered_map -> O(1)
    unordered_map<Node*, int> m;
    Node* temp = head;
    int timer = 1;

    while(temp){
        if(m.find(temp) != m.end()){
            int val = m[temp];
            return timer-val;
        }
        m[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

//optimal approach
int getLenOptimal(Node* head){ //O(N)
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            int len = 1;
            fast = fast->next;
            while(slow != fast){
                len++;
                fast = fast->next;
            }
            return len;
        }          
    }
    return 0;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;  // Loop created at node 3

    Node* head = n1;
    cout<<getLoopLen(head)<<endl;
    cout<<getLenOptimal(head)<<endl;
}