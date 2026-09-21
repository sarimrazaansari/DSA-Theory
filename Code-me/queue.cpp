#include <iostream>
using namespace std;

class QueueArr{
    int arr[5];
    int front;
    int rear;

    public:
        QueueArr():front(-1),rear(-1){}

        void enqueue(int data){
            if(rear==4){
                cout<<"Queue is full\n";
                return;
            }

            if(front==-1) front=0;

            arr[++rear]=data;

        }

        void dequeue(){
            if(front==-1 || front>rear){
                cout<<"Queue is empty\n";
                return;
            }
            front++;
        }

        void peek(){
            if(front==-1 || front>rear){
                cout<<"Queue is empty\n";
                return;
            }

            cout<<"Peek: "<<arr[front]<<endl;
        }

        void display(){
            if(front==-1 || front>rear){
                cout<<"Queue is empty\n";
                return;
            }

            for(int i = front ; i <=rear ; i++){
                cout<<arr[i]<<endl;
            }
            cout<<endl;
        }

        bool isEmpty(){
            return front==-1 || front>rear;
        }
        bool isFull(){
            return rear==4;
        }
};

class Node{
    public:
        int data;
        Node* next;

        Node(int data):data(data),next(nullptr){}
};

class QueueLL{
    Node* front;
    Node* rear;

    public:
        QueueLL():front(nullptr),rear(nullptr){}

        void enqueue(int data){

            Node* newNode=new Node(data);

            if(rear==nullptr){
                front=rear=newNode;
            }


            rear->next=newNode;
            rear=newNode;
        }

        void dequeue(){
            if(front==nullptr){
                cout<<"Queue is empty\n";
                return;
            }

            Node* temp= front;
            front=front->next;

            if(front==nullptr){
                rear=nullptr;
            }

            delete temp;

        }

        void peek(){
            if(front==nullptr){
                cout<<"Queue is empty\n";
                return;
            }

            cout<<"peek: "<<front->data<<endl;
        }

        void display(){
            if(front==nullptr){
                cout<<"Queue is empty\n";
                return;
            }

            for(Node* temp=front ; temp!=nullptr ; temp=temp->next){
                cout<<temp->data<<" ";
            }
            cout<<endl;
        }

        bool isEmpty(){
            return front==nullptr;
        }
};

class CircularQueue{
    int arr[5];
    int front;
    int rear;
    int size;

    public:
        CircularQueue():front(-1),rear(-1),size(5){}

        bool isEmpty(){
            return front == -1;
        }
        bool isFull(){
            return (rear+1)%size==front;
        }

        void enqueue(int data){
            if(isFull()){
                cout<<"Queue is Full\n";
                return;
            }

            if(front==-1){
                front=0;
                rear=0;
            }
            else{
                rear=(rear+1)%size;
            }

            arr[rear]=data;
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty\n";
            }
            if(front==rear){    //single element
                front=rear=-1;
            }

            front=(front+1)%size;
            
        }

        void peek(){
            if(isEmpty()){
                cout<<"Queue is Empty\n";
            }
            cout<<"peek: "<<arr[front]<<endl;
        }

        void display(){
            if(isEmpty()){
                cout<<"Queue is Empty\n";
            }

            for (int i = front; i!=rear; (i+1)%size){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            
        }
};

int main(){

    cout<<"=====Array=====\n";
    QueueArr q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << endl;

    q.display();

    cout << endl;

    q.peek();

    cout << endl;

    q.dequeue();

    cout << endl;

    q.display();

    cout<<"=====LL=====\n";

    QueueLL q2;
    q2.enqueue(10);
    q2.enqueue(20);
    q2.enqueue(30);

    cout << endl;

    q2.display();

    cout << endl;

    q2.peek();

    cout << endl;

    q2.dequeue();

    cout << endl;

    q2.display();

    cout<<"=====Circular QUEUE=====\n";
    QueueLL q3;
    q3.enqueue(10);
    q3.enqueue(20);
    q3.enqueue(30);

    cout << endl;

    q3.display();

    cout << endl;

    q3.peek();

    cout << endl;

    q3.dequeue();

    cout << endl;

    q3.display();



    return 0;
}