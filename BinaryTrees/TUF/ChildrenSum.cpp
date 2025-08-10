#include <iostream>
#include <queue>
#include <map>
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

Node* buildTreeFromLevelOrder() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

void changeTree(Node* root){
    if(!root) return;

    int child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;

    if(child >= root->data) root->data = child;
    else{ //update child nodes with root
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) root->data = total; //update root if non leaf node
}
//TC- O(N)
//SC- O(H)

vector<int> levelOrder(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        result.push_back(curr->data);

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return result;
}


int main(){
    Node* root;
    root = buildTreeFromLevelOrder();

    changeTree(root);
    vector<int> ans = levelOrder(root);
    
    for(int val: ans)
        cout<<val<<" ";
    cout<<endl;
}