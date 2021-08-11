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
    //code start

    void Sorting(Node<T> *ptr)
    {
        if(ptr)
        {
            if (ptr->link)
            {
                if (ptr->data<ptr->link->data)
                {
                    swap(ptr->data,ptr->link->data);
                    Sorting(front);
                }
                Sorting(ptr->link);
            }
        }
    }
    void PrintQueue()
    {
        while(!isEmpty())
        {
            cout<<front->data<<" ";
            Dequeue();
        }
        cout<<endl;
    }
    //code end
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
            //cout << "Value " << front->data << " dequeued from queue" << endl;
            delete front;
            front=NULL;
            rear=NULL;
        }
        else
        {
            //cout << "Value " << front->data << " dequeued from queue" << endl;
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
        cout<<"I m destrcutor"<<endl;
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
    DynamicQueue<int> myQueue;
    cout<<"Values 5 8 3 9 7 2 enqueued"<<endl;
    myQueue.Enqueue(5);
    myQueue.Enqueue(8);
    myQueue.Enqueue(3);
    myQueue.Enqueue(9);
    myQueue.Enqueue(7);
    myQueue.Enqueue(2);
    cout<<"Calling sorting method"<<endl;
    myQueue.Sorting(myQueue.front);
    myQueue.PrintQueue();

    return 0;
}
