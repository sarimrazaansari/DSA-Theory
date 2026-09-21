#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int value):data(value),next(nullptr){}

};

class Stack{
    Node *top;

    public:
        Stack():top(nullptr){}

        void push(int data){
            Node* newNode= new Node(data);

            newNode->next=top;
            top=newNode;
        }

        void pop(){

            if(top==nullptr){
                cout<<"Stack is empty\n";
                return;
            }

            Node* temp=top;

            top=top->next;
            delete temp;
        }

        void peek(){
            if(top==nullptr){
                cout<<"Stack is empty\n";
                return;
            }
            cout<<"peek: "<<top->data;
        }

        void display(){
            if(top==nullptr){
                cout<<"Stack is empty\n";
                return;
            }
            for(Node* temp=top ; temp!=nullptr ; temp=temp->next){
                cout<<temp->data<<endl;
            }
        }

        bool isEmpty(){
            return top==nullptr;
        }


};

int main(){
    Stack l;

    l.push(1);
    l.push(2);
    l.push(3);

    l.display();
    l.pop();

    l.display();

    l.peek();

    cout<<(l.isEmpty()? "True":"False");
}