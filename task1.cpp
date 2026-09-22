#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 2D array: 6 students x 4 subjects
    int marks[6][4] = {
        {85, 90, 78, 88},
        {76, 82, 91, 80},
        {92, 88, 95, 90},
        {68, 75, 70, 72},
        {89, 94, 86, 91},
        {80, 79, 84, 87}
    };

    string subjects[4] = {
        "English", "Mathematics", "Programming", "AI"
    };

    // 1 & 2. Display complete marks table
    cout << "========== MARKS TABLE ==========\n\n";

    cout << left << setw(12) << "Student";

    for (int j = 0; j < 4; j++) {
        cout << setw(15) << subjects[j];
    }

    cout << endl;

    for (int i = 0; i < 6; i++) {
        cout << left << setw(12) << "Student " + to_string(i + 1);

        for (int j = 0; j < 4; j++) {
            cout << setw(15) << marks[i][j];
        }

        cout << endl;
    }

    // 3 & 4. Calculate total and average of each student
    cout << "\n========== TOTAL & AVERAGE ==========\n\n";

    cout << left << setw(12) << "Student"
         << setw(12) << "Total"
         << setw(12) << "Average" << endl;

    int highestTotal = 0;
    int highestStudent = 0;

    for (int i = 0; i < 6; i++) {
        int total = 0;

        for (int j = 0; j < 4; j++) {
            total += marks[i][j];
        }

        double average = total / 4.0;

        cout << left << setw(12) << "Student " + to_string(i + 1)
             << setw(12) << total
             << setw(12) << fixed << setprecision(2) << average
             << endl;

        // Find student with highest total
        if (total > highestTotal) {
            highestTotal = total;
            highestStudent = i;
        }
    }

    // 5. Find highest marks in each subject
    cout << "\n========== HIGHEST MARKS ==========\n\n";

    for (int j = 0; j < 4; j++) {
        int highest = marks[0][j];

        for (int i = 1; i < 6; i++) {
            if (marks[i][j] > highest) {
                highest = marks[i][j];
            }
        }

        cout << subjects[j] << ": " << highest << endl;
    }

    // 6. Display student with highest total
    cout << "\n========== HIGHEST TOTAL ==========\n\n";

    cout << "Student " << highestStudent + 1
         << " has the highest total marks: "
         << highestTotal << endl;

    return 0;
}
