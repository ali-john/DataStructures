#include <iostream>
using namespace std;


//here float data type is used for accuracy in case of negative exponents otherwise
// answer will always be 0.



float power(float n,float x)
{
    if (x>=0)//if exponent is +ve
    {
        if(x==0)
        {

            return 1;
        }
        else
        {
            return n*power(n,x-1);
        }
    }
    else//if exponent is negative
    {
        return 1/n*(power(n,x+1));
    }


}
int main()
{

    float x=power(2,2);
    cout<<"2^2 is "<<x<<endl;
    float y=power(2,-1);
    cout<<"2^-1 is "<<y<<endl;
    float z=power(2,0);
    cout<<"2^0 is "<<z<<endl;
    return 0;
}
