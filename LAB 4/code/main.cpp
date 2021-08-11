#include <iostream>
using namespace std;
template<class T>
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
     * otherwise guidance to fill list.
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
            cout<<"Linked list is empty ,call insert at start to fill it"<<endl;
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

        else if (!isEmpty() & position<=lenght)
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
        else if(!(isEmpty())&position<lenght)
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

int main()
{
    LinkedList<int> myList;//create object of linked list
    cout<<"Is list empty or not"<<endl;
    cout << myList.isEmpty() << endl;//check if list is empty or not (1)->true, 0->false
    cout<<"Delete at start of list is called"<<endl;
    myList.deleteAtStart();//should say list is empty
    myList.InsertAtStart(5);//insert values 1-4 list{5}
    myList.InsertAtStart(4);//list{4 5}
    myList.InsertAtStart(3);//list{3 4 5}
    myList.InsertAtStart(2);// list{2 3 4 5}
    myList.InsertAtStart(1);//list{1 2 3 4 5}
    cout<<"After inserting values, check if list is empty or not"<<endl;
    cout << myList.isEmpty() << endl;//check status of list-->0
    myList.Traverse();//display list;list{1 2 3 4 5}
    myList.deleteAtStart();//delete value of start, list{2 3 4 5}
    cout<<"After calling delete at start "<<endl;
    myList.Traverse();//show list, list{2 3 4 5}
    myList.InsertAtStart(6);//insert 6 at start, list {6 2 3 4 5}
    cout<<"After calling insert at start with value 6"<<endl;
    myList.Traverse();//show list , list {6 3 2 1}
    myList.InsertAtEnd(9);//insert at end, list { 6 2 3 4 5 9}
    cout<<"After calling insert at end with value 9"<<endl;
    myList.Traverse();//list  { 6 2 3 4 5 9}
    myList.deleteAtEnd();// list{6 2 3 4 5}
    cout<<"After calling delete from end"<<endl;
    myList.Traverse();// list{6 3 2 1}
    myList.DeleteAtAnyPosition(3);//list{6 2 4 5};
    cout<<"After calling delete at any position with 3 as arg"<<endl;
    myList.Traverse();//list{6 2 4 5}
    myList.InsertAtAnyPosition(4,7);//inserting 7 at pos 4
    cout<<"After inserting 7 at position 4"<<endl;
    myList.Traverse();//list{6 2 4 7 5}
    myList.deleteAtStart();//list{ 2 4  7 5}
    cout<<"After calling delete from start"<<endl;
    myList.Traverse();
    myList.DeleteAtAnyPosition(2);
    cout<<"After deleting from position 2"<<endl;
    myList.Traverse();//list{2 7 4}
    myList.deleteAtStart();//list{7 4}
    cout<<"After calling delete from start"<<endl;
    myList.Traverse();//list{ 7 4}
    myList.deleteAtStart();//list{4}
    cout<<"After calling delete from start"<<endl;
    myList.Traverse();
    myList.deleteAtStart();//list{empty}
    cout<<"After calling delete from start"<<endl;
    myList.Traverse();// should display list is empty
    //remaining functions checking:
    cout<<"Call delete at start on empty list"<<endl;
    myList.deleteAtStart();
    cout<<"Call delete at end on empty list"<<endl;
    myList.deleteAtEnd();
    myList.InsertAtStart(2);
    myList.InsertAtStart(4);
    LinkedList<int> myList2=myList;
    cout<<"Calling copy constructor when inserted 4 2 in previous list"<<endl;
    myList2.Traverse();

    return 0;
}
