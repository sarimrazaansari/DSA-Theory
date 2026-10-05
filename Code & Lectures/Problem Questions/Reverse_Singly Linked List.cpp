#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int new_data) {
        data = new_data;
        next = NULL;
    }
};

Node *reverseList(Node *head) {

    Node *curr = head, *prev = NULL, *next;

    // Traverse all the nodes of Linked List
    while (curr != NULL) {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data;
        if (node->next)
            cout << " -> ";
        node = node->next;
    }
}

int main() {

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    printList(head);
    
    cout<<"\n";

    head = reverseList(head);

    printList(head);

    return 0;
}
