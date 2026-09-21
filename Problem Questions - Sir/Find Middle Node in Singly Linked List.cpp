#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* findMiddle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    // fast 2 steps aur slow 1 step chalega
    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {

    // Linked List:
    // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Node* middle = findMiddle(head);

    cout << "Middle Node = " << middle->data << endl;

    return 0;
}
