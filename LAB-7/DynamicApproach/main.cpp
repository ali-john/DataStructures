#include <iostream>
using namespace std;

template<class T>
        struct Node
        {
            T data;
            Node *link;
        };
template<class T>
class DynamicQueue
{
public:
    Node<T> *rear;
    Node<T> *front;

    DynamicQueue()//constructor
    {
        rear=NULL;
        front=NULL;
    }
    DynamicQueue(DynamicQueue<T> const &obj)//copy constructor
    {
        Node<T> *temp=obj.front;//points to start of queue
        Node<T> *prevLink=NULL;
        while(temp!=NULL)//continue copying till last node
        {
            if (temp==obj.front)//copying first node
            {
                Node<T> *NewNode=new Node<T>;
                NewNode->data=temp->data;
                NewNode->link=NULL;
                prevLink=NewNode;
                front=NewNode;
                temp=temp->link;
            }
            else
            {
                Node<T> *NewNode=new Node<T>;
                NewNode->data=temp->data;
                NewNode->link=NULL;
                prevLink->link=NewNode;
                prevLink=NewNode;
                temp=temp->link;
            }

        }
    }
    void Enqueue(T value)//insert a value in queue
    {
        Node<T> *NewNode=new Node<T>;
        NewNode->data=value;
        if(isEmpty())//it means inserting first node of queue
        {
            NewNode->link=NULL;
            rear=NewNode;
            front=NewNode;
        }
        else
        {
            NewNode->link=NULL;
            rear->link=NewNode;//make connection from previous node
            rear=NewNode;
        }

    }
    void Dequeue()//to delete value from start of queue
    {
        if(isEmpty())
        {
            cout<<"Queue underflow"<<endl;
        }
        else if(front->link==NULL)//A single node in queue
        {
            cout << "Value " << front->data << " dequeued from queue" << endl;
            delete front;
            front=NULL;
            rear=NULL;
        }
        else
        {
            cout << "Value " << front->data << " dequeued from queue" << endl;
            Node<T> *temp=front;
            front=front->link;
            delete temp;
        }
    }
    void Display()//gets the first element of queue. eg if queue is 1->2->3->4->5 then this fun will give 1
    {
        if(isEmpty())
        {
            cout<<"DynamicQueue is empty"<<endl;
        }
        else
        {
            cout << "Front element of queue is:  " << front->data << endl;
        }
    }
    //isEmpty function that checks if queue is empty or not
    bool isEmpty()
    {
        if (rear==NULL && front==NULL)
            return true;
        else
            return false;
    }
    ~DynamicQueue()//destructor
    {
        Node<T> *temp=front;
        Node<T> *prev;
       while (temp!=NULL)
       {
           prev=temp;
           temp=temp->link;
           delete prev;
       }


    }
};
int main()
{
    DynamicQueue<double> myQueue;
    cout<<"Element 1-5 enqueued"<<endl;
    double j=0.0;
    for (int i = 0; i < 5; i++)//insert 1-5 elements in queue
    {
        j=j+1;
        myQueue.Enqueue(j);
    }
    cout<<"Calling deque"<<endl;
    myQueue.Dequeue();
    cout<<"Enqueue 6 in queue"<<endl;
    myQueue.Enqueue(6);
    cout<<"Continuously calling deque"<<endl;
    for (int i = 0; i < 6; i++)
    {
        myQueue.Dequeue();
    }
    cout<<"Enqueue 7 in queue"<<endl;
    myQueue.Enqueue(7);
    cout<<"Enqueue 8 in queue"<<endl;
    myQueue.Enqueue(8);
    cout<<"Calling display "<<endl;
    myQueue.Display();
    cout<<"Created copy of myQueue"<<endl;
    DynamicQueue<double> myQueue2=myQueue;
    cout<<"Checking copy constructor by dequeue myQueue2"<<endl;
    myQueue2.Dequeue();
    myQueue2.Dequeue();
    myQueue2.Dequeue();

    return 0;
}
