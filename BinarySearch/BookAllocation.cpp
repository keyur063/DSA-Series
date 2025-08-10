#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxPagesAllowed){
    int studentNum=1, pages=0;
    for(int i=0; i<n; i++){
        if(arr[i] > maxPagesAllowed) return false;

        if(pages + arr[i] <= maxPagesAllowed)
            pages += arr[i];
        else{
            studentNum++;
            pages = arr[i];
        }
    }
    return studentNum > m ? false: true;
}

//n-no. of books, m-no.of students
int allocateBooks(vector<int> &arr, int n, int m){
    if(m > n) return -1;

    int sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int st=0, end=sum; //Range of possible ans
    while(st<=end){
        int mid = st + (end-st)/2;

        if(isValid(arr, n, m, mid)) //left
            end = mid-1;
        else //right
            st = mid+1;
    }
    return st;
}

int main(){
    vector<int> arr1 = {2, 1, 3, 4};
    vector<int> arr2 = {15, 17, 20};
    vector<int> arr3 = {27, 31, 44, 39};

    cout<<allocateBooks(arr1, 4, 2)<<endl;
    cout<<allocateBooks(arr2, 3, 2)<<endl;
    cout<<allocateBooks(arr3, 4, 3)<<endl;
    return 0;
}