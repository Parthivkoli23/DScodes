#include <iostream>
using namespace std;

class circular_linked_list
{
public:
    void create_list();
    void insert_begin();
    void insert_end();
    void insert_pos();
    void delete_begin();
    void delete_pos();
    void delete_end();
    void search();
    void display();

private:
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *last;
};


void circular_linked_list::create_list()
{
    int num_elements;
    cout << "Enter the number of elements in the list: ";
    cin >> num_elements;

    struct node *temp;
    temp = new node;
    int value;
    cout << "Input the value of node: ";
    cin >> value;
    temp->data = value;
    last = temp;
    last->next = last;

    for (int i = 1; i < num_elements; i++)
    {
        temp = new node;
        cout << "Input the value of node: ";
        cin >> value;
        temp->data = value;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void circular_linked_list::insert_begin()
{
    struct node *temp;
    temp = new node;
    int value;
    cout << "Input the value of node: ";
    cin >> value;
    temp->data = value;
    temp->next = last->next;
    last->next = temp;
}

void circular_linked_list::insert_end()
{
    struct node *temp;
    temp = new node;
    int value;
    cout << "Input the value of node: ";
    cin >> value;
    temp->data = value;
    temp->next = last->next;
    last->next = temp;
    last = temp;
}

void circular_linked_list::insert_pos()
{
    struct node *temp, *p;
    p = last->next;
    int value;
    int pos;
    cout << "Input the position where the node is to be inserted: ";
    cin >> pos;
    cout << "Input the value of node: ";
    cin >> value;
    temp = new node;
    temp->data = value;
    for (int i = 1; i < pos; i++)
    {
        if (p == last)
        {
            break;
        }
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

void circular_linked_list::delete_begin()
{
    struct node *temp;
    temp = last->next;
    last->next = temp->next;
    delete temp;
}


void circular_linked_list::delete_pos()
{
    struct node *temp, *p;
    p = last->next;
    int pos;
    cout << "Input the position where the node is to be deleted: ";
    cin >> pos;
    for (int i = 1; i < pos; i++)
    {
        if (p == last)
        {
            break;
        }
        temp = p;
        p = p->next;
    }
    temp->next = p->next;
    delete (p);
}

void circular_linked_list::delete_end()
{
    struct node *temp, *p;
    p = last->next;
    while (p->next != last)
    {
        temp = p;
        p = p->next;
    }
    temp->next = p->next;
    last = temp;
    delete p;
}


void circular_linked_list::search()
{
    struct node *p;
    int item;
    int flag;
    cout << "Input the value to be searched: ";
    cin >> item;
    p = last->next;
    while (p != last)
    {
    if (p->data == item)
    {
        flag = 1;
        break;
    }
    p = p->next;
}
if (flag == 1)
{
    cout << "Element found" << endl;
}
else
{
    cout << "Element not found" << endl;
}
}

void circular_linked_list::display()
{
    struct node *p;
    p = last->next;
    cout << "The list is: " << endl;
    while (p != last)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data << endl;
}

int main()
{
    circular_linked_list obj;
    int choice;
    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Insert at beginning" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Insert at position" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete from position" << endl;
        cout << "8. Search for an element" << endl;
        cout << "9. Display the list" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.create_list();
            break;
        case 2:
            obj.insert_begin();
            break;
        case 3:
            obj.insert_end();
            break;
        case 4:
            obj.insert_pos();
            break;
        case 5:
            obj.delete_begin();
            break;
        case 6:
            obj.delete_end();
            break;
        case 7:
            obj.delete_pos();
            break;
        case 8:
            obj.search();
            break;
        case 9:
            obj.display();
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
