#include <iostream>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Stack Class
class Stack {
private:
    Node* top;

public:

    // Constructor
    Stack() {
        top = NULL;
    }

    // Push Operation
    void push(int value) {

        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack." << endl;
    }

    // Pop Operation
    void pop() {

        if (top == NULL) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }

        Node* temp = top;

        cout << temp->data << " popped from stack." << endl;

        top = top->next;

        delete temp;
    }

    // Peek Operation
    void peek() {

        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element: " << top->data << endl;
    }

    // Display Operation
    void display() {

        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;

        cout << "Stack elements (Top to Bottom):" << endl;

        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // Check if Stack is Empty
    bool isEmpty() {
        return top == NULL;
    }
};


int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << endl;

    s.display();

    cout << endl;

    s.peek();

    cout << endl;

    s.pop();

    cout << endl;

    s.display();

    return 0;
}
