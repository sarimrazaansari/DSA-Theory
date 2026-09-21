#include <iostream>
using namespace std;

// Node class for Doubly Linked List
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


class DoublyLinkedList {
private:
    Node* head;     //head = first element
    Node* tail;     //tail = last element

public:

    // Constructor
    DoublyLinkedList() {
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
        }
        else {
            newNode->next = head;
            head->prev = newNode;
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
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
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

        Node* temp = head;

        // Position se previous node tak jana hai
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        // Agar end par insert ho raha hai
        if (temp == tail) {
            insertAtEnd(value);
            return;
        }

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
            head->prev = NULL;
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
            tail->next = NULL;
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

        // Required position tak jana hai
        for (int i = 1; i < position && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
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

        Node* temp = head;
        int position = 1;

        while (temp != NULL) {

            if (temp->data == value) {
                cout << value << " found at position "
                     << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << value << " not found!" << endl;
    }


    // 8. Display Forward
    void displayForward() {

        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Forward: NULL <-> ";

        while (temp != NULL) {

            cout << temp->data;

            if (temp->next != NULL) {
                cout << " <-> ";
            }

            temp = temp->next;
        }

        cout << " <-> NULL" << endl;
    }


    // 9. Display Backward
    void displayBackward() {

        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = tail;

        cout << "Backward: NULL <-> ";

        while (temp != NULL) {

            cout << temp->data;

            if (temp->prev != NULL) {
                cout << " <-> ";
            }

            temp = temp->prev;
        }

        cout << " <-> NULL" << endl;
    }


    // 10. Count Nodes
    int countNodes() {

        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }


    // 11. Update a Node
    void update(int position, int value) {

        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }

        temp->data = value;

        cout << "Node updated successfully!" << endl;
    }
};


int main() {

    DoublyLinkedList list;

    // Insert at beginning
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    // Insert at end
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.displayForward();
    list.displayBackward();


    // Insert at specific position
    list.insertAtPosition(25, 3);

    list.displayForward();


    // Delete from beginning
    list.deleteFromBeginning();

    list.displayForward();


    // Delete from end
    list.deleteFromEnd();

    list.displayForward();


    // Delete from specific position
    list.deleteFromPosition(2);

    list.displayForward();


    // Search
    list.search(30);


    // Update
    list.update(1, 100);

    list.displayForward();


    // Count nodes
    cout << "Total Nodes: "
         << list.countNodes() << endl;

    return 0;
}
