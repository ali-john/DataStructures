#include <iostream>
#define size 5
using namespace std;

template<class T>
class StaticQueue
{
    public:
    T arr[size];//create a static array
    int front;
    int rear;
    StaticQueue()//default constructor
    {
        arr[size]={};
        front=-1;
        rear=-1;
    }
    StaticQueue(const StaticQueue &obj)//copy constructor
    {
        /*
         * since new array is created for each object, hence no need
         * for deep copy. Here shallow copy is serving the purpose.
         */
        rear=obj.rear;
        front=obj.front;
            for (int i = 0; i <=rear ; i++)
            {
                arr[i]=obj.arr[i];
            }
    }
    void Enqueue(T value)
    {
        if (rear==size-1)
        {
            cout<<"Queue overflow occured"<<endl;
        }
        else
        {
            front=0;//always set front to 0
            rear++;
            arr[rear]=value;
            cout<<"Value "<<value<<" enqueued in queue"<<endl;
        }
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout<<"Queue underflow"<<endl;
        }
        else
        {
            cout<<"Value "<<arr[front]<<" dequeue from queue"<<endl;
            for(int i=0;i<rear;i++)//move the elements of queue to left by 1
            {
                arr[i]=arr[i+1];
            }
            /*
             * since moving one position to left overrides element present at 0th index
             * it means dequeue operation is achieved.
             */
            rear--;//decrement the rear number
        }
    }
    void Display()
    {
        if(!isEmpty())
        {
            cout<<"Front element of queue is "<<arr[front]<<endl;
        }
        else
            cout<<"Queue is empty"<<endl;
    }
    bool isEmpty()
    {
        if(front<0 || rear<0)
            return true;
        else
            return false;
    }
    ~StaticQueue()//destructor
    {
        //since no dynamic allocation made in code, therefore no need for deletion in destructor
        cout<<"Destructor called"<<endl;
    }

};
int main()
{
    StaticQueue<int> myQueue;
    cout<<"Element 1-5 enqueued"<<endl;
    double j=0;
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
    StaticQueue<int> myQueue2=myQueue;
    cout<<"Checking copy constructor by dequeue myQueue2"<<endl;
    myQueue2.Dequeue();
    myQueue2.Dequeue();
    myQueue2.Dequeue();

    return 0;
}
