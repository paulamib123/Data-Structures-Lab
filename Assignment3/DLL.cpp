#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node() {}

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class List : public Node
{
public:
    Node *head;
    Node *temp;
    int size;

    List()
    {
        head = NULL;
        temp = NULL;
        size = 0;
    }

    int getSize();
    void create(int val);
    string display();
    void insertAtStart(int val);
    void insertAtMid(int val, int n);
    void insertAtEnd(int val);
    void deleteAtStart();
    void deleteAtMid(int n);
    void deleteAtEnd();
    void reverse();
    void concatenate(List list2);
};

int List ::getSize()
{
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

void List ::create(int val)
{
    Node *node = new Node(val);
    if (head == NULL)
    {
        head = node;
        temp = node;
    }
    else
    {
        temp->next = node;
        node->prev = temp;
        temp = temp->next;
    }
}

string List ::display()
{
    string result;
    temp = head;
    while (temp != NULL)
    {
        result += to_string(temp->data) + " -> ";
        temp = temp->next;
    }
    return result + "NULL";
}

void List ::insertAtStart(int val)
{
    Node *node = new Node(val);

    if (head == NULL)
    {
        head = node;
        temp = node;
        return;
    }

    temp = head;
    temp->prev = node;
    node->next = temp;
    head = node;
}

void List ::insertAtMid(int val, int n)
{
    temp = head;
    Node *node = new Node(val);
    while (n - 2 != 0)
    {
        temp = temp->next;
        n--;
    }

    node->next = temp->next;
    temp->next->prev = node;

    temp->next = node;
    node->prev = temp;
}

void List ::insertAtEnd(int val)
{
    Node *node = new Node(val);

    if (head == NULL)
    {
        head = node;
        temp = node;
        return;
    }

    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
    temp = temp->next;
}

void List ::deleteAtStart()
{
    temp = head;
    head = temp->next;
    head->prev = NULL;
    delete (temp);
}

void List ::deleteAtMid(int n)
{
    temp = head;
    while (n - 1 != 0)
    {
        temp = temp->next;
        n--;
    }
    // temp is at the node to be deleted
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete (temp);
}

void List ::deleteAtEnd()
{
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *q = temp->next;
    temp->next = NULL;
    delete (q);
}

void List ::reverse() //baaki hai
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {
        // reversing the link
        next = current->next;
        current->next = prev;

        // moving pointers ahead
        prev = current;
        current = next;
    }
    head = prev;
}

void List ::concatenate(List list2)
{
    this->temp = this->head;
    while (this->temp->next != NULL)
    {
        this->temp = this->temp->next;
    }
    list2.head->prev = this->temp->next;
    this->temp->next = list2.head;
}

int main()
{
    int option;
    char ch;
    List list;
    int n;
    int val;
    string result;
    int pos;
    List list2;
    int choice;
    int length;
    do
    {
        cout << "MENU" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. REVERSE" << endl;
        cout << "6. CONCATENATE TWO LISTS" << endl;
        cout << "Choose any option: ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1:
            cout << "Enter number of elements to insert in Linked List: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter value for node " << i + 1 << " : ";
                cin >> val;
                list.create(val);
            }
            cout << endl;
            break;

        case 2:
            cout << "DISPLAYING LIST" << endl;
            result = list.display();
            cout << result << endl;
            break;

        case 3:
            length = list.getSize();
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "1. INSERT AT BEGINNING" << endl;
            cout << "2. INSERT AT MIDDLE" << endl;
            cout << "3. INSERT AT END" << endl;
            cout << "Choose option: ";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                list.insertAtStart(val);
                cout << "Inserted element" << endl;
                break;

            case 2:
                if (length == 0)
                {
                    cout << "List is Empty" << endl;
                    break;
                }

                do
                {
                    cout << endl;
                    cout << "Please enter valid position" << endl;
                    cout << "Enter position (except start and end position): ";
                    cin >> pos;
                } while (pos <= 0 || pos >= length);

                list.insertAtMid(val, pos);
                cout << "Inserted element" << endl;
                break;

            case 3:
                list.insertAtEnd(val);
                cout << "Inserted element" << endl;
                break;
            }
            break;

        case 4:
            length = list.getSize();
            cout << "1. DELETE AT BEGINNING" << endl;
            cout << "2. DELETE AT MIDDLE" << endl;
            cout << "3. DELETE AT END" << endl;
            cout << "Choose option: ";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                if (length == 0)
                {
                    cout << "List is Empty" << endl;
                    break;
                }

                list.deleteAtStart();
                cout << "Deleted elemnet" << endl;
                break;

            case 2:
                if (length == 0)
                {
                    cout << "List is Empty" << endl;
                    break;
                }

                do
                {
                    cout << endl;
                    cout << "Please enter valid position" << endl;
                    cout << "Enter position (except start and end position): ";
                    cin >> pos;
                } while (pos <= 0 || pos >= length);

                list.deleteAtMid(pos);
                cout << "Deleted elemnet" << endl;
                break;

            case 3:
                if (length == 0)
                {
                    cout << "List is Empty" << endl;
                    break;
                }

                list.deleteAtEnd();
                cout << "Deleted elemnet" << endl;
                break;
            }
            break;

        case 5:
            list.reverse();
            cout << "Reversed Linked List" << endl;
            break;

        case 6:
            cout << "Enter number of elements to insert in Linked List 2: ";
            cin >> n;
            if (list2.head != NULL)
                list2.head = NULL;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter value for node " << i + 1 << " : ";
                cin >> val;
                list2.create(val);
            }
            cout << "Concatanated two lists" << endl;
            cout << endl;
            list.concatenate(list2);
            break;

        default:
            cout << "Wrong Choice! Enter again!" << endl;
            break;
        }
        cout << endl;
        cout << "Do you want to enter again? (y/n): ";
        cin >> ch;
        cout << endl;
    } while (ch == 'y');
    return 0;
}