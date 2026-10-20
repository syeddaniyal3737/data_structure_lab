#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

struct Patient {
    string id;
    int priority;
};

// Array-based priority queue. A smaller priority number means higher urgency.
class PriorityQueue {
private:
    Patient patients[SIZE];
    int count;

public:
    PriorityQueue() : count(0) {}

    // Add a patient and keep the array ordered by priority.
    void insert(const string& id, int priority) {
        if (count == SIZE) {
            cout << "Queue full: cannot add another patient.\n";
            return;
        }

        Patient newPatient{id, priority};
        int i = count - 1;

        // Shift lower-urgency patients right to make room.
        // Use '>' so patients with equal priority keep arrival order.
        while (i >= 0 && patients[i].priority > priority) {
            patients[i + 1] = patients[i];
            --i;
        }

        patients[i + 1] = newPatient;
        ++count;
        cout << "Patient " << id << " added with priority "
             << priority << ".\n";
    }

    // Treat the patient with the highest urgency (smallest priority number).
    void treatNext() {
        if (count == 0) {
            cout << "Queue empty: no patients waiting.\n";
            return;
        }

        cout << "Treating patient " << patients[0].id
             << " (priority " << patients[0].priority << ").\n";

        // Shift remaining patients left after removing the first patient.
        for (int i = 1; i < count; ++i) {
            patients[i - 1] = patients[i];
        }
        --count;
    }

    // Display all waiting patients in treatment order.
    void display() const {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "Waiting patients (ID, priority):\n";
        for (int i = 0; i < count; ++i) {
            cout << patients[i].id << ", "
                 << patients[i].priority << '\n';
        }
    }
};

int main() {
    PriorityQueue queue;
    int choice, priority;
    string id;

    do {
        cout << "\n--- Hospital Emergency Department ---\n"
             << "1. Add patient\n"
             << "2. Treat highest-priority patient\n"
             << "3. Display waiting patients\n"
             << "4. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter patient ID: ";
                cin >> id;
                cout << "Enter priority (1 = highest urgency): ";
                cin >> priority;
                if (priority < 1) {
                    cout << "Priority must be 1 or greater.\n";
                } else {
                    queue.insert(id, priority);
                }
                break;
            case 2:
                queue.treatNext();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
