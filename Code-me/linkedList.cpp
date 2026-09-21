#include "iostream"
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data):data(data),next(nullptr){}
};

class LinkedList{
    Node *head;

    public:
        LinkedList():head(nullptr){}
        ~LinkedList(){clear(); cout<<"cleard!\n";}

        void insertAtEnd(int data){
            Node* newNode=new Node(data);

            if(head==nullptr){
                head=newNode;
                return;
            }

            Node* temp=head;

            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;   
        }

        void insertAtBegining(int data){
            Node* newNode=new Node(data);

            newNode->next=head;
            head=newNode;
        }

        void insertAfter(int data, int pos){
            Node* temp=head;
            int index=0;
            while(temp!=nullptr && index<pos){
                temp=temp->next;
                index++;
            }

            if(temp!=nullptr){
                Node* newNode=new Node(data);
                newNode->next=temp->next;
                temp->next=newNode;
            }
            else cout<<"Position out of bound!"<<endl;
        }

        bool SearchForKey(int key){
            Node* temp=head;
            while (temp!=nullptr){
                if(temp->data==key){
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }

        void display(){
            Node*temp =head;

            while (temp!=nullptr){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<"\n";
            
        }

        void deleteFromEnd(){
            Node* temp=head;

            if(head==nullptr) return;
            if(head->next==nullptr){
                delete head;
                head=nullptr;
                return;
            }

            while(temp->next->next!=nullptr){
                temp=temp->next;
            }
            delete temp->next;
            temp->next=nullptr;
        }

        void deleteFromStart(){
            if (head==nullptr) return;

            Node*temp =head;
            head=head->next;
            delete temp;
        }

        void deleteAfter(int pos){
            Node* temp=head;
            int index=0;

            while(temp!=nullptr && index<pos){
                temp=temp->next;
                index++;
            }

            if (temp!=nullptr && temp->next!=nullptr){
                Node* NodeToDelete=temp->next;

                temp->next=NodeToDelete->next;
                delete NodeToDelete;
            }
            else cout<<"Position out of Bound!!!\n";
            return;
        }

        void clear(){
            Node* temp=head;
            while (temp!=nullptr){
                Node* toDelete=temp->next;
                delete temp;
                toDelete=temp;
            }
            
        }
};

int main(){
    LinkedList list;

    list.insertAtBegining(1);
    list.insertAtBegining(2);
    list.insertAtBegining(3);

    list.display();

    list.insertAtBegining(0);
    list.display();

    list.insertAfter(7, 2);
    list.display();

    cout << "Searching for 2: "
         << (list.SearchForKey(2) ? "Found" : "Not Found")
         << endl;

    list.deleteFromEnd();
    list.display();

    list.deleteFromEnd();
    list.display();

    list.deleteAfter(1);
    list.display();
    
}