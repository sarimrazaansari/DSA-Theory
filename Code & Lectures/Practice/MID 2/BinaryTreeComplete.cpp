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

class BinaryTree{
    Node *root;

    public:
        BinaryTree():root(nullptr){}

        void insert(int value){
            Node* n= new Node(value);

            if(root==nullptr){
                root=n;
                return;
            }

            Node* q[100];
            int front=0, rear=0;

            q[rear++]=root;

            while(front<rear){
                Node* current=q[front++];

                if(current->left==nullptr){
                    current->left=n;
                    return;
                }
                q[rear++]=current->left;

                if(current->right==nullptr){
                    current->right=n;
                    return;
                }
                q[rear++]=current->right;

            }

        }

        bool search(int key){
            if(root==nullptr) return false;

            Node* q[100];
            int front=0 ,rear=0;

            q[rear++]=root;
            while(front<rear){
                Node* current=q[front++];

                if(current->data==key) return true;

                if(current->left!=nullptr) q[rear++]=current->left;
                if(current->right!=nullptr) q[rear++]=current->right;
            }

            return false;
        }

        bool update(int oldValue, int newValue){
            if(root==nullptr) return false;

            Node* q[100]; int front=0,rear=0;
           
            q[rear++]=root;
            
            while(front<rear){
                Node* current= q[front++];

                if(current->data==oldValue){
                    current->data=newValue;
                    return true;
                }

                if(current->left!=nullptr) q[rear++]=current->left;
                if(current->right!=nullptr) q[rear++]=current->right;
            }
            return false;
        }   

        //delete value
        void deepestDelete(Node* current,Node* deepest){ //find deepest and delete
            if(current==nullptr) return;   
            
            if(current->left==deepest){
                current->left=nullptr;
                delete deepest;
                return;
            }

            if(current->right==deepest){
                current->right=nullptr;
                delete deepest;
                return;
            }

            deepestDelete(current->left,deepest);
            deepestDelete(current->right,deepest);
        }

        bool deleteValue(int key){
            if(root==nullptr){
                return false;
            }

            if(root->left==nullptr && root->right==nullptr){
                if(root->data==key){
                    cout<<"CAnt delete root!"<<endl;
                    return false;
                }
            }

            Node* target=nullptr;
            Node* deepest=nullptr;

            Node* q[100];   int front=0, rear=0;
            q[rear++]=root;

            while(front<rear){
                Node* current= q[front++];

                if(current->data==key && target==nullptr){
                    target=current;
                }
                deepest=current; //finding last node so far

                if(current->left!=nullptr) q[rear++]=current->left;
                if(current->right!=nullptr) q[rear++]=current->right;
            }

            if(target==nullptr){
                cout<<"No element found!"<<endl;
                return false;
            }

            
            if(target==deepest){
                deepestDelete(root, deepest);
                return true;
            }
            
            //start moving target data and deepest 
            int deepestValue = deepest->data;
            deepestDelete(root, deepest);
            target->data = deepestValue;


            cout << "Node deleted successfully.\n";
            return true;
        }

        void preOrder(Node* current){
            if(current==nullptr) return;

            // root left right

            cout<<current->data<<" ";
            preOrder(current->left);
            preOrder(current->right);
        }

        void inOrder(Node* current){
            if(current==nullptr) return;

            // left root right

            inOrder(current->left);
            cout<<current->data<<" ";
            inOrder(current->right);
        }
        void postOrder(Node* current){
            if(current==nullptr) return;

            // left right root

            postOrder(current->left);
            postOrder(current->right);
            cout<<current->data<<" ";
        }

        void display(){
            cout<<"\n PreOrder :";
            preOrder(root);
            cout<<"\n InOrder :";
            inOrder(root);
            cout<<"\n PostOrder :";
            postOrder(root);

            cout<<endl;
        }

        void clear(Node* current)
        {
            if (current == nullptr)
                return;

            clear(current->left);
            clear(current->right);
            delete current;
        }

        ~BinaryTree(){
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
    cout << (t.deleteValue(25) ? "Deleted" : "Not Found") << endl;
    t.display();

    return 0;
}


