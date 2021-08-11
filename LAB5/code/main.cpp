#include <iostream>
using namespace std;

template<class T>
struct Node
{
    T data;
    Node *link;
};
template<class T>
class CircularLinkedList
{
public:
    Node<T> *tail;
    int ListLength=0;
    CircularLinkedList()//default constructor
    {
         tail= NULL;
    }
    //copy constructor:
    CircularLinkedList(const CircularLinkedList &a)
    {
        if (a.tail == NULL)
        {

            tail=NULL;
        }
        else
        {
            Node<T> *ptr_old=a.tail->link;
            Node<T> *pointer= nullptr;
            Node<T> *head_address_holder=nullptr;
            for (int i = 0; i < a.ListLength; i++)
            {

                if (i==0)
                {
                    Node<T> *NewNode=new Node<T>;
                    NewNode->data=ptr_old->data;
                    head_address_holder=NewNode;
                    NewNode->link=NULL;
                    pointer=NewNode;
                    ptr_old=ptr_old->link;
                }
                /*
                 * in last node of list, point tail to it and also put address of head
                 * node in its link portion which is stored.
                 */
                else if(i==a.ListLength-1)//last node of list
                {
                    Node<T> *NewNode=new Node<T>;
                    tail=NewNode;
                    NewNode->data=ptr_old->data;
                    NewNode->link=head_address_holder;
                    pointer->link=NewNode;

                }
                else
                {
                    Node<T> *NewNode=new Node<T>;
                    NewNode->data=ptr_old->data;
                    NewNode->link=NULL;
                    pointer->link=NewNode;
                    pointer=NewNode;
                    ptr_old=ptr_old->link;
                }

            }
        }
    }

    void InsertAtStart(T value)//insert a node at start of list
    {
        Node<T> *NewNode=new Node<T>;
        NewNode->data=value;
        if (isEmpty())
        {
            tail=NewNode;
            NewNode->link=NewNode;
            ListLength++;
        }
        else
        {
            NewNode->link=tail->link;
            tail->link=NewNode;
            ListLength++;
        }
        NewNode=NULL;
        delete NewNode;
    }
    void InsertAtEnd(T value_for_end)//insert a node at end of linked list
    {
        if(isEmpty())
        {
            cout<<"List is empty, inserting a new node"<<endl;
            InsertAtStart(value_for_end);
        }
        else
        {
            Node<T> *NewNode=new Node<T>;
            NewNode->data=value_for_end;
            NewNode->link=tail->link;
            tail->link=NewNode;
            tail=NewNode;
            ListLength++;
        }

    }
    void InsertAtAnyPosition(int position,T val)//INSERT VALUE AT ANY SPECIFIED LOCATION
    {
        if (position==1)
        {
            InsertAtStart(val);
        }
        else if(position>ListLength)
        {
            InsertAtEnd(val);
        }
        else if((!isEmpty())& (position<=ListLength))
        {
            Node<T> *Current=new Node<T>;
            Node<T> *previous_node=tail->link;
            Current->data=val;
            for (int i = 0; i < position-2; i++)
            {
                previous_node=previous_node->link;

            }
            Current->link=previous_node->link;
            previous_node->link=Current;
            Current=NULL;
            delete Current;
            ListLength++;
        }
    }
    void DeleteAtStart()//Delete node at start of list
    {
        if(!isEmpty())
        {
            Node<T> *temp=tail->link;//point to head of list
            tail->link=temp->link;//points tail to 2nd node which is now head
            delete temp;
            temp=NULL;
            ListLength--;
        }
        else
        {
            cout<<"List is empty, can not delete"<<endl;
        }

    }
    void DeleteAtEnd()
    {
        if(isEmpty())
        {
            cout<<"List is empty, can not delete at end"<<endl;
        }
        else if(tail->link==tail)//if there is single node in list
        {
            delete tail;
            tail=NULL;
            ListLength--;
        }
        else
        {
            Node<T> *temp=tail->link;
            while(temp->link!=tail)//stores second last node of list
            {
                temp=temp->link;
            }
            temp->link=tail->link;//points last made node to start
            delete tail;//delete previous last node
            tail=temp;//update tail
            ListLength--;
        }
    }
    void DeleteAtAnyPosition(int position)
    {
        if (position==1)
        {
            DeleteAtStart();
        }
        else if(position==ListLength)
        {
            DeleteAtEnd();
        }
        else if(!(isEmpty())&(position<ListLength))
        {
            Node<T>*previous;
            Node<T>*current=tail->link;
            for (int i = 0; i < position-1; i++)
            {
                previous=current;
                current=current->link;
            }
            previous->link=current->link;
            delete current;
            current=NULL;
            previous=NULL;
            ListLength--;
        }
        else
        {
            cout<<"Either list is empty of position is invalid"<<endl;
        }

    }
    void Traverse()//print the content of list
    {
        if(isEmpty())
        {
            cout<<"List is empty, can not display"<<endl;
        }
        else
        {
            Node<T> *temp=tail->link;
            cout<<"List is: "<<endl;
            while(temp!=tail)
            {
                cout<<temp->data<<" ";
                temp=temp->link;
            }
            cout<<temp->data;
            cout<<endl;
        }


    }
    bool isEmpty()//Check if list is empty or not
    {
        if (tail == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }


    }
    ~CircularLinkedList()
    {
        Node<T> *currentNode=tail->link;
        Node<T> *nextNode=NULL;
        while(currentNode!=tail)
        {
            nextNode=currentNode->link;
            delete currentNode;
            currentNode=nextNode;
        }
        delete currentNode;
        currentNode=NULL;
        nextNode=NULL;
    }
};
int main()
{
    //creating an int type obj with default constructor
    CircularLinkedList<int> myList;
    cout<<"Checking if list is empty"<<endl;
    cout<<myList.isEmpty()<<endl;
    cout<<"Inserting values 1-5 in list"<<endl;
    myList.InsertAtStart(1);
    myList.InsertAtEnd(2);
    myList.InsertAtEnd(3);
    myList.InsertAtEnd(4);
    myList.InsertAtEnd(5);
    cout<<"Checking if list is empty now: "<<endl;
    cout<<myList.isEmpty()<<endl;
    //traversing list:
    myList.Traverse();
    cout<<"Deleting from start "<<endl;
    myList.DeleteAtStart();
    myList.Traverse();
    cout<<"Inserting at start value 6"<<endl;
    myList.InsertAtStart(6);
    myList.Traverse();
    cout<<"Inserting 9 at end of list"<<endl;
    myList.InsertAtEnd(9);
    myList.Traverse();
    cout<<"Calling delete from end"<<endl;
    myList.DeleteAtEnd();
    myList.Traverse();
    cout<<"Deleting from position 3"<<endl;
    myList.DeleteAtAnyPosition(3);
    myList.Traverse();
    cout<<"Inserting value 7 at position 4"<<endl;
    myList.InsertAtAnyPosition(4,7);
    myList.Traverse();
    //CREATING A FLOAT TYPE LIST
    cout<<"Creating float list and inserting 1.5,2.5 ,3.5,4.5,5.5"<<endl;
    CircularLinkedList<float> myList2;
    myList2.InsertAtStart(1.5);
    myList2.InsertAtEnd(2.5);
    myList2.InsertAtEnd(3.5);
    myList2.InsertAtEnd(4.5);
    myList2.InsertAtEnd(5.5);
    myList2.Traverse();
    cout<<"Deleting from position 2"<<endl;
    myList2.DeleteAtAnyPosition(2);
    myList2.Traverse();
    cout<<"Inserting at start 5.5"<<endl;
    myList2.InsertAtStart(5.5);
    myList2.Traverse();
    cout<<"Inserting 6.5 at end of list"<<endl;
    myList2.InsertAtEnd(6.5);
    myList2.Traverse();
    cout<<"Inserting 7.7 at position 5"<<endl;
    myList2.InsertAtAnyPosition(5,7.7);
    myList2.Traverse();

    return 0;
}
