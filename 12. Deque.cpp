#include <iostream>
using namespace std;

const int SIZE = 6; // Maximum size of the deque

class Deque {
private:
    int dequeArray[SIZE]; // Array to store deque elements
    int front;            // Index of the front element
    int rear;             // Index of the rear element

public:
    // Constructor to initialize the deque
    Deque() {
        front = -1;
        rear = -1;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Function to check if the deque is full
    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || front == rear + 1);
    }

    // Function to insert an element at the front of the deque
    void insertFront(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the front.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            --front;
        }
        dequeArray[front] = element;
        cout << "Element inserted at the front.\n";
    }

    // Function to insert an element at the rear of the deque
    void insertRear(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the rear.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            ++rear;
        }
        dequeArray[rear] = element;
        cout << "Element inserted at the rear.\n";
    }

    // Function to delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            ++front;
        }
        cout << "Element deleted from the front.\n";
    }

    // Function to delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            --rear;
        }
        cout << "Element deleted from the rear.\n";
    }

    // Function to print the elements of the deque
    void printDeque() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        int index = front;
        cout << "Elements in the deque: ";
        while (index != rear) {
            cout << dequeArray[index] << " ";
            index = (index + 1) % SIZE;
        }
        cout << dequeArray[rear] << endl;
    }
};

int main() {
    Deque dq;
    int choice, element;
    do {
        cout << "Double-Ended Queue (Deque) Menu:\n";
        cout << "1. Insert at the front\n";
        cout << "2. Insert at the rear\n";
        cout << "3. Delete from the front\n";
        cout << "4. Delete from the rear\n";
        cout << "5. Print the deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to insert at the front: ";
            cin >> element;
            dq.insertFront(element);
            break;
        case 2:
            cout << "Enter the element to insert at the rear: ";
            cin >> element;
            dq.insertRear(element);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            dq.printDeque();
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        cout << endl;
    } while (choice != 6);

    return 0;
}

/*
Additional Information:
1. This program demonstrates a circular deque using an array.
2. The deque supports insertion and deletion from both ends.
3. The `isFull` function checks if the deque is full.
4. The `isEmpty` function checks if the deque is empty.
5. Elements are stored in a circular manner to utilize all space.
6. Front and rear pointers are adjusted for every operation.
7. The `printDeque` function prints all elements currently in the deque.
8. User interaction is provided via a menu-driven interface.
9. The deque has a fixed size of 6 elements (modifiable in `SIZE`).
10. Ensure inputs are integers for proper execution and avoid overflow.
*/
