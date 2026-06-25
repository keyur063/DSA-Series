#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (pair<int, string> &a, pair<int, string> &b) {
        if(a.first != b.first) return a.first > b.first; // min heap based on int
        return a.second > b.second; // min heap based on string
    }
};

int main() {
    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
    return 0;
}