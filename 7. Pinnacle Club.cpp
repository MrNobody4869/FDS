#include<iostream>
#include<string>
using namespace std;

class node
{
public:
    int PRN;
    string Name;
    node *next;
};

class SLL
{
    node *head, *last;
    int count;

public:
    SLL()
    {
        head = nullptr;
        last = nullptr;
        count=0;
    }

    void create();
    void display();
    void search();
};

void SLL::create()
{
    node *temp, *temp1;
    int op;
    do
    {

        if (head == nullptr)
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

            head->next = last;
            count+=2;
        }
        else
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
    count++;
}

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
    cout<<"Total members :"<<count<<endl;
}

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
    SLL S;
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
            S.create();
            break;
        case 2:
            S.display();
            break;
        case 3:
            S.search();
            break;
        case 4:
            cout<<"Exiting program."<<endl;
            break;
        default:
            cout<<"Invalid choice! Please try again."<<endl;
        }
    } while (choice != 4);

    return 0;
}
