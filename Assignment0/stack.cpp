#include <iostream>
using namespace std;

class Stack {
    int size;
    int top;
    int* stack;

    public:
        Stack(int size) {
            stack = new int[size];
            this->size = size;
            top = -1;
        }
        bool isEmpty();
        bool isFull();
        void push(int ele);
        int pop();
        int getTop();
        void display();
};

bool Stack :: isEmpty() {
    return top == -1;
}

bool Stack :: isFull() {
    return top == size - 1;
}

int Stack :: getTop() {
    return stack[top];
}

void Stack :: push(int ele) {
    if (isFull()) {
        cout << "Overflow!" << endl;
        return;
    }
    stack[++top] = ele;
    cout << "Pushed " + to_string(ele) << endl;
}

int Stack :: pop() {
    if (isEmpty()) {
        cout << "Underflow!" << endl;
        return -1;
    }
    int ele = stack[top--];
    cout << "Popped " + to_string(ele) << endl;
    return ele;
}

void Stack :: display() {
    if (top == -1)
        cout << "Stack is empty" << endl;
    for(int i = top; i >= 0; --i) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack stk(3);
    stk.push(70);
    stk.display();
    stk.push(5);
    stk.display();
    stk.push(31);
    stk.display();
    stk.pop();
    stk.display();
    stk.pop();
    stk.display();
    stk.pop();
    stk.display();
}
