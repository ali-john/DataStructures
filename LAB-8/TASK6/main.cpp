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
    Node<T> *top;
    Stack()
    {
        top=NULL;
    }
    void Reverse_list()
    {
        if (!isEmpty())
        {
            T temp=top->data;
            Pop();
            cout<<temp<<" ";
            Reverse_list();
            Push(temp);
        }
        else
        {
            return;
        }
    }
    Stack(const Stack &obj)//copy Constructor
    {

        Node<T> *temp=obj.top;
        Node<T> *prevLink=NULL;
        while(temp!=NULL)
        {
            if (temp==obj.top)
            {
                Node<T> *NewNode=new Node<T>;
                NewNode->data=temp->data;
                NewNode->link=NULL;
                prevLink=NewNode;
                top=NewNode;
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
            //cout<<top->data<<" popped from stack"<<endl;
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
    Stack<int> myStack;
    cout<<"Values 1-5 pushed to stack"<<endl;
    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Push(4);
    myStack.Push(5);
    cout<<"Calling reverse method"<<endl;
    myStack.Reverse_list();
    return 0;
}


void fun (node* head) //PARAMETER IS A POINTER
{
    if (head == NULL)//CHECK IF POINTER IS NULL OR NOT
        return;//IF IT IS NULL, RETURN
    head = head->next;//ELSE MOVE TO LINK OF HEAD
    cout << head->data << endl;//PRINT DATA OF LINK OF HEAD
    if (head->next != NULL)//CHECK IF NEXT NODE IS NULL OR NOT
        fun(head->next);//RECURSIVE CALLS TO FUNCTION
    cout << head->data << endl;//PRINTING DATA
}
