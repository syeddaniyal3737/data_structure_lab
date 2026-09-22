#include <iostream>
using namespace std;

int main() {

    // Matrix A
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Matrix B
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    // Display Matrix A
    cout << "Matrix A:" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Display Matrix B
    cout << "\nMatrix B:" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    // Calculate and display sum
    cout << "\nSum of Matrix A and B:" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
