#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
public:
    Node* root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        Node* n = new Node(value);

        if (root == nullptr)
        {
            root = n;
            return;
        }

        Node* q[100];
        int front = 0, rear = 0;
        q[rear++] = root; //push root in queue

        while (front < rear)
        {
            Node* current = q[front++]; //pop queue element into currect

            if (current->left == nullptr) //check left
            {
                current->left = n; 
                return;
            }
            q[rear++] = current->left; //if not then push in queue

            if (current->right == nullptr) //check right 
            {
                current->right = n;
                return;
            }
            q[rear++] = current->right; //if not then push in queue
        } // and the cycle continues
    }

    bool search(int key)
    {
        if (root == nullptr)
            return false;

        Node* q[100];
        int front = 0, rear = 0;
        q[rear++] = root;

        while (front < rear)
        {
            Node* current = q[front++];

            if (current->data == key) //we only check current; No need to check right and left
                return true;

            if (current->left != nullptr)
                q[rear++] = current->left;

            if (current->right != nullptr)
                q[rear++] = current->right;
        }

        return false;
    }

    bool update(int oldValue, int newValue)
    {
        if (root == nullptr)
            return false;

        Node* q[100];
        int front = 0, rear = 0;
        q[rear++] = root;

        while (front < rear)
        {
            Node* current = q[front++];

            if (current->data == oldValue)
            {
                current->data = newValue;
                return true;
            }

            if (current->left != nullptr)
                q[rear++] = current->left;

            if (current->right != nullptr)
                q[rear++] = current->right;
        }

        return false;
    }

    //check sir delete one
    bool deleteValue(int key)
    {
        if (root == nullptr)
            return false;

        Node* q[100];
        Node* parent[100];

        int front = 0, rear = 0;
        q[rear] = root;
        parent[rear++] = nullptr;

        Node* target = nullptr;
        Node* targetParent = nullptr;
        Node* deepest = nullptr;
        Node* deepestParent = nullptr;

        while (front < rear)
        {
            Node* current = q[front];
            Node* currentParent = parent[front];
            front++;

            if (target == nullptr && current->data == key)
            {
                target = current;
                targetParent = currentParent;
            }

            deepest = current;
            deepestParent = currentParent;

            if (current->left != nullptr)
            {
                q[rear] = current->left;
                parent[rear++] = current;
            }

            if (current->right != nullptr)
            {
                q[rear] = current->right;
                parent[rear++] = current;
            }
        }

        if (target == nullptr)
            return false;

        if (target == deepest)
        {
            if (deepestParent == nullptr)
                root = nullptr;
            else if (deepestParent->left == deepest)
                deepestParent->left = nullptr;
            else
                deepestParent->right = nullptr;

            delete deepest;
            return true;
        }

        target->data = deepest->data;

        if (deepestParent->left == deepest)
            deepestParent->left = nullptr;
        else
            deepestParent->right = nullptr;

        delete deepest;
        return true;
    }

    void preOrder(Node* current)
    {
        if (current == nullptr)
            return;

        cout << current->data << " ";
        preOrder(current->left);
        preOrder(current->right);
    }

    void inOrder(Node* current)
    {
        if (current == nullptr)
            return;

        inOrder(current->left);
        cout << current->data << " ";
        inOrder(current->right);
    }

    void postOrder(Node* current)
    {
        if (current == nullptr)
            return;

        postOrder(current->left);
        postOrder(current->right);
        cout << current->data << " ";
    }

    void display()
    {
        cout << "\nPreorder: ";
        preOrder(root);

        cout << "\nInorder: ";
        inOrder(root);

        cout << "\nPostorder: ";
        postOrder(root);

        cout << endl;
    }

    void clear(Node* current)
    {
        if (current == nullptr)
            return;

        clear(current->left);
        clear(current->right);
        delete current;
    }

    ~BinaryTree()
    {
        clear(root);
    }
};


int main()
{
    BinaryTree t;

    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);

    cout << "Binary Tree Traversals:\n";
    t.display();

    cout << "\nSearch 40: ";
    cout << (t.search(40) ? "Found" : "Not Found") << endl;

    cout << "\nUpdate 20 to 25:\n";
    cout << (t.update(20, 25) ? "Updated" : "Not Found") << endl;
    t.display();

    cout << "\nDelete 30:\n";
    cout << (t.deleteValue(30) ? "Deleted" : "Not Found") << endl;
    t.display();

    return 0;
}

