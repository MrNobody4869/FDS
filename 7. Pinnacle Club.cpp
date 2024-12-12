#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    int PRN;
    string Name;
    Node* next;
};

class SLL {
private:
    Node* head;
    Node* last;
    int value, op;

public:
    SLL() {
        head = NULL;
        last = NULL;
    }

    void create();
    void display();
};

void SLL::create() {
    Node* temp;
    do {
        if (head == NULL) {
          
            temp = new Node;
            cout << "\n Enter PRN And Name Of President: ";
            cin >> temp->PRN >> temp->Name;
            temp->next = NULL;
            head = temp;

            
            last = new Node;
            cout << "\n Enter PRN And Name Of Secretary: ";
            cin >> last->PRN >> last->Name;
            last->next = NULL;
            head->next = last;
        }
        else {
            
            temp = new Node;
            cout << "\n Enter PRN And Name For Member: ";
            cin >> temp->PRN >> temp->Name;
            temp->next = NULL;


            temp->next = last;
            head->next->next = temp;
            head->next = temp;
        }
        cout << "\n Do you want to add new member (1/0): ";
        cin >> op;
    } while (op == 1);
}

void SLL::display() {
    Node* temp;
    temp = head;
    cout << "President: " << temp->PRN << "\t\t" << temp->Name << "\n";
    temp = temp->next;
    while (temp != last) {
        cout << "Member: " << temp->PRN << "\t\t" << temp->Name << "\n";
        temp = temp->next;
    }
    cout << "Secretary: " << temp->PRN << "\t\t" << temp->Name << "\n";
}

int main() {
    SLL S1;
    S1.create();
    S1.display();
    return 0;
}
