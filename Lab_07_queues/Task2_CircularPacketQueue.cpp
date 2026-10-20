#include <iostream>
using namespace std;

const int SIZE = 5;

// Circular queue that reuses array positions after packets are transmitted.
class CircularQueue {
private:
    int packets[SIZE];
    int front;
    int rear;
    int count; // Number of packets currently stored.

public:
    CircularQueue() : front(0), rear(-1), count(0) {}

    // Insert a packet at the rear, wrapping around when necessary.
    void enqueue(int packetId) {
        if (count == SIZE) {
            cout << "Queue full: cannot add packet.\n";
            return;
        }

        rear = (rear + 1) % SIZE;
        packets[rear] = packetId;
        ++count;
        cout << "Packet " << packetId << " added.\n";
    }

    // Transmit the oldest packet from the front.
    void dequeue() {
        if (count == 0) {
            cout << "Queue empty: no packets to transmit.\n";
            return;
        }

        cout << "Transmitting packet " << packets[front] << ".\n";
        front = (front + 1) % SIZE;
        --count;

        // Keep indices in a consistent empty-state configuration.
        if (count == 0) {
            front = 0;
            rear = -1;
        }
    }

    // Display packets from oldest to newest, accounting for wrap-around.
    void display() const {
        if (count == 0) {
            cout << "No packets waiting.\n";
            return;
        }

        cout << "Packets waiting: ";
        for (int i = 0; i < count; ++i) {
            cout << packets[(front + i) % SIZE] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    CircularQueue queue;
    int choice, packetId;

    do {
        cout << "\n--- Network Packet Management ---\n"
             << "1. Add packet\n"
             << "2. Transmit oldest packet\n"
             << "3. Display waiting packets\n"
             << "4. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter packet ID: ";
                cin >> packetId;
                queue.enqueue(packetId);
                break;
            case 2:
                queue.dequeue();
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
