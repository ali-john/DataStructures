#include <iostream>
using namespace std;
#define MaxSize 12
template<class T>
class Stack
{
public:
    T top;
    T arr[MaxSize]={};
    Stack()
    {
        top=-1;
    }
    Stack(const Stack &obj)
    {
        if(!isEmpty())
        {
            top=obj.top;
            for(int i=0; i<=obj.top;i++)
            {
                arr[i]=obj.arr[i];
            }
        }


    }
    void Push(T value)
    {
        cout<<value<<"  pushed at stack"<<endl;
        arr[top+1]=value;
        top++;
    }
    void Pop()
    {
        if (top<0)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            T data=arr[top];
            cout<<data<<" popped from stack"<<endl;
            arr[top]={};
            top--;
        }

    }
    void RetrieveTop()
    {
        if(!isEmpty())
        {
            cout<<arr[top]<<" is top value in stack"<<endl;
        }
        else
        {
            cout<<"stack is empty"<<endl;
        }
    }
    bool isEmpty()
    {
        if (top<0)
        {
            return true;
        }
        else
            return false;
    }
    ~Stack()
    {
        cout<<"destructor called"<<endl;
    }
};
int main()
{
    Stack<int> myStack;
    //inserting 5 values in stack
    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Push(4);
    myStack.Push(5);
    cout<<"Retrieving from stack "<<endl;
    myStack.RetrieveTop();
    cout<<"Popping element from stack "<<endl;
    myStack.Pop();
    cout<<"Inserting 6 in stack "<<endl;
    myStack.Push(6);
    cout<<"Retrieving from stack "<<endl;
    myStack.RetrieveTop();
    cout<<"Popping from stack continuously"<<endl;
    myStack.Pop();
    myStack.Pop();
    myStack.Pop();
    myStack.Pop();
    myStack.Pop();
    myStack.Pop();
    cout<<"Testing copy constructor: "<<endl;
    myStack.Push(78);//push some values to stack
    myStack.Push(65);
    myStack.Push(3);
    Stack<int> myStack2=myStack;//copy constructor should invoke to make copy
    cout<<"Checking top value in myStack2 "<<endl;
    myStack2.RetrieveTop();
    myStack2.Pop();//make myStack2 also empty.
    myStack2.Pop();
    myStack2.Pop();
    myStack2.Pop();

    return 0;
}
