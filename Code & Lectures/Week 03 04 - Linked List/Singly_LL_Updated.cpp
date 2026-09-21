#include <iostream>

using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) : data(data), next(nullptr) {}
};

// SinglyLinkedList class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() : head(nullptr) {}

    // Destructor
    ~SinglyLinkedList() {
        clear();
    }

    // Insert at the end
    void InsertionAtTail(int data) {
        Node* newNode = new Node(data);

        // If list is empty
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at the start
    void InsertionAtStart(int data) {
        Node* newNode = new Node(data);

        newNode->next = head;
        head = newNode;
    }

    // Insert after a specific position
    void InsertAfter(int position, int data) {
        Node* temp = head;
        int index = 0;

        while (temp != nullptr && index < position) {
            temp = temp->next;
            index++;
        }

        if (temp != nullptr) {
            Node* newNode = new Node(data);

            newNode->next = temp->next;
            temp->next = newNode;
        }
        else {
            cout << "Position out of bounds.\n";
        }
    }

    // Search for a key
    bool SearchingForKey(int key) const {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // Display the list
    void Display() const {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Delete from the end
    void DeletionFromEnd() {
        // Empty list
        if (head == nullptr) {
            return;
        }

        // Only one node
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        // Find second-last node
        Node* temp = head;

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        // Delete last node
        delete temp->next;

        // Make second-last node the last node
        temp->next = nullptr;
    }

    // Delete from the start
    void DeletionFromStart() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;

        head = head->next;

        delete temp;
    }

    // Delete node after a specific position
    void DeleteAfter(int position) {
        Node* temp = head;
        int index = 0;

        while (temp != nullptr && index < position) {
            temp = temp->next;
            index++;
        }

        if (temp != nullptr && temp->next != nullptr) {
            Node* nodeToDelete = temp->next;

            temp->next = nodeToDelete->next;

            delete nodeToDelete;
        }
        else {
            cout << "Position out of bounds or no node to delete.\n";
        }
    }

    // Clear the entire list
    void clear() {
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next;

            delete current;

            current = nextNode;
        }

        head = nullptr;
    }
};

int main() {
    SinglyLinkedList list;

    list.InsertionAtTail(1);
    list.InsertionAtTail(2);
    list.InsertionAtTail(3);

    list.Display();

    list.InsertionAtStart(0);
    list.Display();

    list.InsertAfter(2, 5);
    list.Display();

    cout << "Searching for 2: "
         << (list.SearchingForKey(2) ? "Found" : "Not Found")
         << endl;

    list.DeletionFromEnd();
    list.Display();

    list.DeletionFromStart();
    list.Display();

    list.DeleteAfter(1);
    list.Display();

    list.clear();

    cout << "List cleared.\n";

    return 0;
}