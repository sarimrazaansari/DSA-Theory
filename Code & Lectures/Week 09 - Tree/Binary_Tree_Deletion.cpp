#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Find the deepest rightmost node and delete it
void deleteDeepest(Node* root, Node* deepest) { // the deepest is genereated by the functon below
    if (root == NULL)
        return;

    if (root->left == deepest) {
        root->left = NULL;
        delete deepest;
        return;
    }

    if (root->right == deepest) {
        root->right = NULL;
        delete deepest;
        return;
    }

    deleteDeepest(root->left, deepest);
    deleteDeepest(root->right, deepest);
}

// Replace the deleted data with the righmost and delete rightmost from above funct

void deleteNode(Node* root, int value) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) { //if root has no child
        if (root->data == value) {
            cout << "Root is the only node. Handle root deletion separately.\n";
        }
        return;
    }

    Node* target = NULL; // to replace with deepest one
    Node* deepest = NULL; // actual deepest right most

    //searching/traversing deepest and target
    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        if (current->data == value && target == NULL) //find target 
            target = current;

        deepest = current; //preserving deepest right most

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    if (target == NULL) {
        cout << "Value not found.\n";
        return;
    }

    // moving deepest.data in the target then deleting deepest.node

    int deepestValue = deepest->data;
    deleteDeepest(root, deepest);
    target->data = deepestValue;

    cout << "Node deleted successfully.\n";
}



int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    cout << "Before deletion (Level Order): ";
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];
        cout << current->data << " ";

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    cout << "\n";

    deleteNode(root, 20);

    cout << "After deletion (Level Order): ";
    front = 0;
    rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];
        cout << current->data << " ";

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    cout << "\n";

    return 0;
}
