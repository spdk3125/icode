#include <iostream>
using namespace std;

namespace Queue {
    const int SIZE = 5;
    int items[SIZE];
    int head = -1, tail = -1;

    void enQueue(int value) {
        if (tail == SIZE - 1)
            cout << "\nCannot insert element; the queue is already full.";
        else {
            if (head == -1)
                head = 0;
            tail++;
            items[tail] = value;
            cout << "\nInserted -> " << value;
        }
    }

    void deQueue() {
        if (head == -1)
            cout << "\nCannot dequeue; the queue is empty.";
        else {
            cout << "\nDeleted: " << items[head];
            head++;
            if (head > tail)
                head = tail = -1;
        }
    }

    void display() {
        if (tail == -1)
            cout << "\nQueue is empty!";
        else {
            cout << "\nQueue elements are:\n";
            for (int i = head; i <= tail; i++)
                cout << items[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int ch, item;
    do {
        cout << "\nQueue Operations:\n";
        cout << "1. enQueue\n";
        cout << "2. deQueue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the item to enQueue: ";
                cin >> item;
                Queue::enQueue(item);
                break;
            case 2:
                Queue::deQueue();
                break;
            case 3:
                Queue::display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (ch != 4);

    return 0;
}