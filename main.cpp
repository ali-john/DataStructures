#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

template<class T>//templated type T
class DynamicDataHolder
{
public:
    int sizeArr=0;//will hold array size
    int frePos=0;//will keep track of free positions in array
    T *ptr;
    DynamicDataHolder()//default constructor
    {
        //declaring an array of default sizeArr of 3
        sizeArr=2;
        ptr=new T[sizeArr]();//setting to default initilization
    }
    //parametrized constructor
    DynamicDataHolder(int sizeOfArray)
    {
        sizeArr=sizeOfArray;
        ptr=new T[sizeOfArray]();
    }
    //copy constructor:
    DynamicDataHolder(const DynamicDataHolder &a)
    {
        //store the sizeArr of passed object into sizeArr variable
        sizeArr=a.sizeArr;
        //copy free positions info
        frePos=a.frePos;
        //creating array with sizeArr of passed object sizeArr
        ptr=new T[a.sizeArr];
        // copying the content of array of passed object into new object array
        for (int i = 0; i <a.sizeArr ; i++)
        {
            ptr[i]=a.ptr[i];
        }
    }
    void insert(T val)//method to insert values at last available index
    {
        if (frePos == sizeArr)//if no space available, resize array with twice size
        {
            resize(2*sizeArr);
            ptr[frePos]=val;
            frePos++;
        }
        else
        {
            ptr[frePos]=val;
            frePos++;
        }

    }
    //capacity function:
    int capacity()
    {
        return (sizeArr - frePos);
    }
    //resize method:
    void resize(int newSize)//takes newSize of array as input
    {
        try {
            if (newSize > numeric_limits<int>::max()) {
                throw invalid_argument("Function arg much bigger");
            }
            // creating a new pointer array of resized sizeArr
            T *ptrNew = new T[newSize]();
            //copying content of previous array into resized array
            for (int i = 0; i < sizeArr; i++) {
                ptrNew[i] = ptr[i];
            }
            //setting the sizeArr variable of array to new resized sizeArr
            sizeArr = newSize;
            //delete previous array
            delete[]ptr;//
            //points the ptr to new array location and delete new array ptr also
            ptr = ptrNew;
            ptrNew = NULL;
            delete[]ptrNew;
        }
        catch (bad_alloc &exception)
        {
            cerr<<"bad allocation detected"<<exception.what()<<endl;
        }
        catch (invalid_argument &e)
        {
            cerr<<e.what()<<endl;
        }
        catch (out_of_range x)
        {
            cerr<<x.what()<<endl;
        }
        catch (...)
        {
            cout<<"Unknown exception occured during resizing array "<<endl;
        }

    }
    //sizeArr method
    int size()
    {
        /*variable sizeArr at top of code is holding
         * the sizeArr of dynamic array. Simply return it*/
        return sizeArr;
    }
    //overload for [] operator
    T &operator[](int x)
    {
        /*
         * if argument passed is greater than size of array, grow the array
         * with twice the size. In case of cout it will display default value
         * 0 in case of int, float and null char in case of characters. In case of cin,
         * value set to index after resized array.
         */
        if (x>=sizeArr)
        {
            resize(2*sizeArr);
            return(ptr[x]);
        }
        else
            return (ptr[x]);
    }
    //== overload
    string operator==(const DynamicDataHolder & b)
    {
        bool flag= true;
        if (this->sizeArr == b.sizeArr)//compare size of both arrays
        {
            for (int i = 0; i < b.sizeArr; i++)//compare content of arrays
            {
                if (this->ptr[i] == b.ptr[i])
                    continue;
                else
                    flag=false;
            }
            if (flag==true)
                return "true";
            else
                return "false";
        }
        else
        {
            return ("false");
        }

    }

    void ShowArray()//additional method for clarity
    {
        cout<<"Array is: "<<endl;
        for (int i = 0; i < sizeArr; i++)
        {
            cout<<ptr[i]<<"  ";
        }
        cout<<endl;
    }
    //destructor:
    ~DynamicDataHolder()
    {
        delete[]ptr;
        ptr=NULL;
    }

};
int main()
{
    DynamicDataHolder <int> obj; // declare an object holding array of any default size
    cout<<"Default array of obj is:"<<endl;
    obj.ShowArray();//should show 0 0 as default array is of size 2
    DynamicDataHolder <char> obj2(5); // declare an object holding array of size 5
    DynamicDataHolder <char> obj3=obj2; // creates copy
    cout<<"Comparing obj2 and obj 3"<<endl;
    cout<< (obj3==obj2); // compares two objects with respect to their data holder values and returns //true if both are same
    cout<<endl;
    for(int i=0; i<10; i++)
    {
        obj.insert(i*2); // every time insert function get called, it should insert value at the end of data holder
    }
    cout<<"After inserting 10 values to array with size 2"<<endl;
    obj.ShowArray();
    //array when created was of size 2, then grow to 4, then to 8, then to 16.
    //10 elements inserted, so capacity should be now 6
    cout<<"obj.capacity() gives  "<<obj.capacity() ; // should return the number of empty spaces in data holder
    cout<<endl;
    //size of obj array is 16, should show 16
    cout<<"obj.size gives  "<<obj.size(); // should return the size of dataHolder
    cout<<endl;
    obj.resize(15) ; // should resize the dataHolder
    cout<<"After resizing to 15 size, array of obj is :"<<endl;
    obj.ShowArray();
    //since obj2 is char array which is set to null, so obj2[4] should show nothing
    cout<<"obj2[4] is shown"<<endl;
    cout<< obj2[4]; // should display 5th element of data holder
    cout<<endl;
    cout<<"enter value for obj at 10 index"<<endl;
    cin>> obj[10]; // should take input for 10th element of data holder, here the size of data holder is 5, so it should be // catered before taking the input
    obj.ShowArray();
    DynamicDataHolder <int> obj4=obj;//creates copies
    /*
     * some more testing of code:
     */
    //check if content of obj4 is sane as obj or not:
    cout<<"obj4 after copying from obj:"<<endl;
    obj4.ShowArray();
    cout<<"Size of obj4 is "<<obj.size()<<endl;
    //insert values in obj2 char array
    obj2.insert('x');
    obj2.insert('a');
    obj2.insert('l');
    obj2.insert('e');
    obj2.insert('s');
    //show content of obj2 array
    cout<<"after inserting values obj2 array is: "<<endl;
    obj2.ShowArray();
    cout<<"5th element of obj2[] is: "<<endl;
    cout<<obj2[4];
    cout<<endl;

    return 0;
}