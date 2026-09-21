#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d):data(d),next(nullptr){}

};

Node* middleNode(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
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
    head->next->next->next->next->next = new Node(6);

    print(head);

    Node* middle=middleNode(head);

    cout<<middle->data<<endl;
}

