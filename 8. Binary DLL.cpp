#include <iostream>
#include <string>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Class to manage a binary number as a doubly linked list
class BinaryNumber {
private:
    Node* head;
    Node* tail;

public:
    BinaryNumber() : head(nullptr), tail(nullptr) {}

    // Function to append a bit to the binary number
    void appendBit(int bit) {
        Node* newNode = new Node(bit);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to compute 1's complement of the binary number
    void onesComplement() {
        Node* temp = head;
        while (temp) {
            temp->data = (temp->data == 0) ? 1 : 0;
            temp = temp->next;
        }
    }

    // Function to compute 2's complement of the binary number
    void twosComplement() {
        onesComplement();

        // Add 1 to the binary number
        Node* temp = tail;
        int carry = 1;
        while (temp && carry) {
            int sum = temp->data + carry;
            temp->data = sum % 2;
            carry = sum / 2;
            temp = temp->prev;
        }

        // If there's still a carry, add a new node at the head
        if (carry) {
            Node* newNode = new Node(1);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to add another binary number to this binary number
    BinaryNumber add(BinaryNumber& other) {
        BinaryNumber result;
        Node* temp1 = tail;
        Node* temp2 = other.tail;
        int carry = 0;

        while (temp1 || temp2 || carry) {
            int sum = carry;
            if (temp1) {
                sum += temp1->data;
                temp1 = temp1->prev;
            }
            if (temp2) {
                sum += temp2->data;
                temp2 = temp2->prev;
            }

            result.appendToFront(sum % 2);
            carry = sum / 2;
        }

        return result;
    }

    // Helper function to append a bit at the front of the list (used in addition)
    void appendToFront(int bit) {
        Node* newNode = new Node(bit);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to display the binary number
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~BinaryNumber() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    BinaryNumber bin1, bin2;
    string input1, input2;

    cout << "Enter the first binary number: ";
    cin >> input1;
    for (char bit : input1) {
        bin1.appendBit(bit - '0');
    }

    cout << "Enter the second binary number: ";
    cin >> input2;
    for (char bit : input2) {
        bin2.appendBit(bit - '0');
    }

    cout << "\nFirst Binary Number: ";
    bin1.display();
    
    cout << "\nSecond Binary Number: ";
    bin2.display();
    

    cout << "1's Complement of First Binary Number: ";
    bin1.onesComplement();
    bin1.display();

    cout << "2's Complement of First Binary Number: ";
    bin1.twosComplement();
    bin1.display();


    cout << "\nAddition of the Two Binary Numbers: ";
    BinaryNumber sum = bin1.add(bin2);
    sum.display();

    return 0;
}

















/*
---

### **Objectives**
1. Understand the concept and implementation of **Doubly Linked Lists (DLL)**.
2. Learn to:
   - Store binary numbers using a doubly linked list.
   - Compute 1’s and 2’s complements of a binary number.
   - Perform the addition of two binary numbers stored in a doubly linked list.
3. Practice implementing operations on doubly linked lists and manipulating linked structures.

---

### **Short Theory**

**Doubly Linked List (DLL):**
A doubly linked list is a linear data structure where each node contains three components:
1. **Data**: The value stored in the node.
2. **Next Pointer**: A reference to the next node in the sequence.
3. **Previous Pointer**: A reference to the previous node in the sequence.

Unlike singly linked lists, DLLs allow traversal in both directions.

**Key Operations in DLL:**
1. **Insertion**:
   - At the beginning, end, or a specific position.
   - Adjust both `next` and `previous` pointers.
2. **Deletion**:
   - Remove a node by updating the pointers of adjacent nodes.
3. **Traversal**:
   - Forward traversal (from head to tail).
   - Backward traversal (from tail to head).

**Binary Number Representation in DLL:**
Each digit (0 or 1) of a binary number is stored in a node of the doubly linked list. This allows efficient traversal and manipulation of binary digits.

**1’s and 2’s Complement Operations:**
1. **1’s Complement**:
   - Traverse the list and flip each bit (0 → 1, 1 → 0).
2. **2’s Complement**:
   - Compute the 1’s complement.
   - Add 1 to the least significant bit (LSB) using addition logic.

**Addition of Two Binary Numbers:**
1. Traverse the two binary numbers stored in DLL from the tail (LSB).
2. Add corresponding bits along with a carry.
3. Store the result in a new DLL.

**Time Complexity**:
1. **Insertion/Deletion**: O(1) for the head or tail; O(n) for arbitrary positions.
2. **Traversal**: O(n), where (n) is the number of nodes.
3. **1’s and 2’s Complement**: O(n) (requires traversing the entire list).
4. **Addition of Two Binary Numbers**: O(n) (traversal and bit-wise addition).

**Applications**:
- Efficient representation and manipulation of numbers in binary form.
- Used in arithmetic operations in digital systems.
- Dynamic data representation with bidirectional traversal.

**Advantages of DLL**:
1. Allows forward and backward traversal.
2. Efficient insertion and deletion at both ends.

**Disadvantages of DLL**:
1. Requires extra memory for the `previous` pointer.
2. Slightly more complex to implement compared to singly linked lists.

---

This assignment helps students understand advanced linked list structures and their applications in numerical operations, fostering problem-solving skills in dynamic data handling.

*/

