#include<iostream>
#include <cmath>

using namespace std;

template<class T>
T ava_function(T arr[],int size)
{
    T total=0;
    for (int i = 0; i <size ; i++)
    {
        total+=arr[i];
    }
    return (total/size);
}
int main()
{
    int array1[3];
    float array2[4];
    double array3[3];
    cout<<"Enter values for integer array: "<<endl;
    for (int i = 0; i < 3; i++)
    {
        cin>>array1[i];
    }
    cout<<"Enter values for float array : "<<endl;
    for (int i = 0; i <4 ; i++)
    {
        cin>>array2[i];
    }
    cout<<"Enter values for double array :"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cin>>array3[i];
    }
    cout<<"Average of integer array is : "<<ava_function(array1,3)<<endl;
    cout<<"Average of float array is : "<<ava_function(array2,4)<<endl;
    cout<<"Average of double array is : "<<ava_function(array3,3)<<endl;





    return 0;
}