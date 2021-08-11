#include <iostream>
#include <cmath>
using namespace std;
//I am assuming real and imaginary part as integer
class ComplexNumber
{
private:
    int realNum;
    int imaginaryNum;

public:
    ComplexNumber()
    {
        realNum=0;
        imaginaryNum=0;
    }
    ComplexNumber(int real,int img)
    {
        realNum=real;
        imaginaryNum=img;
    }
    void Display()const
    {
        cout<<"Complex Number is "<<realNum<<"+"<<imaginaryNum<<"i"<<endl;
    }
    void Magnitude()const
    {
        float a=sqrt(realNum*realNum+imaginaryNum*imaginaryNum);
        cout<<"Magnitude of number is "<<a<<endl;
    }
    string Add(int real,int img)const
    {
        int NetReal=real+realNum;
        int NetImg=img+imaginaryNum;
        return "Addition of Complex number gives "+to_string(NetReal)+"+"+to_string(NetImg)+"i";
    }

};
int main() {

    //default constructor calling
    ComplexNumber obj;
    obj.Display();
    obj.Magnitude();
    int a,b;
    cout<<"Enter Real And Imaginary part of Complex Number:"<<endl;
    cin>>a>>b;
    cout<<obj.Add(a,b);
    cout<<endl;
    //parametrized constructor calling
    cout<<"Enter Real And Imaginary part of 1st Complex Number:"<<endl;
    cin>>a>>b;
    ComplexNumber obj1(a,b);
    obj1.Display();
    obj1.Magnitude();
    cout<<"Enter Real And Imaginary part of 2nd Complex Number:"<<endl;
    cin>>a>>b;
    cout<<obj1.Add(a,b);
    return 0;
}
