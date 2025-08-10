#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& arr, vector<int>& tempArr, int left, int mid, int right) {
    int i = left;     // Starting index for left subarray
    int j = mid + 1;  // Starting index for right subarray
    int k = left;     // Starting index to be sorted
    int invCount = 0;

    // Merge the two halves while counting inversions
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tempArr[k++] = arr[i++];
        } else {
            tempArr[k++] = arr[j++];
            invCount += (mid - i + 1);  // Count inversions
        }
    }

    while (i <= mid) {
        tempArr[k++] = arr[i++];
    }

    while (j <= right) {
        tempArr[k++] = arr[j++];
    }
 
    for (int i = left; i <= right; i++) {
        arr[i] = tempArr[i];
    }

    return invCount;
}

int mergeSortAndCount(vector<int>& arr, vector<int>& tempArr, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, tempArr, left, mid);
        invCount += mergeSortAndCount(arr, tempArr, mid + 1, right);

        invCount += mergeAndCount(arr, tempArr, left, mid, right);
    }
    return invCount;
}

int countInversions(vector<int>& arr) {
    vector<int> tempArr(arr.size());
    return mergeSortAndCount(arr, tempArr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};
    cout << "Number of inversions are: " << countInversions(arr) << endl;
    return 0;
}
