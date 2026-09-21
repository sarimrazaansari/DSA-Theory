#include <iostream>
using namespace std;


// Node class for Doubly Circular Linked List
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};


class DoublyCircularLinkedList {
private:
    Node* head;
    Node* tail;

public:

    // Constructor
    DoublyCircularLinkedList() {
        head = NULL;
        tail = NULL;
    }


    // 1. Insert at Beginning
    void insertAtBeginning(int value) {

        Node* newNode = new Node(value);

        // Agar list empty hai
        if (head == NULL) {

            head = newNode;
            tail = newNode;

            // Circular connection
            head->next = head;
            head->prev = head;
        }

        else {

            newNode->next = head;
            newNode->prev = tail;

            head->prev = newNode;
            tail->next = newNode;

            head = newNode;
        }
    }


    // 2. Insert at End
    void insertAtEnd(int value) {

        Node* newNode = new Node(value);

        // Agar list empty hai
        if (head == NULL) {

            head = newNode;
            tail = newNode;

            // Circular connection
            head->next = head;
            head->prev = head;
        }

        else {

            newNode->prev = tail;
            newNode->next = head;

            tail->next = newNode;
            head->prev = newNode;

            tail = newNode;
        }
    }


    // 3. Insert at Specific Position
    void insertAtPosition(int value, int position) {

        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }


        // Position 1 means beginning
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }


        // Agar list empty hai aur position 1 nahi hai
        if (head == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }


        Node* temp = head;
        int currentPosition = 1;


        // Previous node tak jana hai
        while (currentPosition < position - 1 &&
               temp->next != head) {

            temp = temp->next;
            currentPosition++;
        }


        // Agar requested position invalid hai
        if (currentPosition != position - 1) {
            cout << "Invalid position!" << endl;
            return;
        }


        // Agar tail ke baad insert karna hai
        if (temp == tail) {
            insertAtEnd(value);
            return;
        }


        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }


    // 4. Delete from Beginning
    void deleteFromBeginning() {

        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }


        Node* temp = head;


        // Sirf ek node hai
        if (head == tail) {

            head = NULL;
            tail = NULL;
        }

        else {

            head = head->next;

            head->prev = tail;
            tail->next = head;
        }


        delete temp;
    }


    // 5. Delete from End
    void deleteFromEnd() {

        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return;
        }


        Node* temp = tail;


        // Sirf ek node hai
        if (head == tail) {

            head = NULL;
            tail = NULL;
        }

        else {

            tail = tail->prev;

            tail->next = head;
            head->prev = tail;
        }


        delete temp;
    }


    // 6. Delete from Specific Position
    void deleteFromPosition(int position) {

        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }


        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }


        // Beginning delete
        if (position == 1) {
            deleteFromBeginning();
            return;
        }


        Node* temp = head;
        int currentPosition = 1;


        // Required position tak jana hai
        while (currentPosition < position &&
               temp->next != head) {

            temp = temp->next;
            currentPosition++;
        }


        // Invalid position
        if (currentPosition != position) {
            cout << "Invalid position!" << endl;
            return;
        }


        // Agar last node delete ho rahi hai
        if (temp == tail) {
            deleteFromEnd();
            return;
        }


        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;


        delete temp;
    }


    // 7. Search an Element
    void search(int value) {

        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }


        Node* temp = head;
        int position = 1;


        do {

            if (temp->data == value) {

                cout << value
                     << " found at position "
                     << position << endl;

                return;
            }


            temp = temp->next;
            position++;

        } while (temp != head);


        cout << value << " not found!" << endl;
    }


    // 8. Display Forward
    void displayForward() {

        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }


        Node* temp = head;

        cout << "Forward: ";


        do {

            cout << temp->data;


            temp = temp->next;


            if (temp != head) {
                cout << " <-> ";
            }

        } while (temp != head);


        cout << endl;
    }


    // 9. Display Backward
    void displayBackward() {

        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return;
        }


        Node* temp = tail;

        cout << "Backward: ";


        do {

            cout << temp->data;


            temp = temp->prev;


            if (temp != tail) {
                cout << " <-> ";
            }

        } while (temp != tail);


        cout << endl;
    }


    // 10. Count Nodes
    int countNodes() {

        if (head == NULL) {
            return 0;
        }


        int count = 0;
        Node* temp = head;


        do {

            count++;
            temp = temp->next;

        } while (temp != head);


        return count;
    }


    // 11. Update a Node
    void update(int position, int value) {

        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }


        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }


        Node* temp = head;
        int currentPosition = 1;


        while (currentPosition < position &&
               temp->next != head) {

            temp = temp->next;
            currentPosition++;
        }


        if (currentPosition != position) {
            cout << "Invalid position!" << endl;
            return;
        }


        temp->data = value;


        cout << "Node updated successfully!" << endl;
    }
};



int main() {

    DoublyCircularLinkedList list;


    // Insert at beginning
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);


    // Insert at end
    list.insertAtEnd(30);
    list.insertAtEnd(40);


    cout << endl;
    list.displayForward();
    list.displayBackward();


    // Insert at specific position
    cout << endl;
    list.insertAtPosition(25, 3);

    cout << "After inserting 25 at position 3:" << endl;
    list.displayForward();


    // Delete from beginning
    cout << endl;
    list.deleteFromBeginning();

    cout << "After deleting from beginning:" << endl;
    list.displayForward();


    // Delete from end
    cout << endl;
    list.deleteFromEnd();

    cout << "After deleting from end:" << endl;
    list.displayForward();


    // Delete from specific position
    cout << endl;
    list.deleteFromPosition(2);

    cout << "After deleting position 2:" << endl;
    list.displayForward();


    // Search
    cout << endl;
    list.search(30);


    // Update
    cout << endl;
    list.update(1, 100);

    cout << "After updating position 1:" << endl;
    list.displayForward();


    // Count nodes
    cout << endl;
    cout << "Total Nodes: "
         << list.countNodes() << endl;


    return 0;
}


