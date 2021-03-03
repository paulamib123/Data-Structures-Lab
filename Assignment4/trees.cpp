#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node() {}

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Tree : public Node
{
public:
    Node *root;

    Tree()
    {
        root = NULL;
    }

    void createTree(int data);
};

void Tree ::createTree(int data)
{
    Node* temp;
    Node* node = new Node(data);
    char ch;
    if (root == NULL) 
    {
        root = node;
    }
    else 
    {
        temp = root;
        while (1) 
        {
            cout << "Do you want to add node at left or right? (l/r)";
            cin >> ch;
            if (ch == 'l') 
            {
                if (temp->left == NULL) 
                {
                    temp->left = node;
                    break;
                } 
                else 
                {
                    temp = temp->left;
                }
            } 
            else if (ch == 'r') 
            {
                if (temp->right == NULL) 
                {
                    temp->right = node;
                    break;
                } 
                else 
                {
                    temp = temp->right;
                }
            }
        }
    }
}

int main() {
    int option;
    char ch;
    do {
        cout << "MENU" << endl;
        cout << "1. CREATE TREE" << endl;
        cout << "Choose any option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            break;
        
        default:
            cout << "Wrong Choice! Enter again!" << endl;
            break;
        }
        cout << "Do you want to enter again? (y/n): ";
        cin >> ch;
        cout << endl;
    } while (ch == 'y');
    return 0;
}

