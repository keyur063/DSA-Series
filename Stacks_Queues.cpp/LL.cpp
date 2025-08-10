#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

class Stack{
public:
    Node* top;
    int size;

    Stack(){
        top = NULL;
        size = 0;
    }

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
        cout<<"Push Successful"<<endl;
    }

    int pop(){
        if(!top){
            cout<<"Stack is Empty ";
            return -1;
        }

        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return x;
    }

    int peek(){
        if(!top){
            cout<<"Stack is Empty ";
            return -1;
        }
        return top->data;
    }

    int currSize(){
        return size;
    }

    bool isEmpty(){
        return (!top);
    }
};
//TC- O(1)
//SC- O(dynamic size)

class Queue{
public:
    Node* front;
    Node* rear;
    int size;
    
    Queue(){
        front = rear = NULL;
        size = 0;
    }

    void push(int x){
        Node* temp = new Node(x);

        if(!front){
            front = rear = temp;
        } else{
            rear->next = temp;
            rear = temp;
        }

        size++;
        cout<<"Push Successful"<<endl;
    }

    int pop(){
        if(!front){
            cout<<"Queue is Empty ";
            return -1;
        }

        int x = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        return x;
    }

    int peek(){
        if(!front){
            cout<<"Stack is Empty ";
            return -1;
        }
        return front->data;
    }

    int currSize(){
        return size;
    }

    bool isEmpty(){
        return (!front);
    }
};

int main(){
    // Stack s;
    // s.push(1);
    // s.push(2);
    // cout<<s.peek()<<endl;
    // cout<<s.currSize()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.currSize()<<endl;
    // cout<<s.isEmpty()<<endl;

    Queue q;
    q.push(1);
    q.push(2);
    cout<<q.peek()<<endl;
    cout<<q.currSize()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.currSize()<<endl;
    cout<<q.isEmpty()<<endl;
}