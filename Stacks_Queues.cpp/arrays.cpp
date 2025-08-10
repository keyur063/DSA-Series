#include<iostream>
using namespace std;

class Stack{
public:
    int *arr;
    int top;
    int size;

    Stack(int n){
        size = n;
        top = -1;
        arr = new int[size];
    }

    void push(int x){
        if(top < size-1){
            top++;
            arr[top] = x;
            cout<<"Push Successful"<<endl;
        } else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    int pop(){
        if(top >= 0){
            int x = arr[top];
            top--;
            return x;
        } else{
            cout<<"Stack Underflow ";
            return -1;
        }           
    }

    int peek(){
        if(top == -1){
            cout<<"Stack is Empty ";
            return -1;
        }
        return arr[top];           
    }

    int currSize(){
        return top + 1;
    }

    bool isEmpty(){
        return (top == -1);
    }

    ~Stack() {
        delete[] arr;
    }
}; 
//TC- O(1)
//SC- O(fixed size)

class Queue{
public:
    int *arr;
    int start, end;
    int currSize, maxSize;

    Queue(int n){
        start = end = -1;
        currSize = 0;
        maxSize = n;
        arr = new int[maxSize];
    }

    void push(int x){
        if(currSize == maxSize){
            cout<<"Queue is Full"<<endl;
            return;
        }
        
        if(end == -1) start = end = 0;
        else end = (end+1) % maxSize;

        arr[end] = x;
        currSize++;
        cout<<"Push Successful"<<endl;
    }

    int pop(){
        if(start == -1){
            cout<<"Queue is Empty ";
            return -1;
        }
            
        int x = arr[start];
        if(currSize == 1) start = end = -1;
        else start = (start+1) % maxSize;

        currSize--;
        return x;
    }

    int top(){
        if(start == -1){
            cout<<"Queue is Empty ";
            return -1;
        }
        return arr[start];           
    }

    int size(){
        return currSize;
    }

    bool isEmpty(){
        return (start == -1);
    }

    ~Queue() {
        delete[] arr;
    }
};

int main(){
    // Stack s(4);
    // s.push(1);
    // cout<<s.currSize()<<endl;
    // cout<<s.peek()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.isEmpty()<<endl;
    // cout<<s.peek()<<endl;

    Queue q(3);
    q.push(1);
    cout<<q.pop()<<endl;
    cout<<q.top()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.size()<<endl;
    q.push(2);
    cout<<q.size()<<endl;
    cout<<q.isEmpty()<<endl;
}