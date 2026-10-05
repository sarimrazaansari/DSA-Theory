#include "iostream"
using namespace std;

class Stack{
    int arr[5];
    int top;

    public:
        Stack():top(-1){}
        
        void push(int data){
            if(top==4){
                cout<<"Overflow! "<<endl;
                return;
            }

            arr[++top]=data;
        }

        void pop(){
            if(top==-1){
                cout<<"Empty"<<endl;
                return;
            }

            top--;
        }

        void peek(){
            cout<<"Peek: "<<arr[top];
        }

        bool isEmpty(){
            return top==-1;
        }
        bool isFull(){
            return top==4;
        }

        void display(){
            for(int i = top ;i>=0; i--){
                cout<<arr[i]<<" ";
            }
        }

};

class Node{
    public:
    int data;
    Node* next;

        Node(int v):data(v),next(nullptr){}
};

class StackLL{
    Node* top;

    public:
        StackLL():top(nullptr){}

        void push(int data){
            Node* newNode=new Node(data);

            newNode->next=top;
            top=newNode;

        }

        void pop(){

            if(top==nullptr){
                cout<<"Empty!"<<endl;
            }
            Node * temp=top;

            top=top->next;
            delete temp;
        }

        void peek(){
            cout<<top->data<<endl;
        }

        bool isEmpty(){return top==nullptr;}

        void display(){
            for (Node* temp = top; temp ; temp=temp->next)
            {
                cout<<temp->data<<" ";
            }
            cout<<"\n";
        }


};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << endl;
    s.display();

    cout << endl;
    s.peek();

    cout << endl;
    s.pop();

    cout << endl;
    s.display();



    return 0;
}