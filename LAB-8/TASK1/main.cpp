#include <iostream>
#include <cstring>
using namespace std;
// The method finds all elements which are either at even positions or multiples of 3
string elementFinder(int arr[10],int i,int size,string ans)
{
    if ( i>=size)
    {
        return (ans+" ");
    } 
    else
    {
        if (i%2==0 || arr[i]%3==0)
        {
            ans=ans+to_string(arr[i])+" ";
        }
        return elementFinder(arr,i+1,size,ans);
    }
}
int main()
{

    int testArray[9]={11 ,36 ,69 ,43 ,15 ,34 ,67 ,72 ,68};
    string x=elementFinder(testArray,0,9,"");
    cout<<"The input array is: "<<endl;
    for (int i = 0; i < sizeof (testArray)/sizeof(testArray[0]); i++)
    {
        cout<<testArray[i]<<" ";
    }
    cout<<endl;
    cout<<"Output array is: "<<endl;
    cout<<x<<endl;
    return 0;
}
