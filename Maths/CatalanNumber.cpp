#include <iostream>
#include <vector>
using namespace std;

int catalan(int n) {
    vector<int> catalanNumbers(n + 1, 0);
    catalanNumbers[0] = catalanNumbers[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalanNumbers[i] += catalanNumbers[j] * catalanNumbers[i - j - 1];
        }
    }

    return catalanNumbers[n];
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Catalan number C(" << n << ") = " << catalan(n) << endl;
    return 0;
}
