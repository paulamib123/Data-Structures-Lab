#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}

    Node(int data)
    {
        this->data = data;
        next = NULL;
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
    if (head == NULL)
        return 0;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        size++;
    }
    return size + 1;
}

void List ::create(int val)
{
    Node *node = new Node(val);
    if (head == NULL)
    {
        head = node;
        temp = node;
        node->next = head;
    }
    else
    {
        temp->next = node;
        node->next = head;
        temp = temp->next;
    }
}

string List ::display()
{
    string result = "";
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return result;
    }

    temp = head;
    while (temp->next != head)
    {
        result += to_string(temp->data) + " -> ";
        temp = temp->next;
    }
    return result + to_string(temp->data);
}

void List ::insertAtStart(int val)
{
    Node *node = new Node(val);
    if (head == NULL)
    {
        head = node;
        temp = node;
        node->next = head;
    }

    node->next = head;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = node;
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
    node->next = temp->next; // new node stores address of nth node
    temp->next = node;       // n - 1 th node points to the new node
}

void List ::insertAtEnd(int val)
{
    Node *node = new Node(val);

    if (head == NULL)
    {
        head = node;
        temp = node;
        node->next = head;
    }

    node->next = head;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = node;
}

void List ::deleteAtStart()
{
    Node *q = head;
    temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    head = q->next;
    temp->next = head;
    delete (q);
}

void List ::deleteAtMid(int n)
{
    temp = head;
    while (n - 2 != 0)
    {
        temp = temp->next;
        n--;
    }

    Node *q = temp->next;
    temp->next = temp->next->next;
    delete (q);
}

void List ::deleteAtEnd()
{
    temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node *q = temp->next;
    temp->next = head;
    delete (q);
}

void List ::reverse()
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current->next != head)
    {
        next = current->next;
        current->next = prev; // reversing the link

        // moving pointers ahead
        prev = current;
        current = next;
    }

    current->next = prev;
    head->next = current;
    head = current;
}

void List ::concatenate(List list2)
{
    this->temp = this->head;
    while (this->temp->next != head)
    {
        this->temp = this->temp->next;
    }
    this->temp->next = list2.head;

    this->temp = list2.head;
    while (this->temp->next != list2.head)
    {
        this->temp = this->temp->next;
    }
    this->temp->next = this->head;
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