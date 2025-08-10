#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTreeFromLevelOrder(){
    vector<int> values = {5, 2, 7, 1, 4, 6, 9, -1, -1, 3, -1, -1, -1, 8, 10};

    if (values.empty() || values[0] == -1) return NULL;

    Node* root = new Node(values[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;  
    while (!q.empty() && i<values.size()) {
        Node* curr = q.front();
        q.pop();

        if (i<values.size() && values[i] != -1) {
            curr->left = new Node(values[i]);
            q.push(curr->left);
        }
        i++;

        if (i<values.size() && values[i] != -1) {
            curr->right = new Node(values[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

Node* inorderSuccessor(Node* root, Node* p){
    Node* succ = NULL;

    while(root){
        if(p->data >= root->data)
            root = root->right;
        else{
            succ = root;
            root = root->left;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* p){
    Node* pred = NULL;

    while(root){
        if(p->data <= root->data)
            root = root->left;
        else{
            pred = root;
            root = root->right;
        }
    }
    return pred;
}
//TC- O(h) ~ O(logN)
//SC- O(1)

int main(){
    Node* root = buildTreeFromLevelOrder();
    cout<<"Successor: "<<inorderSuccessor(root, root->right->left)->data<<endl;
    cout<<"Predecessor: "<<inorderPredecessor(root, root->right->left)->data<<endl;
}