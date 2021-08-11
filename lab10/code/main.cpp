#include <iostream>
#include "LinkedList.h"
#include <queue>
using namespace std;

template <typename T>
struct GraphNode
        {
    T VertexNumber;
    LinkedList<T> Edgeslist;
    GraphNode *next;
};
template<typename T>
struct VisitedList
{
    bool visited;
    T name;
    VisitedList *next;
};
template<typename T>
//dynamic adjacency list implementation of graph
class Graph
{
public:
    GraphNode<T> *graphHead;
    GraphNode<T> *graphTail;
    //1) Create an empty graph:
    Graph()//constructor
    {
        graphHead=nullptr;
        graphTail=nullptr;
    }
    void InsertVertex()//insert a vertex in a graph
    {
        T Vnumber;
        cout<<"Enter Vertex Name"<<endl;
        cin>>Vnumber;
        GraphNode<T> *ptr=SearchVertex(Vnumber);
        if(!ptr)
        {
            GraphNode<T> *Vertex=new GraphNode<T>;
            Vertex->next=nullptr;
            Vertex->VertexNumber=Vnumber;
            if (graphHead==nullptr)
            {
                graphHead=Vertex;
                graphTail=Vertex;
            }
            else
            {
                graphTail->next=Vertex;
                graphTail=Vertex;
            }
        }
        else
            cout<<"Vertex already exist"<<endl;
    }
    void InsertEdge(T v1,T v2)//insert an edge between two vertices.
    {
        GraphNode<T> *first_vertex=SearchVertex(v1);
        GraphNode<T> *second_vertex=SearchVertex(v2);
        if(first_vertex && second_vertex)
        {
            first_vertex->Edgeslist.InsertAtEnd(v2);
            second_vertex->Edgeslist.InsertAtEnd(v1);

        } else
            cout<<"Vertex does not exist . Add vertex"<<endl;
    }
    void DeleteEdge(T vertex_one, T vertex_two)
    {
        GraphNode<T> *vertex_oneaddress=SearchVertex(vertex_one);
        GraphNode<T> *vertex_twoaddress=SearchVertex(vertex_two);
        if(vertex_oneaddress && vertex_twoaddress)
        {

            vertex_oneaddress->Edgeslist.Delete(vertex_two);
            vertex_twoaddress->Edgeslist.Delete(vertex_one);
        } else
            cout<<"Vertex does not exist ."<<endl;
    }
    void DeleteVertex()
    {
        T Vnumber;
        cout<<"Enter Vertex Name"<<endl;
        cin>>Vnumber;
        GraphNode<T> *ptr=SearchVertex(Vnumber);
        if(ptr)
        {
            while(!ptr->Edgeslist.isEmpty())
            {
                T vertex_two=ptr->Edgeslist.head->value;
                DeleteEdge(Vnumber,vertex_two);
            }
            if(ptr==graphHead)
            {
                graphHead=graphHead->next;
                delete ptr;
                ptr=nullptr;
            }
            else if(ptr==graphTail)
            {
                ptr=graphHead;
                while(ptr->next!=graphTail)
                {
                    ptr=ptr->next;
                }
                ptr->next=nullptr;
                delete graphTail;
                graphTail=ptr;

            }
            else
            {
                GraphNode<T>*temp=graphHead;
                while(temp->next!=ptr)
                {
                    temp=temp->next;
                }
                temp->next=ptr->next;
                delete ptr;
            }
        }
        else
            cout<<"Vertex does not exist"<<endl;
    }
    GraphNode<T> * SearchVertex(T vertex)
    {
        if(graphHead==nullptr)//if vertex list is empty
            return nullptr;
        else
        {
            GraphNode<T> *temp=graphHead;
            while(temp)
            {
                if (temp->VertexNumber==vertex) {
                    return temp;
                }
                else
                    temp=temp->next;
            }
            return nullptr;
        }
    }
    //3)isEmpty method check if graph is empty or not
    bool isEmpty()
    {
        if (!graphHead)
            return true;
        else
            return false;
    }
    int VertexCount()
    {
        GraphNode<T> *temp=graphHead;
        int vertices=0;
        for(temp;temp!=nullptr;temp=temp->next)
            vertices++;
        return vertices;
    }
    void EdgeCount()
    {
        Node<T> *edgePointer;
        GraphNode<T> *temp=graphHead;
        int edges=0;
        while (temp!=nullptr)
        {
            edgePointer=temp->Edgeslist.head;
            while(edgePointer!=NULL)
            {
                edges++;
                edgePointer=edgePointer->link;
            }
            temp=temp->next;
        }
        cout<<"Total Edges are: "<<edges/2<<endl;
    }
    void CheckEdgeExistence(T vertexOne, T vertexTwo)
    {
        GraphNode<T> *vertexOne_address=SearchVertex(vertexOne);
        GraphNode<T> *vertexTwo_address=SearchVertex(vertexTwo);
        Node<T> *listptr= nullptr;
        if(vertexOne_address && vertexTwo_address)//if an edge exist between a and b then it alse exists
            //between b and a
        {
            listptr=vertexOne_address->Edgeslist.head;
            while(true)
            {
                if(listptr==NULL)
                {
                    cout<<"Edge does not exist between given vertices"<<endl;
                    break;
                }

                else if(listptr->value==vertexTwo)
                {
                    cout<<"Edge exist between "<<vertexOne<<" and "<<vertexTwo<<endl;
                    break;
                }
                else
                    listptr=listptr->link;
            }
        }
        else
            cout<<"Vertices does not exists"<<endl;
    }
private:void DFS_recursive(VisitedList<T> *visitedList, T vertex)//helper for dfs by recursively calling itself
    {
        VisitedList<T> *temp=visitedList;
        while(true)
        {
            if(temp->name==vertex)
                break;
            else
                temp=temp->next;
        }

        temp->visited=true;
        GraphNode<T> *vertex_addr=SearchVertex(vertex);
        Node<T> *listptr=vertex_addr->Edgeslist.head;
        while(listptr!=NULL)
        {
            VisitedList<T> *ptr=visitedList;
            while(true)
            {
                if(ptr->name==listptr->value)
                    break;
                else
                    ptr=ptr->next;
            }
            if(!ptr->visited)
                DFS_recursive(visitedList,listptr->value);
            else
                listptr=listptr->link;
        }
        cout<<temp->name<<" ";

    }

public:
    void DepthFirstSearch()
    {
        T startingVertex;
        cout<<"Enter starting vertex "<<endl;
        cin>>startingVertex;
        int size=VertexCount();
        VisitedList<T> *visitedHead= new VisitedList<T>;
        visitedHead->next=nullptr;
        visitedHead->name=graphHead->VertexNumber;
        visitedHead->visited=false;
        VisitedList<T> *temp=visitedHead;
        GraphNode<T> *ptr=graphHead;
        for(int i=1;i<size;i++)
        {
            ptr=ptr->next;
            VisitedList<T> *newNode= new VisitedList<T>;
            temp->next=newNode;
            newNode->next=nullptr;
            newNode->visited=false;
            newNode->name=ptr->VertexNumber;
            temp=newNode;
        }

        DFS_recursive(visitedHead,startingVertex);
        VisitedList<T> *currentNode=visitedHead;
        VisitedList<T> *nextNode= nullptr;
        while (currentNode!=nullptr)
        {
            nextNode=currentNode->next;
            delete currentNode;
            currentNode=nextNode;
        }
        delete currentNode;
        currentNode=nullptr;
        delete nextNode;
        nextNode=nullptr;
        cout<<endl;
    }
    void BreadthFirstSearch()
    {
        T startingVertex;
        cout<<"Enter starting vertex "<<endl;
        cin>>startingVertex;
        queue<T> queueobj;
        int size=VertexCount();
        VisitedList<T> *visitedHead= new VisitedList<T>;
        visitedHead->next=nullptr;
        visitedHead->name=graphHead->VertexNumber;
        visitedHead->visited=false;
        VisitedList<T> *temp=visitedHead;
        GraphNode<T> *ptr=graphHead;
        /*
         * use a linked list to keep track of all nodes that are visited.
         * Array can work for integer data type but if nodes name change to string, it
         * would not be feasible to maintain link between visited nodes and array indices
         */
        for(int i=1;i<size;i++)//linked list of vertices and there visited status
        {
            ptr=ptr->next;
            VisitedList<T> *newNode= new VisitedList<T>;
            temp->next=newNode;
            newNode->next=nullptr;
            newNode->visited=false;
            newNode->name=ptr->VertexNumber;
            temp=newNode;
        }
        //bfs implementation.
        //push starting node in queue
        queueobj.emplace(startingVertex);
        temp=visitedHead;
        while(true)
        {
            if(temp->name==startingVertex)
                break;
            else
                temp=temp->next;
        }
        temp->visited=true;
        while(!queueobj.empty())
        {
            T frontElement=queueobj.front();
            cout<<frontElement<<" ";
            queueobj.pop();//remove front element.
            //now push all unvisited nodes of front element in queue.
            ptr=SearchVertex(frontElement);
            Node<T> *ptrList=ptr->Edgeslist.head;

           while(ptrList!=NULL)
           {
               temp=visitedHead;
               while(temp!=nullptr)
               {
                   if(temp->name==ptrList->value)
                       break;
                   else
                       temp=temp->next;
               }
               if(!temp->visited)
               {
                   queueobj.emplace(temp->name);
                   temp->visited=true;
               } else
                   ptrList=ptrList->link;
           }
        }
        //delete the visited nodes linkedlist
        VisitedList<T> *currentNode=visitedHead;
        VisitedList<T> *nextNode= nullptr;
        while (currentNode!=nullptr)
        {
            nextNode=currentNode->next;
            delete currentNode;
            currentNode=nextNode;
        }
        delete currentNode;
        currentNode=nullptr;
        delete nextNode;
        nextNode=nullptr;
        cout<<endl;
    }

    //2) Destroy a graph
    ~Graph()//destructor
    {
        GraphNode<T> *currentNode=graphHead;
        GraphNode<T> *nextNode= nullptr;
        while (currentNode!= nullptr)
        {
            nextNode=currentNode->next;
            delete currentNode;
            currentNode=nextNode;
        }
        delete currentNode;
        currentNode= nullptr;
        delete nextNode;
        nextNode=NULL;
    }

};
int main()
{
    //creating graph object
    Graph<string> obj;
    cout<<"Make following graph: "<<endl;
    cout<<" a \n";
    cout<<" /   \\"<<endl;
    cout<<"b      c"<<endl;
    cout<<"\\      \\"<<endl;
    cout<<"  d ----- e"<<endl;
    cout<<"Check if graph is empty or not "<<endl;
    cout<<obj.isEmpty()<<endl;
    cout<<"Adding 5 vertex of graph"<<endl;
    for (int j=0;j<5;j++)
        obj.InsertVertex();
    cout<<"Check if graph is empty or not "<<endl;
    cout<<obj.isEmpty()<<endl;
    cout<<"Adding edges between vertices: "<<endl;
    for (int j=0; j<5;j++)
    {
        string v1,v2;
        cout<<"Enter vertex name between which edge has to be inserted "<<endl;
        cin>>v1>>v2;
        obj.InsertEdge(v1,v2);
    }
    cout<<"The total number of vertices in graph are: "<<endl;
    cout<<obj.VertexCount()<<endl;
    cout<<"The total number of edges in graph are: "<<endl;
    obj.EdgeCount();
    cout<<"Enter two vertices to check whether edge exist between them or not "<<endl;
    string v1,v2;
    cin>>v1>>v2;
    obj.CheckEdgeExistence(v1,v2);
    cout<<"Displaying  DFS_traversal of graph: "<<endl;
    obj.DepthFirstSearch();
    cout<<"Deleting a vertex from graph: "<<endl;
    obj.DeleteVertex();
    cout<<"Displaying  DFS_traversal of graph: "<<endl;
    obj.DepthFirstSearch();
    cout<<"The total number of vertices in graph are: "<<endl;
    cout<<obj.VertexCount()<<endl;
    cout<<"Delete an edge between two vertices:"<<endl;
    cout<<"Enter two vertices between which edge is to be delete "<<endl;
    cin>>v1>>v2;
    obj.DeleteEdge(v1,v2);
    cout<<"Check if edge exist between "<<v1<< " and "<< v2<<endl;
    obj.CheckEdgeExistence(v1,v2);
    cout<<"Displaying  DFS_traversal of graph: "<<endl;
    obj.DepthFirstSearch();
    cout<<"Displaying  BFS_traversal of graph: "<<endl;
    obj.BreadthFirstSearch();
    cout<<"Adding recently deleted edge between "<<v1<<" and "<<v2<<endl;
    obj.InsertEdge(v1,v2);
    cout<<"Displaying  BFS_traversal of graph: "<<endl;
    obj.BreadthFirstSearch();

    return 0;
}
