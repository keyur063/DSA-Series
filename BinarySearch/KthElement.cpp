#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k){
        int n1=a.size(), n2=b.size();
        if(n1 > n2) return kthElement(b, a, k); //smaller array first

        int low = max(0, k-n2); 
        int high = min(k, n1); //can take max k
        int left = k;
        int n = n1 + n2;

        while(low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;

            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
            if(mid1 >= 1) l1 = a[mid1-1];
            if(mid2 >= 1) l2 = b[mid2-1];

            if(l2 <= r1 && l1 <= r2)
                return max(l1, l2);
            else if(l1 > r2) high = mid1-1;
            else low = mid1+1;
        }
        return 0;
}

//TC- O(log(min(n1, n2)))

int main(){
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int>b = {1, 4, 8, 10};

    cout<<kthElement(a, b, 5)<<endl;
}