#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> // for setprecision
using namespace std;

// Minimise maximum distance between gas stations

long double bruteForce(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> gasStnPlaced(n-1, 0);

    for (int gs=1; gs<=k; gs++) {
        long double maxSection = -1;
        int maxIdx = -1;

        for (int i=0; i<n-1; i++) {
            long double diff = arr[i+1] - arr[i];
            long double sectionLen = diff / (long double)(gasStnPlaced[i] + 1);

            if (sectionLen > maxSection) {
                maxSection = sectionLen;
                maxIdx = i;
            }
        }
        gasStnPlaced[maxIdx]++;
    }

    long double maxAns = -1;
    for (int i=0;  i<n - 1; i++) {
        long double diff = arr[i+1] - arr[i];
        long double sectionLen = diff / (long double)(gasStnPlaced[i] + 1);
        maxAns = max(maxAns, sectionLen);
    }
    return maxAns;
}

long double betterSoln(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> gasStnPlaced(n-1, 0);
    priority_queue<pair<long double, int>> pq;

    for(int i=0; i<n-1; i++)
        pq.push({arr[i+1] - arr[i], i});

    for(int gs=1; gs<=k; gs++){
        auto top = pq.top();
        pq.pop();

        int secIdx = top.second;
        gasStnPlaced[secIdx]++;

        long double initDiff = arr[secIdx+1] - arr[secIdx];
        long double newSecLen = initDiff / (long double)(gasStnPlaced[secIdx] + 1);

        pq.push({newSecLen, secIdx});
    }
    return pq.top().first;
}

int gasStnReq(vector<int>& arr, long double dist){
    int cnt = 0;
    for(int i=1; i<arr.size(); i++){
        int numInBetween = (arr[i] - arr[i-1]) / dist;

        if((arr[i] - arr[i-1]) / dist == numInBetween * dist) //if int then int-1
            numInBetween--;

        cnt += numInBetween;
    }
    return cnt;
}

long double optimalSoln(vector<int>& arr, int k){
    int n = arr.size();

    long double low=0, high=0;
    for (int i=0; i<arr.size()-1; i++)
        high = max(high, (long double)(arr[i+1] - arr[i]));
    
    while(high - low > 1e-6){
        long double mid = low + (high-low) / 2.0;
        int cnt = gasStnReq(arr, mid);

        if(cnt > k) //mid is too small as many stn are added
            low = mid;
        else
            high = mid;
    }
    return high;
}

int main(){
    vector<int> arr = {1, 13, 17, 23};
    // cout << fixed << setprecision(6) << bruteForce(arr, 5) << endl;
    // cout << fixed << setprecision(6) << betterSoln(arr, 5) << endl;
    cout << fixed << setprecision(6) << optimalSoln(arr, 5) << endl;
}