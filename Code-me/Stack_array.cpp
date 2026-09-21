#include <iostream>
using namespace std;

class Stack{
    int arr[5];
    int top;

    public:
        Stack():top(-1){}

        void push(int value){
            if(top==4){
                cout<<"Stack is full\n";
                return;
            }

            arr[++top]=value;
        }

        void pop(){
            if(top==-1){
                cout<<"stack is empty\n";
                return;
            }

            top--;
        }

        void peek(){
            if(top==-1){
                cout<<"stack is empty\n";
                return;
            }

            cout<<"peek: "<<arr[top]<<endl;
        }

        bool isEmpty(){
            return top==-1;
        }

        bool isFull(){
            return top==4;
        }

        void display(){
            if(top==-1){
                cout<<"stack is empty\n";
                return;
            }

            for(int i=top; i>=0; i--){
                cout<<arr[i]<<endl;
            }

        }

};

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    s.display();

    s.pop();
    s.display();

    s.peek();

    cout<<s.isEmpty();
    cout<<s.isFull();
}