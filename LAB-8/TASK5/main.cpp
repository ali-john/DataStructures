#include <iostream>
using namespace std;
template<class T>
struct Node
{
    T data;
    Node *link;
};

template<class T>
class LinkedList
{
public:
    Node<T> *head;
    int length=0;
    int nodeCounter=1;
    //default constructor to initialize to null
    LinkedList()
    {
        head=NULL;
    }

    //copy constructor ends:
    /*
     * Alternate nodes print method will print even number of nodes if isEven set to true otherwise will
     * print odd number of nodes. In given test plan, it is to be noticed that in linked list
     * 1 2 3 4 5 6 7 , when iseven set to false, output is 1 3 5 7. Therefore I assume the list indexing
     * is started from position 1.
     */
    void Alternate_nodes(Node<T> *ptr,bool isEven)
    {
        if(ptr==NULL)//traverse till last node
            return;
        else if(isEven==true)//if to find even nodes
        {
            if(nodeCounter%2==0)//if node is even, display otherwise continue recursion
            {
                cout<<ptr->data<<" ";
                nodeCounter++;
                Alternate_nodes(ptr->link,isEven);
                nodeCounter--;
            } else
            {
                nodeCounter++;
                Alternate_nodes(ptr->link,isEven);
                nodeCounter--;
            }

        }
        else//if node to display is odd
        {
            if(nodeCounter%2!=0)
            {
                cout<<ptr->data<<" ";
                nodeCounter++;
                Alternate_nodes(ptr->link,isEven);
                nodeCounter--;
            } else
            {
                nodeCounter++;
                Alternate_nodes(ptr->link,isEven);
                nodeCounter--;
            }

        }

    }

    //Insert at start function:
    void InsertAtStart(T val)
    {
        Node<T> *NewNode=new Node<T>;
        NewNode->data=val;
        NewNode->link=NULL;
        if (head==NULL)
        {
            head=NewNode;
            length++;
        }
        else
        {
            NewNode->link=head;
            head=NewNode;
            length++;
        }
        NewNode=NULL;
        delete NewNode;
    }
    //Insert at end function:
    /*
     * if list is empty, inserting at end does not make sense.
     * so check if list is empty or not.
     * it not empty, insert a node at end
     * otherwise guidance to fill list.
     */
    void InsertAtEnd(T val)
    {
        if (!isEmpty())
        {
            Node<T> *EndNode=new Node<T>;//creating new node
            EndNode->data=val;//setting data of new node
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
            length++;

        }
        else
            cout<<"Linked list is empty ,call insert at start to fill it"<<endl;
    }
    //Delete at start
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
                cout << (temp->data) << "  ";
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

int main()
{
    LinkedList<int> myList;
    cout<<"Values 1-7 inserted in list"<<endl;
    myList.InsertAtStart(1);
    myList.InsertAtEnd(2);
    myList.InsertAtEnd(3);
    myList.InsertAtEnd(4);
    myList.InsertAtEnd(5);
    myList.InsertAtEnd(6);
    myList.InsertAtEnd(7);
    cout<<"Case 1 when isEven set to true, the list is: "<<endl;
    myList.Alternate_nodes(myList.head,true);
    cout<<endl;
    cout<<"Case 2 when isEven set to false, the list is: "<<endl;
    myList.Alternate_nodes(myList.head,false);

    return 0;
}
