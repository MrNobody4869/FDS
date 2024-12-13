// C++ program for simulating job queue using functions to add job and delete job from queue
#include <iostream>
using namespace std;

class Queue {
public:
    int queue[5]; // Array to store queue elements
    int front, rear; // Variables to track the front and rear of the queue

    // Constructor to initialize queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to add a job to the queue
    void enQueue() {
        int value;
        if (rear == 4) { // Check if the queue is full
            cout << "Queue is FULL!!! Insertion is not possible!!!" << endl;
        } else {
            cout << "Enter the value to be inserted: ";
            cin >> value;
            if (front == -1) { // Set front to 0 if queue was empty
                front = 0;
            }
            rear++; // Increment rear and insert the value
            queue[rear] = value;
            cout << "Inserted: " << value << endl;
        }
    }

    // Function to delete a job from the queue
    void deQueue() {
        if (front == -1 || front > rear) { // Check if the queue is empty
            cout << "Queue is EMPTY!!! Deletion is not possible!!!" << endl;
        } else {
            int temp = queue[front]; // Store the value to be deleted
            cout << "Deleted Element: " << temp << endl;
            front++; // Move the front forward
            if (front > rear) { // Reset queue if it becomes empty
                front = rear = -1;
            }
        }
    }

    // Function to display the elements in the queue
    void display() {
        if (front == -1) { // Check if the queue is empty
            cout << "Queue is EMPTY!!!" << endl;
        } else {
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++) { // Loop through the queue
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue Q1; // Create a queue object
    int choice; // Variable to store user choice
    do {
        cout << "\n1. Add Job\n2. Delete Job\n3. Display Jobs\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            Q1.enQueue(); // Call function to add job
            break;
        case 2:
            Q1.deQueue(); // Call function to delete job
            break;
        case 3:
            Q1.display(); // Call function to display jobs
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4); // Repeat until user chooses to exit

    return 0;
}

/*
Additional Information:
1. This program simulates a job queue using an array-based implementation.
2. The queue has a maximum size of 5 elements.
3. The `enQueue` function adds an element to the queue (rear side).
4. The `deQueue` function removes an element from the queue (front side).
5. The `display` function prints the current elements in the queue.
6. If the queue is full, further insertions are blocked.
7. If the queue is empty, deletions are not allowed.
8. The queue follows the FIFO (First In, First Out) principle.
9. User interaction is facilitated via a menu-driven approach in `main`.
10. Ensure inputs are valid (integers within reasonable range) for proper functionality.
*/



/*
### **Objectives**:
1. Understand the **queue** Abstract Data Type (ADT).
2. Learn to implement queue operations for real-world applications.
3. Explore how job scheduling uses queues in operating systems.
4. Develop a program to simulate job addition and deletion operations using arrays or linked lists.

---

### **Theory**:
1. **What is a Queue?**:
   - A queue is a linear data structure that follows the **First-In-First-Out (FIFO)** principle:
     - The element added first is removed first.
     - New elements are added to the **rear**, and elements are removed from the **front**.

2. **Key Operations of a Queue**:
   - **Enqueue**: Add an element to the rear of the queue.
   - **Dequeue**: Remove an element from the front of the queue.
   - **Peek/Front**: Retrieve the front element without removing it.
   - **IsFull/IsEmpty**: Check if the queue is full or empty.

3. **Applications of Queue in Job Scheduling**:
   - Operating systems use queues to manage processes and tasks.
   - In a job scheduling context:
     - Jobs are enqueued as they arrive.
     - Jobs are dequeued for execution in the order they were added.
     - No priority differentiation; purely FIFO-based execution.

4. **Implementation Approaches**:
   - **Array-based Queue**:
     - Fixed size; wrap-around using circular logic.
     - Easier to implement but has size limitations.
   - **Linked List-based Queue**:
     - Dynamic size; more memory-efficient for varying workloads.

5. **Steps to Simulate a Job Queue**:
   - Initialize an empty queue.
   - Accept jobs as user input and enqueue them.
   - Process jobs (dequeue) based on FIFO order.
   - Display the current state of the queue after each operation.

6. **Algorithm**:
   **Enqueue Operation**:
   - Check if the queue is full (overflow condition).
   - Increment the rear pointer.
   - Add the new job to the queue.
   
   **Dequeue Operation**:
   - Check if the queue is empty (underflow condition).
   - Retrieve and remove the front job.
   - Increment the front pointer.

*/
