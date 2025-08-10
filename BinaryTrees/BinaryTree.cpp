#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root){
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1) return NULL;

    // cout << "Enter data for left of " << data << ": " << endl;
    root -> left = buildTree(root -> left);

    // cout << "Enter data for right of " << data << ": " << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } else{
            cout << temp -> data << " ";

            if(temp -> left) q.push(temp -> left);

            if(temp -> right) q.push(temp -> right);
        }
    }
}

void reverseLevelOrderTraversal(Node* root){
    if(root == NULL) return;

    stack<Node*> s;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            s.push(NULL);
            if(!q.empty()){
                q.push(NULL);
            }
        } else{
            s.push(temp);
            
            if(temp -> right) q.push(temp -> right);
            if(temp -> left) q.push(temp -> left);
        }
    }

    while(!s.empty()){
        Node* temp = s.top();
        s.pop();

        if(temp == NULL){
            cout << endl;
        } else{
            cout << temp -> data << " ";
        }
    }
}

void inOrderTraversal(Node* root){ //left node right
    if(root == NULL) return;

    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

//Traversal without recursion and stack(iterative way)
void morrisTraversal(Node* root){
    if(root == NULL) return;

    Node* curr = root;
    while(curr != NULL){
        if(curr -> left == NULL){
            cout << curr -> data << " ";
            curr = curr -> right;
        } else{
            Node* predecessor = curr -> left;
            while(predecessor -> right != NULL && predecessor -> right != curr){
                predecessor = predecessor -> right;
            }
            // or 
            // Node* predecessor = curr -> left -> right;

            if(predecessor -> right == NULL){
                    //create link betn pred and curr
                    predecessor -> right = curr;
                    curr = curr -> left;
                } else{
                    //delete link
                    predecessor -> right = NULL;
                    cout << curr -> data << " ";
                    curr = curr -> right;
                }
        }
    }
}

void preOrderTraversal(Node* root){ //node left right
    if(root == NULL) return;

    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(Node* root){ //left right node
    if(root == NULL) return;

    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}

void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp -> data << ": " << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for " << temp -> data << ": " << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}

int main(){
    Node* root;
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Printing Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    // cout << "\n";

    // cout << "Printing In Order Traversal: ";
    // inOrderTraversal(root);
    // cout << "\n\n";

    // cout << "Printing Morris Traversal: ";
    // morrisTraversal(root);

    // cout << "Printing Pre Order Traversal: ";
    // preOrderTraversal(root);
    // cout << "\n\n";

    // cout << "Printing Post Order Traversal: ";
    // postOrderTraversal(root);

    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);

    // cout << "Printing Reverse Level Order Traversal: " << endl;
    // reverseLevelOrderTraversal(root);
}