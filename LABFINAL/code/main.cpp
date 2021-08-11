#include <iostream>
#include <queue>
#include<list>
using namespace std;
struct Applicant_Data
{
    string Name;
    string PhoneNumber;
    string CNIC;
    string DOB;
    int Number_of_pages;
    int tokenNumber;
    int TotalFees;
    string document;
    bool BiometricVerified=false;
    bool FeesPaid=false;
    bool attested=false;
};

class DegreeAttestation
{
public:
    int Token_number;
    list<Applicant_Data> registration_queue;
    list<Applicant_Data>::iterator itr=registration_queue.begin();
    list<Applicant_Data> attestedApplicantsRecord;
    list<Applicant_Data>::iterator  record_itr=attestedApplicantsRecord.begin();
    DegreeAttestation()//constructor
    {
        Token_number=0;
    }
    void Registration()
    {
        Applicant_Data obj;
        string name,phone,cnic,date_of_birth;
        int pages;
        cout<<"ENTER NAME"<<endl;
        cout<<"ENTER PHONE NUMBER:"<<endl;
        cout<<"ENTER CNIC:"<<endl;
        cout<<"ENTER DOB:"<<endl;
        cout<<"NUMBER OF PAGES SEQUENTIALLY:"<<endl;
        cin>>name>>phone>>cnic>>date_of_birth>>pages;
        obj.Name=name;
        obj.CNIC=cnic;
        obj.DOB=date_of_birth;
        obj.Number_of_pages=pages;
        obj.PhoneNumber=phone;
        Token_number++;//token number generated
        obj.tokenNumber=Token_number;
        registration_queue.push_back(obj);

    }
    void FeesPayment()
    {
       itr=registration_queue.begin();
       if(!itr->FeesPaid)
       {
           int pages=itr->Number_of_pages;
           int fees=2000*pages;
           itr->TotalFees=fees;
           itr->FeesPaid=true;
           cout<<"Your fees RS"<<fees<<" paid"<<endl;
       }
       else
           cout<<"FEees already submitted"<<endl;

    }
    void BiometricVerification()
    {
        itr=registration_queue.begin();
        /*
         * creating a simple captcha to see verification
         */
        if(itr->FeesPaid && !(itr->BiometricVerified))
        {
            int captcha=3000;
            int input=0;
            cout<<"To confirm verification enter the displayed number correctly"<<endl;
            cout<<" ##3000##"<<endl;
            cin>>input;
            if(input==captcha)//if verification is done
            {
                itr->BiometricVerified=true;
                int choice=0;
                cout<<"PRESS 1 FOR going to attestation.. Else press 2 to wait"<<endl;
                cin>>choice;
                if(choice==1)
                    AttestationWindow();
                else
                {
                    cout<<"keep wait "<<endl;
                }

            }
            else
            {
                cout<<"WELCOME TO HELP DESK"<<endl;
                int choice=0;
                cout<<"PRESS 1 FOR ENDING SUBMISSON, PRESS 2 TO AGAIN WAIT IN QUEUE"<<endl;
                cin>>choice;
                if(choice==1)
                    registration_queue.pop_front();
                else if(choice==2)
                {
                    Applicant_Data newuser=registration_queue.front();
                    newuser.tokenNumber=Token_number;
                    registration_queue.pop_front();
                    registration_queue.push_back(newuser);
                    cout<<"You are added again in queue. wait"<<endl;
                }

            }
        }
        else
        {
            cout<<"Fees not paid yet or already biometric verified. "<<endl;
        }


    }

    void AttestationWindow()
    {
        itr=registration_queue.begin();
        if(itr->BiometricVerified && !(itr->attested))
        {
            string copy;
            cout<<"Enter copy of document"<<endl;
            cin>>copy;
            int captcha=5000;
            int input=0;
            cout<<"To confirm documents verification enter the displayed number correctly"<<endl;
            cout<<" ##5000##"<<endl;
            cin>>input;
            if(input==captcha)
            {
                itr->attested=true;
                itr=registration_queue.begin();
                itr->document=copy;
                GenerateSlip();
            }
            else
            {
                cout<<"Verification not successful"<<endl;
                AttestationWindow();
            }
        }
        else
        {
            cout<<"YOu are not verified yet"<<endl;
        }


    }
    void GenerateSlip()
    {
        itr=registration_queue.begin();
        if(itr->BiometricVerified && itr->attested && itr->FeesPaid)
        {
            cout<<"You can take documents at "<<itr->tokenNumber<<" th "<<"of june"<<endl;
            Applicant_Data VerifiedUser=registration_queue.front();
            registration_queue.pop_front();
            attestedApplicantsRecord.push_back(VerifiedUser);
        }
        else
        {
            cout<<"You are not verified"<<endl;

        }

    }

    void Display()//testing and of admin panle
    {
        int key=789,input;
        cout<<"To enter backend, enter secret key"<<endl;
        cin>>input;
        if(input==key)
        {
            for(itr=registration_queue.begin();itr!=registration_queue.end();itr++)
            {
                cout<<"User Name"<<itr->Name<<endl;
                cout<<"User token"<<itr->tokenNumber<<endl;
                cout<<"User Document:"<<itr->document<<endl;
            }
        }

    }
    ~DegreeAttestation()
    {
        registration_queue.clear();
    }


};
int main()
{
    DegreeAttestation system;
    cout<<"INSTRUCTIONS:"<<endl;
    cout<<"ONCE ONE PERSON IS GOING THROUGH ENTIRE PROCESS, NEXT PERSON CAN NOT CAME. "<<endl;
    cout<<"FOLLOW AS-->REGISTER URSELF-->PAY FEES-->Biometric VERIFY-->GENERATE SLIP"<<endl;
    int cont=1;
    do
    {
        cout<<"WELCOME TO REGISTRATION CENTER XYZ UNIVERSITY "<<endl;
        cout<<"PRESS 1-->TO REGISTER  \n";
        cout<<"PRESS 2-->TO PAY FEES  \n";
        cout<<"PRESS 3-->TO BIOMETRICALLY VERIFY URSELF  \n";
        cout<<"PRESS 4-->TO GENERATE SLIP  \n";
        cout<<"PRESS 5-->ADMIN PANEL"<<endl;
        int choice=0;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                system.Registration();
                break;
            }
            case 2:
            {
                system.FeesPayment();
                break;
            }
            case 3:
            {
                system.BiometricVerification();
                break;
            }
            case 4:
            {
                system.AttestationWindow();
            }
            case 5:
            {
                system.Display();
            }
            default:
                break;
        }
           cout<<"Want to continue? press 1"<<endl;
        cin>>cont;

    }while(cont==1);


    return 0;
}
