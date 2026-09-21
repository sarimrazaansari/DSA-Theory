#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data):data(data),next(nullptr),prev(nullptr){}
};

class DoublyLinkedList{
    Node* head;
    Node* tail;

    public:
        DoublyLinkedList():head(nullptr),tail(nullptr){}

        void insertAtBeginning(int value){
            Node* newNode=new Node(value);

            if(head==nullptr){
                head=newNode;
                tail=newNode;
                return;
            }

            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }

        void insertAtEnd(int value){
            Node* newNode=new Node(value);
            if(head==nullptr){
                head=newNode;
                tail=newNode;
                return;
            }

            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }

        void insertAtPosition(int value, int pos){
            //Position Starts from 1 not 0 -> First index = 1
            if(pos<1){
                cout<<"Invalid postion!"<<endl;
                return;
            }
            else if(pos==1){
                insertAtBeginning(value);
                return;
            }

            Node* temp= head;

            for(int i=1;temp!=nullptr && i<pos-1;i++){
                temp=temp->next;
            }

            if(temp==nullptr){
                insertAtEnd(value);
                return;
            }

            Node* newNode=new Node(value);

            newNode->next=temp->next;
            temp->next->prev=newNode;
            temp->next=newNode;
            newNode->prev=temp;

        }

        void deleteFromBeginning(){
            if(head==nullptr){
                cout<<"List is empty"<<endl;
                return;
            }

            Node* temp=head;

            if(head==tail){
                head=tail=nullptr;
                delete temp;
                return;
            }
            
            head=head->next;
            head->prev=nullptr;
            delete temp;

        }

        void deleteFromEnd(){
            if(head==nullptr){
                cout<<"List is MT\n";
                return;
            }

            Node*temp = tail;
            if(head==tail){
                head=tail=nullptr;
                delete temp;
                return;
            }

            tail=tail->prev;
            tail->next=nullptr;
            delete temp;
        }

        void deleteFromPosition(int pos){
            if(head==nullptr){
                cout<<"List is MT\n";
                return;
            }

            if(pos<1){
                cout<<"Invalid Postion!"<<endl;
                return;
            }

            else if(pos==1){
                deleteFromBeginning();
            }
            
            Node* temp=head;

            for(int i=1; i<pos && temp!=nullptr;i++){
                temp=temp->next;
            }
            if(temp==nullptr){
                cout<<"Position out of Bound!\n";
            }

            if(temp==tail){
                deleteFromEnd();
                return;
            }

            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;

            delete temp;
        }

        bool searchKey(int key){
            for(Node* temp=head ; temp!=nullptr ; temp=temp->next){
                if(temp->data==key){
                    return true;
                }  
            }
            return false;
        }

        void displayForward(){

            if(head==nullptr){
                cout<<"List is MT!\n";
            }

            for(Node* temp=head ; temp!=nullptr ; temp=temp->next){
                cout<<temp->data<<" ";
            }
            cout<<endl;
        }

        void displayBackward(){

            if(head==nullptr){
                cout<<"List is MT!\n";
            }

            for(Node* temp=tail ; temp!=nullptr ; temp=temp->prev){
                cout<<temp->data<<" ";
            }
            cout<<endl;
        }

        int countNode(){
            int count=0;
            for(Node* temp=head ; temp!=nullptr ; temp=temp->next){
                count++;
            }
            return count;
        }

        void updateValue(int value, int pos){
            if(pos<1){
                cout<<"Invalid Position\n";
                return;
            }
            int count=1;
            for(Node* temp = head ; temp!=nullptr;temp=temp->next){
                if(count==pos){
                    temp->data=value;
                    cout<<"Node Updated!\n";
                    return;
                }
                count++;
            }
            cout<<"Invalid positionss!\n";
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
    cout<<(list.searchKey(30)? "True": "False")<<endl;


    // Update
    list.updateValue(100, 1);

    list.displayForward();


    // Count nodes
    cout << "Total Nodes: "
         << list.countNode() << endl;

    return 0;
}