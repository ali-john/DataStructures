#include <iostream>
using namespace std;

class Square
{
private:
    int side;

public:

    Square(int side)
    {
        this->side=side;
    }
//Area method
    void Area() const
    {
        cout<<"Area of square with side "<<side<<" is "<<side*side<<endl;
    }
//perimeter method
    void Perimeter() const
    {
        cout<<"Perimeter of square with side "<<side<<" is "<<4*side<<endl;
    }
};
int main() {

    int a=0;
    cout<<"Enter Side of square: "<<endl;
    cin>>a;
    Square obj(a);
    obj.Area();
    obj.Perimeter();
    return 0;
}
