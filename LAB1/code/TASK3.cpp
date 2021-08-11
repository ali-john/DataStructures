#include <iostream>
using namespace std;

class Count
{
public:
    static int count;
    int pos;
    Count()
    {
        count+=1;
        pos=count;
    }
    void DisplayTotal()
    {
        cout<<"Objects created are "<<count<<endl;
    }
    int MyPos()
    {
        return pos;
    }
};
int Count::count=0;
int main() {
    //first object created
    Count obj;
    //second object
    Count obj1;
    //check total objects using first object
    obj.DisplayTotal();
    //check position of first object.
    cout<<"object obj created at position "<<obj.MyPos()<<endl;
    //create 2 more objects
    Count obj3;
    Count obj4;
    //check position of third object
    cout<<"object obj3 created at position "<<obj3.MyPos()<<endl;
    //check total objets
    obj4.DisplayTotal();
    //check position of fourth object.
    cout<<"object obj4 created at position "<<obj4.MyPos()<<endl;
    //now finally check position of object obj1:
    cout<<"Checking position of obj1 at "<<obj1.MyPos()<<endl;

    return 0;
}
