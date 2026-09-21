#include <iostream>
using namespace std;

class Stack {
private:
    int arr[5];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top == 4) {
            cout << "Stack Overflow! Cannot insert more elements." << endl;
            return;
        }

        top++;
        arr[top] = value;

        cout << value << " pushed into stack." << endl;
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }

        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    // Peek operation
    void peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element: " << arr[top] << endl;
    }

    // Display operation
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (Top to Bottom):" << endl;

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == 4;
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
