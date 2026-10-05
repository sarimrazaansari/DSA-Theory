#include "iostream"
using namespace std;

class Queue{
    int arr[5];
    int front;
    int rear;

    public:
        Queue():front(-1),rear(-1){}

        bool isFull(){return rear==4;}
        bool isEmpty(){return front==-1 | front>rear;}
        void enqueue(int data){
            if(rear==4){
                cout<<"Overflow!"<<endl;
                return;
            }

            if(front==-1){
                front=0;
            }

            arr[++rear]=data;
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"Empty!"<<endl;
            }

            front++;
        }

        void display(){
            for(int i=front ; i<=rear ; i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }

        void peek(){
            cout<<arr[front]<<endl;
        } 
};

class Node{
    public:
        int data;
        Node* next;

        Node(int d):data(d),next(nullptr){}
};

class QueueLL{
    Node* front;
    Node* rear;

    public:
        QueueLL():front(nullptr),rear(nullptr){}

        bool isEmpty(){return front==nullptr;}

        void enqueue(int data){
            Node* temp= new Node(data);

            if(isEmpty()){
                front=rear=temp;
            }

            rear->next=temp;
            rear=temp;
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"MT"<<endl;
                return;
            }

            Node* temp =front;
            front=front->next;
            delete temp;
        }

        void display(){
            if(isEmpty()){
                cout<<"MT"<<endl;
                return;
            }

            for(Node* temp= front ; temp ; temp=temp->next ){
                cout<<temp->data<<" ";
            }

        }

        void peek(){
            cout<<front->data;
        }
};

class QueueCircular{
    int arr[5];
    int front;
    int rear;
    int size;

    public:
        QueueCircular():front(-1),rear(-1),size(5){}

        bool isFull(){
        return (rear + 1) % size == front;
        }

        bool isEmpty(){return front==-1;}

        void enqueue(int data){
            if(isFull()){
                cout<<"Full\n";
                return;
            }

            if(isEmpty()){
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
                cout<<"MT\n";
                return;
            }

            if (front==rear)
            {
                front=rear=-1;
            }
            else{
                front=(front+1)%size;
            }
            
            
        }

        void peek(){
            cout<<arr[front]<<endl;
        }

        void display(){
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % size;
            }
        cout << endl;
        }
};

int main(){
    QueueCircular q;

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

    return 0;
}