#include <iostream>
using namespace std;

void sayDigits(int n, string arr[]){
    if(n==0) return;

    int digit = n%10;
    n /= 10;

    // cout << arr[digit] << " "; //two one four

    sayDigits(n, arr);

    cout << arr[digit] << " "; //four one two
}

int main(){
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int n;
    cin >> n;

    sayDigits(n, arr);
}