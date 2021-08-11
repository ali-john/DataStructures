//
// Created by abc on 5/23/2021.
//

#ifndef LAB9_STACK_H
#define LAB9_STACK_H
#include <iostream>
using namespace std;
template<class T>
struct  NodeS
{
    T data;
    NodeS *link;
};
template<class T>
class Stack
{
public:
    NodeS<T> *top;
    Stack()
    {
        top=NULL;
    }
    Stack(const Stack &obj)//copy Constructor
    {

        NodeS<T> *temp=obj.top;
        NodeS<T> *prevLink=NULL;
        while(temp!=NULL)
        {
            if (temp==obj.top)
            {
                NodeS<T> *NewNode=new NodeS<T>;
                NewNode->data=temp->data;
                NewNode->link=NULL;
                prevLink=NewNode;
                top=NewNode;
                temp=temp->link;
            }
            else
            {
                NodeS<T> *NewNode=new NodeS<T>;
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
        NodeS<T> *NewNode=new NodeS<T>;
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
        cout<<value<<" pushed to stack"<<endl;
    }
    bool Pop()
    {
        if (isEmpty())
        {
            //cout<<"Stack is empty"<<endl;
            return false;
        }
        else if (top->link==NULL)
        {
            //cout<<top->data<<" popped from stack"<<endl;
            delete top;
            top=NULL;
        }
        else
        {
            NodeS<T> *temp=top;
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
        NodeS<T> *temp=top;
        NodeS<T> *current=NULL;
        while (temp!=NULL)
        {
            current=temp;
            temp=temp->link;
            delete current;
            current=NULL;
        }
    }

};
#endif //LAB9_STACK_H
