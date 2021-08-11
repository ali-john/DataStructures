#include <iostream>
using namespace std;
template<class T>
struct Node
{
    T data;
    Node *link;
};
/*Note
 * Only necessary methods for list ADT is shown which are used to implement search
 * */
template<class T>
class LinkedList
{
public:
    Node<T> *head;
    int length=0;
    //default constructor to initialize to null
    LinkedList()
    {
        head=NULL;
    }

    string search(Node<T> *ptr,int data)//search method
    {
        if (ptr==NULL )
        {
            return "Element Not found";
        }

        else if(ptr->data==data)
        {
            return "Element found";
        }

        else
        {
            return search(ptr->link,data);
        }

    }
    //copy constructor:

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
    \
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
    myList.InsertAtStart(1);
    myList.InsertAtEnd(2);
    myList.InsertAtEnd(3);
    myList.InsertAtEnd(4);
    myList.InsertAtEnd(5);
    myList.Traverse();
    Node<int> *temp=myList.head;
    cout<<"Search key given is 6"<<endl;
    cout<<myList.search(temp,6);
    cout<<endl;
    cout<<"Search key given is 2"<<endl;
    cout<<myList.search(myList.head,2);
    return 0;
}
