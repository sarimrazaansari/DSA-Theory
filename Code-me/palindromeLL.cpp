#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d):data(d),next(nullptr){}
};

Node* middleLL(Node* head){
    Node* slow=head;
    Node* fast=head;

    //finding 2nd last or last node even and odd respectively
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* reverseLL(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    Node* next;

    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }
    return prev;
}

bool isPalindrome(Node* head){
    Node* middle=middleLL(head);
    Node* second=reverseLL(middle->next);

    Node* first=head;
    
    while(second!=nullptr){
        if(first->data!=second->data) return false;
        first=first->next;
        second=second->next;
    }
    return true;

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
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    print(head);

    cout<<(isPalindrome(head)?"True":"False")<<endl;

    
}

