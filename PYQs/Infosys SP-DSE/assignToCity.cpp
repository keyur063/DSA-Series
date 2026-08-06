#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;

/*
    2N employees have to travel to cities A and B.
    For each ith employee, cost of travelling to:
        city A = A[i]
        city B = min(A[i], B[i]) + B[i] via a transit hub
    Find minimum travel cost while ensuring exactly N employees are assigned to each city.

    1 <= N, A[i], B[i] <= 1e5
*/

int main() {
    int N;
    cin >> N;

    int total = 2 * N;
    vector<int> A(total), B(total);
    for(int i=0; i<total; i++)
        cin >> A[i];

    for(int i=0; i<total; i++)
        cin >> B[i];

    vector<int> costDiff(total);
    LL minCost = 0;

    // send all employees to A
    for(int i=0; i<total; i++) {
        minCost += A[i];
        int cityBcost = min(A[i], B[i]) + B[i];
        costDiff[i] = cityBcost - A[i];
    }

    sort(costDiff.begin(), costDiff.end());
    
    // send N employees with min cost diff to B
    for(int i=0; i<N; i++)
        minCost += costDiff[i];

    cout << minCost;
    return 0;
}