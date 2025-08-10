#include <iostream>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;

    Heap(){
        size = 0;
        arr[0] = -1;
    }
    
    void insertInHeap(int val){ //TC- O(logn)
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            } else{
                return;
            }
        }
    }

    void printHeap(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        } cout << endl;
    }

    void deleteFromHeap(){ //TC- O(logn)
        if(size == 0){
            cout << "No element to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        //relocate root node to its correct position
        int i = 1;
        while (i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else{
                return;
            }
        }
        
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;

    while(size > 1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main(){
    Heap h;
    // h.insertInHeap(50);
    // h.insertInHeap(55);
    // h.insertInHeap(53);
    // h.insertInHeap(52);
    // h.insertInHeap(54);
    // h.printHeap();

    // h.deleteFromHeap();
    // h.printHeap();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    //heap creation
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout << "Printing array in heap order: " << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    } cout << endl;

    heapSort(arr, n);

    cout << "Printing array in sorted order: " << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    } cout << endl;

}