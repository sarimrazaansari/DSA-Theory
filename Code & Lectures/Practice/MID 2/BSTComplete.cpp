#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data):data(data){
            left=right=nullptr;
        }
};

class BST{
    Node *root;
    
    Node* insertNode(Node* node, int value){
        if(node == NULL) return new Node(value); //inserting

        if(value<node->data)
            node->left=insertNode(node->left,value);
        if(value>node->data)
            node->right=insertNode(node->right,value);

        return node; //returning root
    }

    bool searchNode(Node* node, int key){
        if(node == NULL) return false;

        if(node->data==key) return true;

        if(key<node->data) 
            return searchNode(node->left,key);
        //if(key>node->data)
            return searchNode(node->right,key);
    }

    Node* IS(Node* node){
        while(node->left!=NULL && node!=NULL){
            node=node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int key){
        if(node==NULL) return NULL;

        if(key<node->data)
            node->left=deleteNode(node->left,key);
        if(key>node->data)
            node->right=deleteNode(node->right,key);
        
        else{
            //case 1 and 2
            if(node->left==NULL){ 
                Node* temp= node->right; //preserve right
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                Node* temp=node->left; //preserve left
                delete node;
                return temp;
            }

            //case 3
            
                Node* successor=IS(node->right);
                node->data=successor->data;
                node->right=deleteNode(node->right,successor->data); //deleting successor finding by its value
            
        }
        return node;
    }

    void inOrder(Node* node){
            if(node==NULL) return;

        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }

    public:

        BST(){root=NULL;}

        void insert(int data){
            root = insertNode(root,data);
        }

        bool search(int data){
            return searchNode(root,data);
        }
        void remove(int data){
            root=deleteNode(root,data);
        }

        void sort(){
            inOrder(root);
            cout<<endl;
        }

};

int main(){
    BST tree;

    int values[] = {
        16, 5, 7, 20, 3, 11, 4, 18, 48, 56, 36
    };

    int n = sizeof(values) / sizeof(values[0]);

    // 1. Build the BST
    for (int i = 0; i < n; i++) {
        tree.insert(values[i]);
    }

    cout << "Sorted values: ";
    tree.sort();

    // 2. Search for 11
    int key = 11;

    if (tree.search(key)) {
        cout << key << " found in the BST." << endl;
    }
    else {
        cout << key << " not found in the BST." << endl;
    }

    // 3. Insert 13
    tree.insert(13);

    cout << "After inserting 13: ";
    tree.sort();

    // 4. Delete 20
    tree.remove(20);

    cout << "After deleting 20: ";
    tree.sort();

    return 0;
}