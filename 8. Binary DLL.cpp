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
