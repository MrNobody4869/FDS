#include <iostream>
using namespace std;

#define SIZE 5 // Define the size of the circular queue

class CircularQueue {
private:
    int queue[SIZE]; // Array to store queue elements
    int front, rear; // Variables to track the front and rear of the queue

public:
    // Constructor to initialize queue
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to add an order to the queue
    void enQueue(int order) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot add more orders." << endl;
        } else {
            if (front == -1) { // Initialize front if the queue was empty
                front = 0;
            }
            rear = (rear + 1) % SIZE; // Increment rear circularly
            queue[rear] = order; // Add the order to the queue
            cout << "Order " << order << " added to the queue." << endl;
        }
    }

    // Function to remove an order from the queue
    void deQueue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No orders to serve." << endl;
        } else {
            cout << "Order " << queue[front] << " served." << endl;
            if (front == rear) { // Reset the queue if it becomes empty
                front = rear = -1;
            } else {
                front = (front + 1) % SIZE; // Increment front circularly
            }
        }
    }

    // Function to display the current orders in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No orders to display." << endl;
        } else {
            cout << "Current Orders in Queue: ";
            int i = front;
            while (i != rear) {
                cout << queue[i] << " ";
                i = (i + 1) % SIZE; // Increment index circularly
            }
            cout << queue[rear] << endl; // Print the last element
        }
    }
};

int main() {
    CircularQueue cq; // Create a circular queue object
    int choice, order; // Variables for user input

    do {
        cout << "\n1. Add Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter order number to add: ";
            cin >> order;
            cq.enQueue(order); // Add an order to the queue
            break;
        case 2:
            cq.deQueue(); // Serve (remove) an order from the queue
            break;
        case 3:
            cq.display(); // Display current orders in the queue
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4); // Loop until the user chooses to exit

    return 0;
}

/*
Additional Information:
1. This program simulates a circular queue for managing orders.
2. A circular queue reuses empty spaces at the beginning when elements are removed.
3. The `enQueue` function adds an order to the rear.
4. The `deQueue` function removes an order from the front.
5. The `display` function shows the current elements in the queue.
6. The queue is implemented using an array with a fixed size of 5.
7. The program prevents overflow (adding to a full queue) and underflow (removing from an empty queue).
8. Edge cases such as wrapping around indices are handled using modulo (`%`) operator.
9. This implementation is useful for scenarios like ticket counters, order processing, or scheduling tasks.
10. Make sure to test the program with various inputs to verify edge cases.
*/



/*

### **Objectives**:
1. Understand the **circular queue** data structure and its operations.
2. Learn to implement a circular queue using arrays for efficient memory utilization.
3. Explore real-world applications of circular queues in scheduling and buffer management.
4. Develop a program to simulate a pizza ordering system using a circular queue.
5. Analyze how circular queues prevent memory wastage in fixed-size queues.

---

### **Short Theory**:

1. **What is a Circular Queue?**  
   - A **circular queue** is a linear data structure that connects the rear of the queue to the front, forming a circle.  
   - It avoids memory wastage by reusing empty spaces created by dequeuing elements.  

2. **Key Features**:  
   - **Front**: Tracks the first element of the queue.  
   - **Rear**: Tracks the last element of the queue.  
   - **Wrap-around**: When the rear or front reaches the end of the array, it wraps around to the beginning.  

3. **Key Operations**:  
   - **Enqueue**: Add an element to the rear of the queue.  
     - Increment the rear pointer (wrap-around if necessary).  
     - Check if the queue is full before insertion.  
   - **Dequeue**: Remove an element from the front of the queue.  
     - Increment the front pointer (wrap-around if necessary).  
     - Check if the queue is empty before removal.  
   - **Peek**: Access the front element without removing it.  
   - **IsFull**: Check if the queue is full.  
   - **IsEmpty**: Check if the queue is empty.  

4. **Applications**:  
   - **Order Management**: Handling first-come-first-serve orders in restaurants (e.g., pizza orders).  
   - **Buffering**: Circular buffers in real-time systems like audio or video streaming.  
   - **Task Scheduling**: Efficiently managing tasks in round-robin scheduling.  
   - **Network Management**: Storing packets in routers.  

5. **Advantages**:  
   - Prevents memory wastage compared to a standard linear queue.  
   - Efficient for fixed-size buffers and real-time systems.  

6. **Disadvantages**:  
   - Fixed size limits the number of elements.  
   - Needs careful implementation to handle wrap-around conditions.  

*/
