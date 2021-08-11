#include <iostream>
using namespace std;
#include <list>
#include <iterator>
#include <cmath>
struct User
{
    string User_name;
    string Password;
};
class LoginSystem
{
public:
    static const int size=7;
    list<User> HashTable[size];
    list<User>::iterator itr= HashTable->begin();


    int HashFunction(string data)
    {
        int temp=0,location=0;
        for (int i=0;i<data.length();i++)
            temp+=data[i]*pow(2,i)+data[i]+10;
        location=temp%size;
        return location;
    }
    void SignUp()
    {
        User user;
        string Password,UserName;
        cout<<"Enter User Name "<<endl;
        cin>>UserName;
        user.User_name=UserName;
        cout<<"Enter Password "<<endl;
        cin>>Password;
        user.Password=Password;
        int loc=HashFunction(UserName);
        bool UserExist=false;
        for (itr=HashTable[loc].begin(); itr!=HashTable[loc].end();itr++)
        {
            if(itr->User_name==UserName)//user already in table
            {
                cout<<"User already exists. Sign in instead"<<endl;
                UserExist=true;
                break;
            }
        }
        if(!UserExist)
        {
            HashTable[loc].push_back(user);
            cout<<"Sign Up successfully"<<endl;
        }

    }
    void SignIn()
    {
        User user;
        string Password,UserName;
        cout<<"Enter User Name "<<endl;
        cin>>UserName;
        int loc=HashFunction(UserName);
        bool UserFound=false;
        bool passwordMatched=false;
        for (itr=HashTable[loc].begin();itr!=HashTable[loc].end();itr++)
        {
            if(itr->User_name==UserName)
            {
                UserFound=true;
                cout<<"Enter Password "<<endl;
                cin>>Password;
                if(itr->Password==Password)
                    passwordMatched=true;
                else
                    passwordMatched=false;
            }
        }

        if(!UserFound)
            cout<<"User does not Exist. Try Signing Up first"<<endl;
        else
        {
            if(passwordMatched)
                cout<<"Login Successful"<<endl;
            else
                cout<<"Incorrect Password. Try again "<<endl;
        }

    }
    void Display()//for testing purpose
    {
        for (int i=0; i<size; i++)
        {
            for (itr=HashTable[i].begin(); itr!=HashTable[i].end();itr++)
            {
                cout<<"User Name :"<<itr->User_name<<endl;
            }
        }
    }
    void Search(string Uname)
    {
        int loc=HashFunction(Uname);
        bool exists=false;
        for (itr=HashTable[loc].begin(); itr!=HashTable[loc].end();itr++)
        {
            if(itr->User_name==Uname)//user in table
            {
                exists=true;
                cout<<"User exists at "<<loc<<endl;
                break;
            }
        }
        if(!exists)
        {
            cout<<"User does not exist"<<endl;
        }
    }
    bool isEmpty()
    {
        if(HashTable->empty())
            return true;
        else
            return false;
    }
    ~LoginSystem()
    {
        HashTable->clear();
    }

};
int main()
{
    LoginSystem obj;
    cout<<"### login user "<<endl;
    obj.SignIn();
    cout<<"### Sign up user "<<endl;
    obj.SignUp();
    cout<<"### login user "<<endl;
    obj.SignIn();
    cout<<"### login user "<<endl;
    obj.SignIn();
    cout<<"### SIGNUP user "<<endl;
    obj.SignUp();
    cout<<"### SIGNUP user "<<endl;
    obj.SignUp();
    cout<<"### login user "<<endl;
    obj.SignIn();
    cout<<"### ALL USERS #### "<<endl;
    obj.Display();

    return 0;
}
