#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
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

class NodeValue{
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

Node* buildTreeFromLevelOrder(){
    // vector<int> values = {20, 15, 40, 14, 18, 30, 60, -1, 17, 16, 19, 50};
    vector<int> values = {2,1,3};
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

NodeValue helper(Node* root){
    if(!root) return NodeValue(INT_MAX, INT_MIN, 0); //size 0 for null tree

    auto left = helper(root->left);
    auto right = helper(root->right);

    if((left.maxNode < root->data) && (right.minNode > root->data))
        //is BST
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), 1 + left.maxSize + right.maxSize);

    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize)); //reinit min and max to opp extremes
}

int largestBSTSubtree(Node* root){
    return helper(root).maxSize;
}
//TC- O(N)
//SC- O(1) excl rec

int main(){
    Node* root = buildTreeFromLevelOrder();
    cout<<largestBSTSubtree(root)<<endl;
}