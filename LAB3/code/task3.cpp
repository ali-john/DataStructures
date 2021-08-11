#include <iostream>
using namespace  std;

template<class T>
class TemplateClass
{
public:
    //creating pointer
    T *ptr;
    //size variable
    int size=0;
    //DEFAULT CONSTRUCTOR:
    TemplateClass()
    {
        //declaring an array of default size of 3
        size=3;
        ptr=new T[size];

    }
    //parametrized constructor. Since size is always int make parameter fixed data type int
    TemplateClass(int sizeOfArray)
    {
        size=sizeOfArray;
        ptr=new T[sizeOfArray];
    }
    //copy constructor:
    TemplateClass(const TemplateClass &a)
    {
        //store the size of passed object into size variable
        size=a.size;
        //creating array with size of passed object size
        ptr=new T[a.size];
        // copying the content of array of passed object into new object array
        for (int i = 0; i <a.size ; i++)
        {
            ptr[i]=a.ptr[i];
        }
    }
    //set method to set user values into array:
    void setValue()
    {
        for (int i = 0; i < size; i++)
        {
            T v;
            cout<<"Enter value : "<<endl;
            cin>>v;
            ptr[i]=v;

        }
    }
    //resize array method
    void Resize(int newSize)
    {
       // creating a new pointer array of resized size
        T *ptrNew=new T[newSize];
        //copying content of previous array into resized array
        for (int i = 0; i < size; i++)
        {
            ptrNew[i]=ptr[i];
        }
        //setting the size variable of array to new resized size
        size=newSize;
        //delete previous array and set to null
        delete []ptr;//
        ptr=NULL;
        //points the ptr to new array location and delete new array ptr also
        ptr=ptrNew;
        delete []ptrNew;
        ptrNew=NULL;

    }
    // display method to show the content of array
    void ShowArray()
    {
        cout<<"Array is: "<<endl;
        for (int i = 0; i < size; i++)
        {
               cout<<ptr[i]<<"  ";
        }
        cout<<endl;
    }
    //destructor for de-allocating memory:
    ~TemplateClass()
    {
        delete []ptr;
        ptr=NULL;
    }
};

int main()
{
    //test plans given for code will be executed
    //plan 1:
    //creating an array of int type of default size which was set to 3:
    TemplateClass<int> template_class1;
    cout<<template_class1[1];
    //For more clarity lets print the default array also.
    cout<<"Default array is : "<<endl;
    template_class1.ShowArray();


    //plan 2:
    //an array of user input size. Let it be 6
    TemplateClass<int> template_class2(6);
    //lets also print it:
    cout<<"An array of user type with size 6 is: "<<endl;
    template_class2.ShowArray();

    //plan 3
    //an array of float type with user size of 4
    TemplateClass<float> template_class3(4);
    //print it also
    cout<<"An array of float type with size 4 is: "<<endl;
    template_class3.ShowArray();

    //plan 4
    // an array of copy of int array of size 6 with object template_class2
    TemplateClass<int> template_class4=template_class2;
    //print it also:
    cout<<"Copy array is : "<<endl;
    template_class4.ShowArray();

    //plan 5
    //setting values to float type array of size 4
    cout<<"Enter values for float array:"<<endl;
    template_class3.setValue();
    cout<<"Set values to float array of size 4, the array is: "<<endl;
    template_class3.ShowArray();

    //plan 6
    //setting values to default array of size 6
    cout<<"Enter values for default array: "<<endl;
    template_class1.setValue();
    cout<<"After setting values to default array it is: "<<endl;
    template_class1.ShowArray();

    //case 7:
    //setting value to int array of size 6 which was copied
    cout<<"Enter values for int array of size 6 which is copied array: "<<endl;
    template_class4.setValue();
    //display array after setting values:
    cout<<" copied Array after setting values is : "<<endl;
    template_class4.ShowArray();

    //plan 8:
    //array is already displayed above so this plan is completed.

    //plan 9
    //calling set function for template_class2 object
     cout<<"Enter values for int array of type 6: "<<endl;
     template_class2.setValue();
     cout<<"Array with size 6 of int type is : "<<endl;
     template_class2.ShowArray();

     //plan 10:
     // displaying float array:
     cout<<"Float array is : "<<endl;
     template_class3.ShowArray();

     //plan 11:
     //int array already displayed above. This plan is complete

     //plan 12:
     //resizing copied array to size 4 which was initially 6
     cout<<"Array before resizing is: "<<endl;
     template_class4.ShowArray();
     template_class4.Resize(4);
     cout<<"Array after resizing to size 4 is: "<<endl;
     template_class4.ShowArray();

     //plan 13:
     //resized array showed above. Plan is executed

    return 0;
}
