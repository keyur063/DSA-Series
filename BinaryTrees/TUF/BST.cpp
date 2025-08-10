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
    vector<int> values = {10, 5, 13, 3, 6, 11, 14, 2, 4, -1, 9};

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

int ceilBST(Node* root, int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(key > root->data){
            root = root->right;
        } else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int floorBST(Node* root, int key){
    int floor = -1;
    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }
        if(key > root->data){
            floor = root->data;
            root = root->right;
        } else{
            root = root->left;
        }
    }
    return floor;
}

int main(){
    Node* root = buildTreeFromLevelOrder();
    cout<<"Ceil: "<<ceilBST(root, 8)<<endl;
    cout<<"Floor: "<<floorBST(root, 7)<<endl;
}