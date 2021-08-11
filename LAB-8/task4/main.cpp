#include <iostream>
using namespace std;
template<class T>
struct  Node
{
    T data;
    Node *link;
};
template<class T>
class Stack
{
public:
    void Reverse_printing()
    {
        if (isEmpty())
        {
            //"Stack is empty
            return;
        }
        else
        {
            int top_data=top->data;
            Pop();
            cout<<top_data<<" ";
            Reverse_printing();
            Push(top_data);

        }
    }
    void Reverse_lexiographic()
    {
        while(!isEmpty())
        {
            cout<<top->data<<" ";
            Pop();
        }
    }
    Node<T> *top;
    Stack()
    {
        top=NULL;
    }
    void Push(T value)
    {
        Node<T> *NewNode=new Node<T>;
        NewNode->data=value;
        if(isEmpty())
        {
            NewNode->link=NULL;
            top=NewNode;
        }
        else
        {
            NewNode->link=top;
            top=NewNode;
        }
        //cout<<value<<" pushed to stack"<<endl;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout<<"Stack is empty"<<endl;
        }
        else if (top->link==NULL)
        {
           // cout<<top->data<<" popped from stack"<<endl;
            delete top;
            top=NULL;
        }
        else
        {
            Node<T> *temp=top;
            //cout<<top->data<<" popped from stack"<<endl;
            top=top->link;
            delete temp;
            temp=NULL;
        }
    }
    void RetrieveTop()//outputs top value at stack
    {
        cout<<"Top value at stack is: ";
        cout<<top->data<<endl;
    }

    bool isEmpty()
    {
        if (top==NULL)
            return true;
        else
            return false;
    }

    ~Stack()//destructor
    {
        Node<T> *temp=top;
        Node<T> *current=NULL;
        while (temp!=NULL)
        {
            current=temp;
            temp=temp->link;
            delete current;
            current=NULL;
        }
    }

};

int main()
{

    cout<<"Pushing values 1 2 3 4 5 to stack"<<endl;
    Stack<int> myStack;
    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Push(4);
    myStack.Push(5);
    cout<<"Calling reverse printing function"<<endl;
    myStack.Reverse_Iteratively();
    return 0;
}
