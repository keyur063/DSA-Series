#include <iostream>
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

bool getPath(Node* root, vector<int>& ans, int key){
    if(!root) return false;
    ans.push_back(root->data);

    if(root->data == key || getPath(root->left, ans, key) || getPath(root->right, ans, key)) return true;

    ans.pop_back(); //pop if wrong path
    return false;
}

vector<int> printPath(Node* root, int key){
    vector<int> ans;
    if(!root) return ans;
    getPath(root, ans, key);
    return ans;
}
//TC- O(N)
//SC- O(H)

int main(){
    Node* root = buildTree(root);
    // 1 2 3 -1 4 5 -1 -1 6 -1 -1 -1 7 -1 8 9 10 -1 -1 11 -1 -1 -1
    vector<int> ans = printPath(root, 10);
    for(int val: ans)
        cout<<val<<" ";
    cout<<endl;
}