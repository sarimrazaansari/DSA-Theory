#include <iostream>
using namespace std;

class Queue {
private:
    int arr[5];
    int front; //remove item
    int rear; //add  item

public:

    // Constructor
    Queue() {
        front = -1;
        rear = -1; //top and rear is aprox same
    }

    // Enqueue Operation
    void enqueue(int value) {

        if (rear == 4) {
            cout << "Queue Overflow! Queue is full." << endl;
            return;
        }

        // First element
        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = value;

        cout << value << " inserted into queue." << endl;
    }

    // Dequeue Operation
    void dequeue() {

        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }

        cout << arr[front] << " removed from queue." << endl;

        front++;
    }

    // Peek Operation
    void peek() {

        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    // Display Operation
    void display() {

        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements (Front to Rear):" << endl;

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Check if Queue is Empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Check if Queue is Full
    bool isFull() {
        return rear == 4;
    }
};


int main() {

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << endl;

    q.display();

    cout << endl;

    q.peek();

    cout << endl;

    q.dequeue();

    cout << endl;

    q.display();

    return 0;
}
