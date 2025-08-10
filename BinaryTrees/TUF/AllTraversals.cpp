#include <iostream>
#include <queue>
#include <stack>
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

Node* buildTree(Node* root){
    cout<<"Enter data: "<< endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1) return NULL;

    root->left = buildTree(root -> left);
    root->right = buildTree(root -> right);

    return root;
}

vector<vector<int>> traversals(Node* root){
    vector<vector<int>> traversals;
    vector<int> pre, in, post;
    stack<pair<Node*, int>> s;

    s.push({root, 1});
    if(root == NULL) return traversals;

    while(!s.empty()){
        auto it = s.top();
        s.pop();

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);

            if(it.first->left)
                s.push({it.first->left, 1});
        } 
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);

            if(it.first->right)
                s.push({it.first->right, 1});
        } 
        else{
            post.push_back(it.first->data);
        }
    }

    traversals.push_back(pre);
    traversals.push_back(in);
    traversals.push_back(post);
    return traversals;
}
//TC- O(3N)
//SC- O(N^3)

int main(){
    Node* root;
    root = buildTree(root);

    // 1 2 3 -1 4 5 -1 -1 6 -1 -1 7 -1 8 9 -1 
    vector<vector<int>> ans = traversals(root);
    for(auto row: ans){
        for(int val: row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}