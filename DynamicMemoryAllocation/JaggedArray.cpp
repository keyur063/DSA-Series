#include <iostream>
using namespace std;

int main() {
    int rows;
    
    // Prompt the user to input the number of rows
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    // Declare an array of pointers
    int** jaggedArray = new int*[rows];
    
    // To store the number of elements in each row
    int* numElements = new int[rows];
    
    // For each row, ask the user for the number of elements and the elements themselves
    for (int i = 0; i < rows; i++) {
        cout << "Enter the number of elements in row " << i + 1 << ": ";
        cin >> numElements[i];  // Store the size of each row
        
        // Dynamically allocate memory for the row
        jaggedArray[i] = new int[numElements[i]];
        
        // Input the elements for this row
        cout << "Enter " << numElements[i] << " elements for row " << i + 1 << ": ";
        for (int j = 0; j < numElements[i]; j++) {
            cin >> jaggedArray[i][j];
        }
    }
    
    // Display the jagged array
    cout << "\nJagged array contents:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < numElements[i]; j++) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;
    delete[] numElements;

    return 0;
}
