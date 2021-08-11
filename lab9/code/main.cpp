#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T data;
    Node *rightLink;
    Node *leftLink;
};

template <class T>
class Tree
{
public:
    Node<T> *rootPtr;
    Tree()//constructor
    {
        rootPtr= nullptr;
    }
    Tree(const Tree &obj) {
        rootPtr = CopyTree(obj.rootPtr);
    }
    Node<T>* CopyTree(Node<T> *srcPtr)
    {
        if(srcPtr== nullptr)
            return srcPtr;
        else
        {
            Node<T> *temp=getNewNode();
            temp->data=srcPtr->data;
            temp->leftLink=CopyTree(srcPtr->leftLink);
            temp->rightLink=CopyTree(srcPtr->rightLink);
            return temp;
        }
    }
    Node<T>* getNewNode()// make a new node
    {
        Node<T> *newNode=new Node<T>;
        newNode->rightLink=nullptr;
        newNode->leftLink=nullptr;
        return newNode;
    }
    Node<T>* ReturnParent(Node<T> *root,T key)//ptr will get root of tree
    {
        Node<T> *parent=nullptr;
        while(root!=nullptr && root->data!=key)
        {
            parent=root;
            if(root->data>key)
                root=root->leftLink;
            else
                root=root->rightLink;
        }
        return parent;
    }
    void Insert(T value)
    {
        Node<T> *temp;
        if(isEmpty())
        {
            temp=getNewNode();
            temp->data=value;
            rootPtr=temp;
        }
        else
        {
            Node<T>*ptr=rootPtr;
            while(true)
            {
                if(value>ptr->data)
                {
                    if(!ptr->rightLink)//empty place at right side
                    {
                        temp=getNewNode();
                        ptr->rightLink=temp;
                        temp->data=value;
                        break;
                    }
                    else
                        ptr=ptr->rightLink;
                }
                else if(value<ptr->data)
                {
                    if(!ptr->leftLink)//empty place at left side
                    {
                        temp=getNewNode();
                        ptr->leftLink=temp;
                        temp->data=value;
                        break;
                    }
                    else
                        ptr=ptr->leftLink;
                }
                else
                {
                    cout<<"Element already exist"<<endl;
                    break;
                }
            }
        }


    }
    Node<T>* Search(T value)//search for a value and returns its pointer
    {
        if(!isEmpty())
        {
            if(rootPtr->data==value)
            {
                cout<<"Element Found"<<endl;
                return rootPtr;
            }
            else
            {

                if(value>rootPtr->data)
                {
                    Node<T> *tempPtr=rootPtr->rightLink;
                    while(true)
                    {
                        if(value>tempPtr->data && tempPtr->rightLink!=nullptr)
                            tempPtr=tempPtr->rightLink;
                        else if(value<tempPtr->data && tempPtr->leftLink!=nullptr)
                            tempPtr=tempPtr->leftLink;
                        else if(value==tempPtr->data)
                        {
                            cout<<"Value Found"<<endl;
                            return tempPtr;
                        }
                        else
                        {
                            cout<<"Element Not found"<<endl;
                            return nullptr;
                        }
                    }

                }
                else
                {
                    Node<T> *tempPtr=rootPtr->leftLink;
                    while(true)
                    {
                        if(value>tempPtr->data && tempPtr->rightLink!=nullptr)
                            tempPtr=tempPtr->rightLink;
                        else if(value<tempPtr->data && tempPtr->leftLink!=nullptr)
                            tempPtr=tempPtr->leftLink;
                        else if(value==tempPtr->data)
                        {
                            cout<<"Value Found"<<endl;
                            return tempPtr;
                        }
                        else
                        {
                            cout<<"Element Not found"<<endl;
                            return nullptr;
                        }
                    }
                }

            }
        }
        else
        {
            cout<<"Tree is empty"<<endl;
            return nullptr;
        }

    }
    void Delete(T value)
    {
        Node<T> *NodeAddress=Search(value);

        if(!isEmpty() && NodeAddress!=nullptr)
        {
            Node<T> *NodeParent;
            if(NodeAddress!=rootPtr)
                NodeParent=ReturnParent(rootPtr,NodeAddress->data);
            else
                NodeParent=nullptr;

            if(NodeAddress==rootPtr)//seperate deletion for root
            {
                if(NodeAddress->leftLink==nullptr && NodeAddress->rightLink==nullptr)
                {
                    delete NodeAddress;
                    rootPtr= nullptr;
                }
                else if(NodeAddress->rightLink==nullptr)
                {
                    Node<T> *temp=rootPtr;
                    rootPtr=rootPtr->leftLink;
                    delete temp;
                    temp=nullptr;
                }
                else if(NodeAddress->leftLink==nullptr)
                {
                    Node<T> *temp=rootPtr;
                    rootPtr=rootPtr->rightLink;
                    delete temp;
                    temp=nullptr;
                }
                else if(NodeAddress->leftLink!=nullptr && NodeAddress->rightLink!=nullptr)
                {
                    Node<T> *replacingValue=NodeAddress->leftLink;//looking for largest value at left
                    if (replacingValue->rightLink!=nullptr)
                    {
                        while(replacingValue->rightLink!=nullptr)
                        {
                            replacingValue=replacingValue->rightLink;
                        }
                        NodeAddress->data=replacingValue->data;
                        NodeParent=ReturnParent(rootPtr,replacingValue->data);
                        NodeParent->rightLink=nullptr;
                        delete replacingValue;
                    }
                    else
                    {
                        rootPtr->leftLink=replacingValue->leftLink;
                        rootPtr->data=replacingValue->data;
                        delete replacingValue;
                    }
                }
            }
            else if(NodeAddress->leftLink==nullptr && NodeAddress->rightLink==nullptr)//a leaf node
            {
                if(NodeParent->leftLink==NodeAddress)
                    NodeParent->leftLink=nullptr;
                else
                    NodeParent->rightLink=nullptr;
                delete NodeAddress;
                NodeAddress= nullptr;
            }
            else if(NodeAddress->leftLink==nullptr)
            {
                if (NodeParent->rightLink==NodeAddress)
                    NodeParent->rightLink=NodeAddress->rightLink;
                else
                    NodeParent->leftLink=NodeAddress->rightLink;
                delete NodeAddress;
                NodeAddress=nullptr;
            }
            else if(NodeAddress->rightLink==nullptr)
            {
                if (NodeParent->rightLink==NodeAddress)
                    NodeParent->rightLink=NodeAddress->leftLink;
                else
                    NodeParent->leftLink=NodeAddress->leftLink;
                delete NodeAddress;
                NodeAddress=nullptr;
            }
            else if(NodeAddress->leftLink!=nullptr && NodeAddress->rightLink!=nullptr)//case 3
            {
                Node<T> *replacingValue=NodeAddress->leftLink;//looking for largest value at left
                if (replacingValue->rightLink!=nullptr)
                {
                    while(replacingValue->rightLink!=nullptr)
                    {
                        replacingValue=replacingValue->rightLink;
                    }
                    NodeAddress->data=replacingValue->data;
                    NodeParent=ReturnParent(rootPtr,replacingValue->data);
                    NodeParent->rightLink=nullptr;
                    delete replacingValue;
                }
                else
                {
                    NodeParent->leftLink=replacingValue->leftLink;
                    NodeAddress->data=replacingValue->data;
                    delete replacingValue;
                }
            }
        }

    }
    bool isEmpty()
    {
        if (!rootPtr)
            return true;
        else
            return false;
    }
    void DeleteSubTree(Node<T> *temp)//delete a tree from a specific point
    {
        if(temp==nullptr)
            return;
        else
        {
            DeleteSubTree(temp->leftLink);
            DeleteSubTree(temp->rightLink);
        }
        delete temp;
    }

    void preOrder_Traversal(Node<T> *temp)// root -- left -- right
    {
        if(isEmpty())
        {
            cout<<"Tree is empty\n";
            return;
        }
        if(temp==nullptr)
            return;
        else
        {
            cout<<temp->data<<"  ";
            preOrder_Traversal(temp->leftLink);
            preOrder_Traversal(temp->rightLink);
        }
    }
    void PostOrder_Traversal(Node<T> *temp)//left -- right -- root
    {
        if(isEmpty())
        {
            cout<<"Tree is empty\n";
            return;
        }
        if(temp== nullptr)
            return;
        else
        {
            PostOrder_Traversal(temp->leftLink);
            PostOrder_Traversal(temp->rightLink);
            cout<<temp->data<<"  ";
        }
    }
    void InOrder_Traversal(Node<T> *temp)
    {
        if(isEmpty())
        {
            cout<<"Tree is empty\n";
            return;
        }
        if(temp == nullptr)
            return;
        else
        {
            InOrder_Traversal(temp->leftLink);
            cout<<temp->data<<"  ";
            InOrder_Traversal(temp->rightLink);
        }
    }
    ~Tree()
    {
        DeleteSubTree(rootPtr);//delete sub tree of root i.e entire tree
        rootPtr=nullptr;//set root to nullptr.
    }



};
int main() {


    Tree<int> myTree;
    myTree.Insert(21);
    myTree.Insert(22);
    myTree.Insert(10);
    myTree.Insert(19);
    myTree.Insert(17);
    cout<<"Values added to Tree"<<endl;
    cout<<"Inorder Traverse myTree\n";
    myTree.InOrder_Traversal(myTree.rootPtr);
    cout<<endl;
    cout<<"Preorder Traverse myTree"<<endl;
    myTree.preOrder_Traversal(myTree.rootPtr);
    cout<<endl;
    cout<<"Postorder Traversal myTree"<<endl;
    myTree.PostOrder_Traversal(myTree.rootPtr);
    cout<<endl;
    cout<<"Searching 6 in tree"<<endl;
    myTree.Search(6);
    cout<<"Searching 21 in tree"<<endl;
    myTree.Search(21);
    cout<<"Inserting 22 in the tree"<<endl;
    myTree.Insert(22);
    cout<<endl;
    cout<<"Deleting 78 from tree"<<endl;
    myTree.Delete(78);
    cout<<"Deleting 10 from tree"<<endl;
    myTree.Delete(10);
    cout<<"Tree inorder traverse"<<endl;
    myTree.InOrder_Traversal(myTree.rootPtr);
    cout<<endl;
    cout<<"Checking if tree is empty or not"<<endl;
    cout<<myTree.isEmpty()<<endl;
    cout<<"New tree from copying is created"<<endl;
    Tree<int> copyTree=myTree;
    cout<<"Checking if copy tree is empty or not"<<endl;
    cout<<copyTree.isEmpty()<<endl;
    copyTree.InOrder_Traversal(copyTree.rootPtr);
    cout<<endl;
    cout<<"Deleting 17 from Copy tree"<<endl;
    copyTree.Delete(17);
    cout<<endl;
    cout<<"Inorder traverse myTree"<<endl;
    myTree.InOrder_Traversal(myTree.rootPtr);
    cout<<endl;
    cout<<"Inorder Traverse copy Tree"<<endl;
    copyTree.InOrder_Traversal(copyTree.rootPtr);
    cout<<endl;
    cout<<"Deleting 19 from copy tree"<<endl;
    copyTree.Delete(19);
    cout<<"Deleting 21 from copy tree"<<endl;
    copyTree.Delete(21);
    cout<<"Deleting 22 from copy tree"<<endl;
    copyTree.Delete(22);
    cout<<"Inorder traverse copy tree"<<endl;
    copyTree.InOrder_Traversal(copyTree.rootPtr);
    cout<<endl;
    cout<<"Inorder traverse myTree"<<endl;
    myTree.InOrder_Traversal(myTree.rootPtr);
    cout<<endl;
    cout<<"Pre order traverse myTree"<<endl;
    myTree.preOrder_Traversal(myTree.rootPtr);
    cout<<endl;
    cout<<"Post order traverse myTree"<<endl;
    myTree.PostOrder_Traversal(myTree.rootPtr);
    cout<<endl;

    return 0;
}
