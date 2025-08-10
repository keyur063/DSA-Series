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

vector<int> topView(Node* root){
    vector<int> ans;
    if(!root) return ans;
    map<int, int> m; //hd, node val

    queue<pair<Node*, int>> q; //node, hd
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int line = it.second;
        if(m.find(line) == m.end()) m[line] = node->data; //store 1st occ

        if(node->left) q.push({node->left, line-1});
        if(node->right) q.push({node->right, line+1});
    }

    for(auto it: m)
        ans.push_back(it.second);
    return ans;
}

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(!root) return ans;
    map<int, int> m; //hd, node val

    queue<pair<Node*, int>> q; //node, hd
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int line = it.second;
        m[line] = node->data; //store last occ

        if(node->left) q.push({node->left, line-1});
        if(node->right) q.push({node->right, line+1});
    }

    for(auto it: m)
        ans.push_back(it.second);
    return ans;
}
//TC- O(N)
//SC- O(2N)

int main(){
    Node* root;
    root = buildTree(root);

    // 1 2 3 -1 4 5 -1 -1 6 -1 -1 -1 7 -1 8 9 10 -1 -1 11 -1 -1 -1
    // vector<int> ans = topView(root);
    vector<int> ans = bottomView(root);
    for(int val: ans)
        cout<<val<<" ";
    cout<<endl;
}