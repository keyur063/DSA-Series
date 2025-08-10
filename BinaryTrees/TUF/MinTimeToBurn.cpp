#include <iostream>
#include <queue>
#include <unordered_map>
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
    vector<int> values = {1, 2, 3, 4, -1, 5, 6, -1, 7};

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

void markParents(Node* root, unordered_map<Node*, Node*> &parent_track){
    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node* curr = q.front();
        q.pop();

        if (curr->left){
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right){
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

int minTime(Node* root, Node* target){
    unordered_map<Node*, Node*> parent_track;
    markParents(root, parent_track);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int maxi = 0;

    while(!q.empty()){
        int size = q.size();
        int burn = 0; //increment time if node is burnt (bool func)

        for(int i=0; i<size; i++){
            Node* curr = q.front();
            q.pop();

            if(curr->left && !visited[curr->left]){
                burn = 1; //node is burnt
                q.push(curr->left);
                visited[curr->left] = true;
            }

            if(curr->right && !visited[curr->right]){
                burn = 1;
                q.push(curr->right);
                visited[curr->right] = true;
            }

            if(parent_track[curr] && !visited[parent_track[curr]]){ //check parent
                burn = 1;
                q.push(parent_track[curr]);
                visited[parent_track[curr]] = true;
            }
        }
        if(burn) maxi++;
    }
    return maxi;
}
//TC- O(N) + O(N) + O(map)
//SC~ O(N)

int main(){
    Node* root;
    root = buildTreeFromLevelOrder();
    // 1 2 3 4 -1 5 6 -1 7 -1 -1 -1 

    cout<<minTime(root, root->left)<<endl;
}