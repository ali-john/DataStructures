#include <iostream>
using namespace std;

class Converter
{
public:
    int *ptr=new int;
    //constructor
    Converter(){}

    void setValue(int &a)
    {
       ptr=&a;
    }
    int getValue()
    {
        return *ptr;
    }
    int convert()
    {
        *ptr=(*ptr)*1000;
        return *ptr;
    }
    ~Converter()
    {
        delete ptr;
        ptr=NULL;
    }
};

int main() {

    int kiloGramWeight=10;
    //CREATE object of converter type
    Converter obj;
    cout<<"Value of KiloGram weight is "<<kiloGramWeight<<endl;
    //set ptr of converter to kilogram weight variable
    obj.setValue(kiloGramWeight);
    //check if value is stored in ptr
    cout<<"Value of ptr is : "<<obj.getValue()<<endl;
    //convert kg weight to grams
    cout<<"After convert is called ptr has value : "<<obj.convert()<<endl;
    cout<<"After completion KilogramWeight has value : "<<kiloGramWeight<<endl;
    return 0;
}
