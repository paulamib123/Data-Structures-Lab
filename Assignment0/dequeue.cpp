#include <iostream>
using namespace std;

class Deque{
    int arr[100];
    int front;
    int rear;
    int size;

    public:
        Deque(int s){
            front = -1;
            rear = 0;
            size = s;
        }
    
        void insertFront(int key);
        void insertRear(int key);
        void deleteFront();
        void deleteRear();
        bool isFull();
        bool isEmpty();
        int getFront();
        int getRear();
        void display();
};

bool Deque :: isFull(){
    return ((front == 0 && rear == size - 1) || front == rear + 1);
}

bool Deque :: isEmpty(){
    return (front == -1);
}

void Deque :: insertFront(int key) {
    if (isFull()) 
    { 
        cout << "Overflow\n" << endl; 
        return; 
    } 
  
    if (front == -1) 
    { 
        front = 0; 
        rear = 0; 
    } 
  
    else if (front == 0) 
        front = size - 1; 
  
    else 
        front = front-1; 
  
    arr[front] = key ; 
       
}

void Deque :: insertRear(int key) {
    if (isFull()) 
    { 
        cout << " Overflow\n " << endl; 
        return; 
    } 
  
    if (front == -1) 
    { 
        front = 0; 
        rear = 0; 
    } 
  
    else if (rear == size-1) 
        rear = 0; 
   
    else
        rear = rear + 1; 

    arr[rear] = key ; 
}

void Deque :: deleteFront() {
    if (isEmpty()) {
        cout << "UnderFlow\n" << endl;
        return;
    }

    if (front == rear) {
        rear = -1;
        front = -1;
    }

    else {
        if (front == size - 1) 
            front = 0;
        else
            front = front + 1;
    }
}

void Deque :: deleteRear() {
    if (isEmpty()) {
        cout << "UnderFlow\n" << endl;
        return;
    }

    if (front == rear) {
        rear = -1;
        front = -1;
    }

    else if (rear == 0)
        rear = size - 1;
    
    else
        rear = rear - 1;
}

int Deque :: getFront(){
    if (isEmpty()) 
    { 
        cout << " Underflow\n" << endl; 
        return -1 ; 
    } 
    return arr[front]; 
}

int Deque :: getRear(){
     if(isEmpty() || rear < 0) 
    { 
        cout << " Underflow\n" << endl; 
        return -1 ; 
    } 
    return arr[rear]; 
}

void Deque :: display()
{
    if(front > rear) {
        for(int i = front; i < size; i++) {
            cout << arr[i] << " ";
        }
        for(int j = 0; j <= rear; j++) {
            cout << arr[j] << " ";
        }
    }
    else {
        for(int i = front;i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
}

int main(){
    Deque dq(50);
    int ele, choice, result;
    char ch;
    
    do{
        cout << "Menu" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Delete at Front" << endl;
        cout << "3. Insert at Rear" << endl;
        cout << "4. Delete at Rear" << endl;
        cout << "5. Get Front" << endl;
        cout << "6. Get Rear" << endl;
        cout << "7. Display Deque" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter element: ";
                cin >> ele;
                dq.insertFront(ele);
                cout << "Inserted " << ele << " at front" << endl;
                break;
            case 2:
                dq.deleteFront();
                cout << "Deleted element at front" << endl;
                break;
            case 3: 
                cout << "Enter element: ";
                cin >> ele;
                cout << "Inserted " << ele << " at rear" << endl;
                dq.insertRear(ele);
                break;
            case 4:
                dq.deleteRear();
                cout << "Deleted element at rear" << endl;
                break;
            case 5:
                result = dq.getFront();
                if (result != -1) {
                    cout << "Element at front is " << result << endl;
                }
                break;
            case 6:
                result = dq.getRear();
                if (result != -1) {
                    cout << "Element at rear is " << result << endl;
                }
                break;
            case 7:
                dq.display();
                break;
        }
        cout << "Do you want to enter again (y/n) ?" << endl;
        cin >> ch;
    } while(ch == 'y');

    return 0;   
    
}