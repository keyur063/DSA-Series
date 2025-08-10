#include <iostream>
using namespace std;

class kQueue{
    public:
        int *arr, *front, *rear, *next;
        int n, k, freeSpot;

    public:
        kQueue(int n, int k){
            this -> n = n;
            this -> k = k;
            arr = new int[n];

            front = new int[k];
            rear = new int[k];  
            for(int i=0; i<k; i++){
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n-1; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;

            freeSpot = 0;
        }

        void enqueue(int data, int qn){
            //overflow
            if(freeSpot == -1){
                cout << "No empty space is present" << endl;
                return;
            }

            //find first free index
            int index = freeSpot;

            //update freespot
            freeSpot = next[index];

            //check whether first element
            if(front[qn-1] == -1){ //zero indexing
                front[qn-1] = index;
            } else{
                //link new element to prev element
                next[rear[qn-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //insert element
            arr[index] = data;
        }

        int dequeue(int qn){
            //underflow
            if(front[qn-1] == -1){
                cout << "Queue is empty" << endl;
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //increment front
            front[qn-1] = next[index];

            //update freespot
            next[index] = freeSpot;

            //freespot to popped index
            freeSpot = index;

            return arr[index];
        }
};

int main(){
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 2);
    q.enqueue(30, 3);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(3) << endl;
}