#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d):data(d),next(nullptr){}
};

Node* reverseLL(Node* head){
    Node* current=head;
    Node* prev = nullptr;
    Node* next = nullptr;

    //at last next willbe out of the list and prev becomes last node
    while(current!=nullptr){
        next=current->next;
        current->next=prev;

        prev=current;
        current=next;
    }    
    return prev;
}

void print(Node* head){
    for(Node* temp= head; temp!=nullptr; temp=temp->next){
        cout<<temp->data<<" ";
    }
    cout<<"\n";
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    print(head);

    head=reverseLL(head);

    print(head);
}