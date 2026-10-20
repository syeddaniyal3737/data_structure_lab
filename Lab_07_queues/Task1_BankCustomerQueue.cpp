#include <iostream>
using namespace std;

const int SIZE = 5;

// Simple linear queue for bank customer token numbers.
class LinearQueue {
private:
    int customers[SIZE];
    int front;
    int rear;

public:
    LinearQueue() : front(-1), rear(-1) {}

    // Add a customer at the rear of the queue.
    void enqueue(int token) {
        // In a linear queue, rear cannot move past the last array index.
        if (rear == SIZE - 1) {
            cout << "Queue overflow: no space available.\n";
            return;
        }

        // Set front when inserting the first customer.
        if (front == -1) {
            front = 0;
        }

        customers[++rear] = token;
        cout << "Customer " << token << " added.\n";
    }

    // Serve and remove the customer at the front.
    void dequeue() {
        if (front == -1) {
            cout << "Queue underflow: no customers waiting.\n";
            return;
        }

        cout << "Serving customer " << customers[front] << ".\n";

        // Reset the queue when its last customer is served.
        if (front == rear) {
            front = rear = -1;
        } else {
            ++front;
        }
    }

    // Display customers in first-in, first-out order.
    void display() const {
        if (front == -1) {
            cout << "No customers waiting.\n";
            return;
        }

        cout << "Waiting customers: ";
        for (int i = front; i <= rear; ++i) {
            cout << customers[i] << ' ';
        }
        cout << '\n';
    }

    // Report how many customers are waiting.
    void countCustomers() const {
        cout << "Number of waiting customers: ";
        if (front == -1) {
            cout << 0 << '\n';
        } else {
            cout << rear - front + 1 << '\n';
        }
    }
};

int main() {
    LinearQueue queue;
    int choice, token;

    do {
        cout << "\n--- Bank Customer Service ---\n"
             << "1. Add customer (enqueue)\n"
             << "2. Serve customer (dequeue)\n"
             << "3. Display waiting customers\n"
             << "4. Count waiting customers\n"
             << "5. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter customer token: ";
                cin >> token;
                queue.enqueue(token);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                queue.countCustomers();
                break;
            case 5:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
