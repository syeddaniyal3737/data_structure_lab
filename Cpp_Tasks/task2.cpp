#include <iostream>
using namespace std;

int main() {

    // 1. Create and initialize the 2D parking array
    int parking[4][5] = {
        {1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0}
    };

    int occupied = 0;
    int empty = 0;

    // 2. Display the complete parking layout
    cout << "===== PARKING LAYOUT =====" << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << parking[i][j] << " ";

            // 3. Count occupied spaces
            if (parking[i][j] == 1) {
                occupied++;
            }
            // 4. Count empty spaces
            else {
                empty++;
            }
        }
        cout << endl;
    }

    // Display occupied and empty spaces
    cout << "\nTotal occupied spaces: " << occupied << endl;
    cout << "Total empty spaces: " << empty << endl;

    // 5. Ask user for row and column
    int row, column;

    cout << "\nEnter row number (1-4): ";
    cin >> row;

    cout << "Enter column number (1-5): ";
    cin >> column;

    // Convert user input to array index
    row--;
    column--;

    // 6. Check selected parking space
    if (parking[row][column] == 0) {
        cout << "\nThe selected parking space is AVAILABLE." << endl;
    }
    else {
        cout << "\nThe selected parking space is OCCUPIED." << endl;
    }

    // 7. Display total capacity and current occupancy
    int totalCapacity = 4 * 5;

    cout << "\n===== PARKING INFORMATION =====" << endl;
    cout << "Total parking capacity: " << totalCapacity << endl;
    cout << "Current occupancy: " << occupied << endl;
    cout << "Available spaces: " << empty << endl;

    return 0;
}
