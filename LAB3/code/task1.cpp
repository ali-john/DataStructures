#include <iostream>
using namespace std;

//class creation
class Swaps
{
public:
    //pointers
    char *ptr1=new char ;
    char *ptr2=new char;

    //default constructor:
    Swaps(){}
    void setValue(char charmem1,char charmem2)
    {
        *ptr1=charmem1;
        *ptr2=charmem2;
    }
    char getValue(int PointerNumber)
    {
        if (PointerNumber==1)
            return *ptr1;
        else
            return *ptr2;
    }
    //swap method:
    void swap()
    {
        char temp;
        temp=*ptr2;
        *ptr2=*ptr1;
        *ptr1=temp;

    }

    //display method to display both pointer values
    void Display()
    {
        cout<<"Value of ptr1 is "<<*ptr1<<endl;
        cout<<"Value of ptr2 is "<<*ptr2<<endl;
    }
    //destructor:
    ~Swaps()
    {
        delete ptr1;
        delete ptr2;
        ptr1=NULL;
        ptr2=NULL;
        cout<<"Destructor has been called";
    }

};

int main()
{
    //Create object of class
     Swaps obj;
     //set values
     obj.setValue('a','c');
     //get ptr1 content by passing 1 as arg
     cout<<"GetValue method has given: "<<obj.getValue(1)<<endl;
     //DISPLAY content of both pointers
     obj.Display();
     //call swap method
     obj.swap();
     cout<<"Content of both pointers after swap is called : "<<endl;
     obj.Display();

}
