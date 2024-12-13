#include<iostream>
#include<string>
using namespace std;

class node
{
public:
    int PRN;           // PRN of the member
    string Name;       // Name of the member
    node *next;        // Pointer to the next node in the list
};

class SLL
{
    node *head, *last;  // Pointers to the first and last nodes
    int count;          // Counter for the number of members

public:
    SLL()
    {
        head = nullptr;
        last = nullptr;
        count = 0;
    }

    void create();
    void display();
    void search();
};

// Function to create the list and add members
void SLL::create()
{
    node *temp, *temp1;
    int op;

    do
    {
        if (head == nullptr)  // If the list is empty, add President and Secretary
        {
            temp = new node;
            cout << "\n Enter PRN and Name of President: "<<endl;
            cin >> temp->PRN >> temp->Name;
            temp->next = nullptr;
            head = temp;

            temp = new node;
            cout << "\n Enter PRN and Name of Secretary: "<<endl;
            cin >> temp->PRN >> temp->Name;
            temp->next = nullptr;
            last = temp;

            head->next = last;  // Link President to Secretary
            count += 2;
        }
        else  // If the list is not empty, add more members
        {
            temp1 = head;
            while (temp1->next != last)
            {
                temp1 = temp1->next;
            }

            temp = new node;
            cout << "\n Enter PRN and Name for Member: "<<endl;
            cin >> temp->PRN >> temp->Name;
            temp->next = last;
            temp1->next = temp;
            count++;
        }

        cout << "\n Do you want to add a new member? (1 for Yes / 0 for No): "<<endl;
        cin >> op;
    } while (op == 1);
}

// Function to display all members
void SLL::display()
{
    if (head == nullptr)
    {
        cout << "\n The list is empty.\n";
        return;
    }

    node *temp = head;
    cout << "\nClub Members:\n";
    cout << temp->PRN << "\t\t" << temp->Name << " (President)\n";
    temp = temp->next;

    while (temp != last)
    {
        cout << temp->PRN << "\t\t" << temp->Name << " (Member)\n";
        temp = temp->next;
    }

    if (temp != nullptr)
    {
        cout << temp->PRN << "\t\t" << temp->Name << " (Secretary)\n";
    }
    cout << "Total members: " << count << endl;
}

// Function to search for a member by PRN
void SLL::search()
{
    if (head == nullptr)
    {
        cout << "\n The list is empty. Cannot search.\n";
        return;
    }

    int prn_key;
    cout << "\n Enter the PRN number to search: ";
    cin >> prn_key;

    node *temp = head;
    while (temp != nullptr)
    {
        if (temp->PRN == prn_key)
        {
            cout << "PRN " << prn_key << " found: " << temp->Name << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "PRN " << prn_key << " not found in the list.\n";
}

int main()
{
    SLL S;  // Create an instance of the singly linked list
    int choice;

    do
    {
        cout << "\n--- Pinnacle Club Menu ---\n";
        cout << "1. Create List\n";
        cout << "2. Display List\n";
        cout << "3. Search Member by PRN\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            S.create();  // Add members to the list
            break;
        case 2:
            S.display();  // Show all members
            break;
        case 3:
            S.search();  // Search for a member by PRN
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}














/*
---

### **Objectives**
1. Understand the concept of **Singly Linked Lists (SLL)** and their operations.
2. Learn to:
   - Add and delete members, including special nodes for the president and secretary.
   - Compute the total number of members in the club.
   - Display members in both regular and reverse order (using recursion).
   - Concatenate two linked lists representing two divisions.
3. Develop skills in implementing and manipulating linked lists to solve real-world problems.

---

### **Short Theory**

**Singly Linked List (SLL):**
A singly linked list is a linear data structure where each node contains two components:
1. **Data**: The value stored in the node.
2. **Next Pointer**: A reference to the next node in the sequence.

The first node is called the **head**, and the last node points to `NULL`.

**Key Operations in SLL:**
1. **Insertion**:
   - At the beginning.
   - At the end.
   - At a specific position.
2. **Deletion**:
   - From the beginning.
   - From the end.
   - A specific node.
3. **Traversal**:
   - Visit and process each node sequentially.
   - Display nodes in reverse using recursion.
4. **Concatenation**:
   - Merge two linked lists by linking the last node of the first list to the head of the second list.

**Algorithmic Steps for Key Functions**:
1. **Add Member**:
   - Create a new node.
   - Update the pointers to insert it at the appropriate position.
2. **Delete Member**:
   - Adjust pointers to bypass the node to be deleted.
   - Free memory for the deleted node.
3. **Count Members**:
   - Traverse the list and maintain a count.
4. **Reverse List**:
   - Use recursion to print nodes from the last to the first.

**Time Complexity**:
1. **Insertion/Deletion at Head**: O(1).
2. **Insertion/Deletion at Tail or Specific Position**: O(n) (requires traversal).
3. **Traversal/Counting Members**: O(n).
4. **Concatenation**: O(n) (to find the tail of the first list).

**Applications**:
- Dynamic memory management.
- Implementation of stacks and queues.
- Efficient insertion and deletion in real-time systems.

**Advantages of SLL**:
- Dynamic size (no fixed size required like arrays).
- Efficient memory usage for certain applications.

**Disadvantages of SLL**:
- No backward traversal.
- Accessing an element requires traversing from the head.

---

This assignment provides hands-on experience with a fundamental data structure, highlighting its applications in dynamic systems and its adaptability for real-world scenarios.
    */
