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

bool isLeaf(Node* root){
    return !(root->left || root->right);
}

void addLeftBoundary(Node* root, vector<int> &ans){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaves(Node* root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, ans);
    if(root->right) addLeaves(root->right, ans);
}

void addRightBoundary(Node* root, vector<int> &ans){
    Node* curr = root->right;
    vector<int> temp; //O(H)
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for(int i=temp.size()-1; i>=0; --i){
        ans.push_back(temp[i]);
    }
}

vector<int> printBoundary(Node* root){
    vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);

    addLeftBoundary(root, ans); //O(H)
    addLeaves(root, ans); //O(N-2H)
    addRightBoundary(root, ans); //O(H)
    return ans;
}
//TC- O(N) traversal
//SC- O(N) temp if right skewed

int main(){
    Node* root;
    root = buildTree(root);

    // 1 2 3 -1 4 5 -1 -1 6 -1 -1 -1 7 -1 8 9 10 -1 -1 11 -1 -1 -1
    vector<int> ans = printBoundary(root);
    for(int val: ans)
        cout<<val<<" ";
    cout<<endl;
}