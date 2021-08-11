#include <iostream>
#define size 5
using namespace std;
/*
 * Do not know why its giving one bug
 * Fix it later.
 * Its not 100% correct.
 */
template<class T>
class StaticCircular
{
public:
    int front;
    int rear;
    int count=0;
    T arr[size];
    StaticCircular()//default constructor
    {
        front=-1;
        rear=-1;
        arr[size]={};
    }
    StaticCircular(const StaticCircular &obj)//copy constructor
    {
        front=obj.front;
        rear=obj.rear;
        for (int i = front; i <=rear ; i++)
        {
            arr[i]=obj.arr[i];
        }
    }
    void Enqueue(T value)//insert value in queue
    {
        /*
         * to check if there is a room in queue, check circularly if r+1==front or not
         * if rear+1==front then there is no room in queue
         * otherwise there is a space in queue.
         */
        if((rear+1)%size==front && count>=size)
        {
            cout<<"Queue overflow"<<endl;
        }
        else if(rear==-1 & front==-1)//first element insertion
        {
            front=0;
            rear++;
            arr[rear]=value;
            count++;
        }
        else if(rear!=-1 && front==-1)//if queue is dequeued once
        {
            front=1;
            rear++;
            arr[rear]=value;
            count++;
        }
        else
        {
            rear=(rear+1)%size;
            arr[rear]=value;
            count++;
        }
    }
    void Dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue underflow"<<endl;
        }
        else if(front==rear)
        {
            cout<<arr[front]<<" dequeued"<<endl;
            front=-1;
            count--;
        }
        else
        {
            cout<<arr[front]<<" dequeued"<<endl;
            front=(front+1)%size;
            count--;
        }

    }
    void Display()//display first element of queue
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            cout<<"Front element of queue is "<<arr[front]<<endl;
        }
    }
    bool isEmpty()
    {
        if(front<0 && count<=0)
            return true;
        else
            return false;
    }
    ~StaticCircular()
    {
        cout<<"Destructor called"<<endl;
    }
};
int main()
{

    StaticCircular<int> myQueue;
    cout<<"Element 1-5 enqueued"<<endl;
    double j=0;
    for (int i = 0; i < 5; i++)//insert 1-5 elements in queue
    {
        j=j+1;
        myQueue.Enqueue(j);
    }
    cout<<"Calling deque"<<endl;
    myQueue.Dequeue();
    cout<<"Calling deque"<<endl;
    myQueue.Dequeue();
    cout<<"Enqueue 6 in queue"<<endl;
    myQueue.Enqueue(6);
    cout<<"Enqueue 7 in queue"<<endl;
    myQueue.Enqueue(7);
    cout<<"Calling display "<<endl;
    myQueue.Display();
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
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();
    cout<<"Copy constructor invoking"<<endl;
    StaticCircular<int >myQueue2=myQueue;
    myQueue2.Display();
    return 0;
}
