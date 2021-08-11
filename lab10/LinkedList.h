//
// Created by abc on 5/30/2021.
//

#ifndef LAB10_LINKEDLIST_H
#define LAB10_LINKEDLIST_H
using namespace std;
template<typename T>
struct Node
{
    T value;
    Node *link;
};
template<class T>
class LinkedList
{
public:
    Node<T> *head;
    int lenght=0;
    //default constructor to initialize to null
    LinkedList()
    {
        head=NULL;
    }
    //copy constructor:
    LinkedList(const LinkedList &a)
    {
        if (a.head == NULL)
        {

            head=NULL;
        }
        else
        {
            Node<T> *ptr_old=a.head;
            Node<T> *pointer= nullptr;

            for (int i = 0; i < a.lenght; i++)
            {

                if (i==0)
                {
                    Node<T> *NewNode=new Node<T>;
                    NewNode->value=ptr_old->value;
                    NewNode->link=NULL;
                    pointer=NewNode;
                    ptr_old=ptr_old->link;
                    head=NewNode;
                }
                else
                {
                    Node<T> *NewNode=new Node<T>;
                    NewNode->value=ptr_old->value;
                    NewNode->link=NULL;
                    pointer->link=NewNode;
                    pointer=NewNode;
                    ptr_old=ptr_old->link;
                }

            }
        }
    }
    //Insert at start function:
    void InsertAtStart(T val)
    {
        Node<T> *NewNode=new Node<T>;
        NewNode->value=val;
        NewNode->link=NULL;
        if (head==NULL)
        {
            head=NewNode;
            lenght++;
        }
        else
        {
            NewNode->link=head;
            head=NewNode;
            lenght++;
        }
        NewNode=NULL;
        delete NewNode;
    }
    //Insert at end function:
    /*
     * if list is empty, inserting at end does not make sense.
     * so check if list is empty or not.
     * it not empty, insert a node at end
     * otherwise call insert at start.
     */
    void InsertAtEnd(T val)
    {
        if (!isEmpty())
        {
            Node<T> *EndNode=new Node<T>;//creating new node
            EndNode->value=val;//setting value of new node
            EndNode->link=NULL;//as its last node, set link to null
            Node<T> *ptr;//create ptr to traverse
            ptr=head;//point ptr to head
            while (ptr->link!=NULL)//traverse till its at end
            {
                ptr=ptr->link;
            }
            ptr->link=EndNode;//create link between previous and last node
            EndNode=NULL;
            delete EndNode;
            lenght++;

        }
        else
            InsertAtStart(val);
    }
    //Delete at start
    void deleteAtStart()
    {
        if(!isEmpty())
        {
            Node<T> *temp=head;
            head=head->link;
            delete temp;
            temp=NULL;
            lenght--;

        }

        else
        {
            cout<<"List is empty"<<endl;
        }


    }
    /*
     * Check if list is empty, no need of deletions.
     * check if list has only one node ? Delete that
     * if list has more than 1 node, delete last one
     * */
    void deleteAtEnd()
    {
        if (isEmpty())
        {
            cout<<"List is empty, can not delete at end"<<endl;
        }
        else if(head->link==NULL)
        {
            delete head;
            head=NULL;
            lenght--;
        }
        else
        {
            Node<T> *previous;
            Node<T> *temp=head;
            while (temp->link!=NULL)
            {
                previous=temp;
                temp=temp->link;
            }
            previous->link=NULL;
            delete temp;
            temp=NULL;
            previous=NULL;
            delete previous;
            lenght--;

        }
    }
    void InsertAtAnyPosition(int position,T val)
    {
        if (position==1)
        {
            InsertAtStart(val);
        }

        else if (!isEmpty() && position<=lenght)
        {
            Node<T> *Current=new Node<T>;
            Node<T> *previous_node=head;
            Current->value=val;
            for (int i = 0; i < position-2; i++)
            {
                previous_node=previous_node->link;

            }
            Current->link=previous_node->link;
            previous_node->link=Current;
            Current=NULL;
            delete Current;
            lenght++;

        }
        else
        {
            cout<<"List is empty or position to be inserted is greater than length of list"<<endl;
        }

    }
    void DeleteAtAnyPosition(int position)
    {
        if (position==1)
        {
            deleteAtStart();
        }
        else if(position==lenght)
        {
            deleteAtEnd();
        }
        else if(!(isEmpty())&& position<lenght)
        {
            Node<T>*previous;
            Node<T>*current=head;
            for (int i = 0; i < position-1; i++)
            {
                previous=current;
                current=current->link;
            }
            previous->link=current->link;
            delete current;
            current=NULL;
            previous=NULL;
            lenght--;
        }
        else
        {
            cout<<"Either list is empty of position is invalid"<<endl;
        }
    }
    //method made for graph. find position of edge in graph and delete that edge.
    void Delete(T value)
    {
        int positionOfEdge=0;
        Node<T> *temp=head;
        while(true)
        {
            if(value==temp->value)
            {
                positionOfEdge++;
                DeleteAtAnyPosition(positionOfEdge);
                break;
            }
            else
            {
                if (temp==NULL)
                    break;
                else
                    temp=temp->link;
            }
        }
    }
    //Is empty method
    /*will return true if list is empty else return
     * false.
     * */
    bool isEmpty()
    {
        if (head==NULL)
        {
            return true;
        }
        else
            return false;
    }
    //traverse function:
    void Traverse()
    {
        if (head==NULL)
        {
            cout<<"List is empty, can not display"<<endl;
        }
        else
        {
            Node<T> *temp=head;
            //continue moving forward until null at link is found:
            cout<<"The linked list is displayed: "<<endl;
            while (temp!=NULL)
            {
                cout<<(temp->value)<<"  ";
                temp=temp->link;
            }
            cout<<endl;
            temp=NULL;
            delete temp;
        }

    }
    ~LinkedList()
    {
        Node<T> *currentNode=head;
        Node<T> *nextNode=NULL;
        while (currentNode!=NULL)
        {
            nextNode=currentNode->link;
            delete currentNode;
            currentNode=nextNode;
        }
        delete currentNode;
        currentNode=NULL;
        delete nextNode;
        nextNode=NULL;
    }
};
#endif //LAB10_LINKEDLIST_H
