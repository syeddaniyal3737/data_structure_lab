#include <iostream>
using namespace std;

const int SIZE = 5;

// Fixed-size circular array implementation of a double-ended queue (deque).
class Deque {
private:
    int requests[SIZE];
    int front;
    int rear;
    int count;

public:
    Deque() : front(0), rear(-1), count(0) {}

    // Insert a passenger request at the front end.
    void insertFront(int requestId) {
        if (count == SIZE) {
            cout << "Deque full: cannot insert request.\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }

        requests[front] = requestId;
        ++count;
        cout << "Request " << requestId << " inserted at front.\n";
    }

    // Insert a passenger request at the rear end.
    void insertRear(int requestId) {
        if (count == SIZE) {
            cout << "Deque full: cannot insert request.\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        requests[rear] = requestId;
        ++count;
        cout << "Request " << requestId << " inserted at rear.\n";
    }

    // Remove the request at the front end.
    void removeFront() {
        if (count == 0) {
            cout << "Deque empty: nothing to remove.\n";
            return;
        }

        cout << "Removed request " << requests[front]
             << " from front.\n";
        front = (front + 1) % SIZE;
        --count;

        if (count == 0) {
            front = 0;
            rear = -1;
        }
    }

    // Remove the request at the rear end.
    void removeRear() {
        if (count == 0) {
            cout << "Deque empty: nothing to remove.\n";
            return;
        }

        cout << "Removed request " << requests[rear]
             << " from rear.\n";
        rear = (rear - 1 + SIZE) % SIZE;
        --count;

        if (count == 0) {
            front = 0;
            rear = -1;
        }
    }

    // Display requests in order from front to rear.
    void display() const {
        if (count == 0) {
            cout << "No passenger requests waiting.\n";
            return;
        }

        cout << "Requests (front to rear): ";
        for (int i = 0; i < count; ++i) {
            cout << requests[(front + i) % SIZE] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    Deque deque;
    int choice, requestId;

    do {
        cout << "\n--- Train Station Passenger Management ---\n"
             << "1. Insert at front\n"
             << "2. Insert at rear\n"
             << "3. Remove from front\n"
             << "4. Remove from rear\n"
             << "5. Display requests\n"
             << "6. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter request ID: ";
                cin >> requestId;
                deque.insertFront(requestId);
                break;
            case 2:
                cout << "Enter request ID: ";
                cin >> requestId;
                deque.insertRear(requestId);
                break;
            case 3:
                deque.removeFront();
                break;
            case 4:
                deque.removeRear();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
