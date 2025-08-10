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

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root -> data){
        root -> right = insertIntoBST(root -> right, data);
    } else{
        root -> left = insertIntoBST(root -> left, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void findMinMax(Node* root){
    Node* temp = root;

    while(temp -> left)
        temp = temp -> left;
    cout << "Min: " << temp -> data << endl;

    temp = root;
    while(temp -> right)
        temp = temp -> right;
    cout << "Max: " << temp -> data << endl;
}

Node* minVal(Node* root){
    Node* temp = root;

    while(temp -> left)
        temp = temp -> left;
    return temp;
}

Node* deleteFromBST(Node* root, int val){
    if(root == NULL) return NULL;

    if(root -> data == val){
        //0 children
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        //right child
        if(root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        //2 children
        if(root -> left != NULL && root -> right != NULL){
            //step 1: find min value of right subtree
            int mini = minVal(root -> right) -> data;

            //step 2: replace value of root with min
            root -> data = mini;

            //step 3: delete node
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    } else if(root -> data > val){
        root -> left = deleteFromBST(root -> left, val);  
    } else{
        root -> right = deleteFromBST(root -> right, val);
    }
    return root;
}

int main(){
    Node* root = NULL;

    cout << "Enter data: " << endl;
    takeInput(root);

    // 50 20 70 10 30 90 110 -1
    root = deleteFromBST(root, 50);

    cout << "Printing BST..." << endl;
    levelOrderTraversal(root);
    // cout << "\n\n";

    // findMinMax(root);

    //TC- O(logN)
}