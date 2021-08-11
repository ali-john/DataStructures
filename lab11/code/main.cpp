#include <iostream>
#include <cmath>
using namespace std;
template<typename T>
class Heap
{
public:

    int lastIndex;
    T *HeapArray;
    Heap(int Heapsize)
    {
        lastIndex=0;
        int size=Heapsize;
        HeapArray=new T[size];
    }
    void Insert()
    {
        T data;
        cout<<"Enter Value for insertion "<<endl;
        cin>>data;
        HeapArray[lastIndex]=data;
        lastIndex++;
        Heapifyup();
        cout<<data<<" Added in Heap"<<endl;
    }
    void Heapifyup()
    {
        int childIndex=lastIndex-1;
        int parentIndex=floor((childIndex-1)/2);
        while(HeapArray[parentIndex]<HeapArray[childIndex])
        {
            swap(HeapArray[parentIndex],HeapArray[childIndex]);
            childIndex=parentIndex;
            parentIndex=floor((childIndex-1)/2);
        }
    }
    void Remove()
    {
        if(lastIndex>=1)
        {
            cout<<HeapArray[0]<<" removed from Heap"<<endl;
            HeapArray[0]=HeapArray[lastIndex-1];//since lastindex is pointing to first empty location.
            lastIndex--;
            HeapifyDown();
        }
        else
            cout<<"Heap is Empty "<<endl;
    }
    void test()
    {
        for (int i = 0; i < lastIndex; i++)
        {
            cout<<HeapArray[i];
        }
    }
    void HeapifyDown()
    {
        int RightChildpos=RightChildIndex(0);
        int LeftChildpos=LeftChildIndex(0);
        int rootIndex=0;
        for (int i=0;RightChildpos<=lastIndex-1;i++)
        {

            if(RightChildpos>=0 && LeftChildpos>=0)
            {
                if(HeapArray[RightChildpos]>HeapArray[rootIndex] && HeapArray[RightChildpos]>HeapArray[LeftChildpos])
                {
                    swap(HeapArray[rootIndex],HeapArray[RightChildpos]);
                    rootIndex=RightChildpos;
                    RightChildpos=RightChildIndex(rootIndex);
                    LeftChildpos=LeftChildIndex(rootIndex);
                }
                else if(HeapArray[LeftChildpos]>HeapArray[rootIndex] && HeapArray[LeftChildpos]>HeapArray[RightChildpos])
                {
                    swap(HeapArray[rootIndex],HeapArray[LeftChildpos]);
                    rootIndex=LeftChildpos;
                    LeftChildpos=LeftChildIndex(rootIndex);
                    RightChildpos=RightChildIndex(rootIndex);
                } else
                    break;
            }
            else
                break;
        }

    }
    int ParentIndex(int index)
    {
        int parent_index=floor((index-1)/2);
        return parent_index;
    }
    int LeftChildIndex(int index)
    {
        int leftChildIndex=(2*index)+1;
        if(leftChildIndex<=lastIndex)
            return leftChildIndex;
        else
            return -10;
    }
    int RightChildIndex(int index)
    {
        int rightChildIndex=(2*index)+2;
        if(rightChildIndex<=lastIndex)//if right child exist only then return otherwise return dumy value
            return rightChildIndex;
        else
            return -10;
    }
    bool HasRightChild(int index)
    {
        int rightChildIndex=(2*index)+2;
        /* ----------------------------
         * |  45  |  13| 12  | 23  | 11 |  | | | if index of 12 was given its right child cal will give,
         * -----------------------------
         * 2*2+2=6, althogh 6 is in limit of array but there is no child, so check if right child exceeding
         * limit of lastindex, return false, else true
         */
        if (rightChildIndex<=lastIndex)
            return true;
        else
            return false;
    }
    bool HasLeftChild(int index)
    {
        int leftChildIndex=(2*index)+1;
        if(leftChildIndex<=lastIndex)
            return true;
        else
            return false;
    }
    bool HasParent(int index)
    {
        if(index==0)//root has no parent
            return false;
        else
        {
            int parentIndex=floor((index-1)/2);//parent is always less than child in array
            if(parentIndex>=0 && parentIndex<lastIndex)
                return true;
            else
                return false;
        }
    }
    T peek()
    {
        return HeapArray[0];
    }
    void Swap(int index1, int index2)
    {
        swap(HeapArray[index1],HeapArray[index2]);
    }
    bool isEmpty()
    {
        if(lastIndex<=0)
            return true;
        else
            return false;
    }
    ~Heap()
    {
        delete []HeapArray;
    }

};
int main()
{

    Heap<string> obj(20);
    obj.Remove();
    obj.Insert();
    cout<<"Peak value is "<<obj.peek()<<endl;
    obj.Insert();
    cout<<"Peak value is "<<obj.peek()<<endl;
    obj.Insert();
    obj.Insert();
    obj.Insert();
    cout<<"Peak value is "<<obj.peek()<<endl;
    obj.Remove();
    cout<<"Peak value is "<<obj.peek()<<endl;
    obj.Remove();
    cout<<"Peak value is "<<obj.peek()<<endl;
    obj.Remove();
    cout<<"Peak value is "<<obj.peek()<<endl;
    obj.Remove();
    obj.Remove();
    obj.Remove();
    cout<<"TESTING OTHER METHODS"<<endl;
    cout<<"Adding 20 30 40 50 in heap"<<endl;
    obj.Insert();
    obj.Insert();
    obj.Insert();
    obj.Insert();
    cout<<"Heap is as: "<<endl;
    cout<<"   50     \n";
    cout<<"/     / 30 \n";
    cout<<"40         \n";
    cout<<"/          \n";
    cout<<"20          \n";
    cout<<"Check if 20 has child or not "<<endl;
    cout<<obj.HasLeftChild(3)<<endl;
    cout<<"Check parent index of 20"<<endl;
    cout<<obj.ParentIndex(3)<<endl;
    cout<<"Check if 40 has parent or not"<<endl;
    cout<<obj.HasParent(1)<<endl;
    cout<<"Check if root 50 has right child or not"<<endl;
    cout<<obj.HasRightChild(0)<<endl;
    cout<<"Check if 50 has parent or not"<<endl;
    cout<<obj.HasParent(0)<<endl;

    return 0;
}