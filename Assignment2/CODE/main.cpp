#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

struct Document
{
    string DocumentName;
    int DocumentPriority;
    string DocumentStatus;
    Document *link;
    Document *previousLink;
};//a node for document list
class DocumentList//maintain document queue of each user
{
public:
    Document *front;
    Document *rear;
    DocumentList();
    void InsertDocument();
    void DeleteDocument();
    bool isEmptyDocList();
    void PrintDocumentQueue();
    ~DocumentList();

};
struct User
{
    string UserName;
    int UserID;
    DocumentList docList;
    User *link;
    User *previousLink;
};
class UserClass//basic functionalities of user
{
public:
    User *head;//points to start of user list
    User *tail;//points at end of list
    UserClass();
    void AddUser();
    bool isEmptyUserList();
    ~UserClass();
};
struct PrinterSpooler
{
    int load=0;
    int printerID;
    PrinterSpooler *link;
    PrinterSpooler *previousLink;
    UserClass user;
};
class Printers
{
public:
    PrinterSpooler *printersHead;
    PrinterSpooler *printersTail;
    Printers();
    void AddUser();
    void AddDocuments();
    void Print();
    void PrintAllDocuments();//this method will print all documents of a user from its document queue.
    void DocumentStatus();//check document status
    void AddPrinter();
    void RemovePrinter();
    void ShowAvailablePrinters();//for testing
    bool isEmptyPrinters();
    ~Printers();
};
//header files
#include "CheckExistence.h"
#include "FindUserLocation.h"
void Deletion(PrinterSpooler *ptr_p,User *ptr_u);
//                               implementation of DocumentList class
//############################################################################################################
DocumentList::DocumentList()
{
    front=NULL;
    rear=NULL;
}
bool DocumentList::isEmptyDocList()
{
    if(front==NULL && rear==NULL)
        return true;
    else
        return false;
}
void DocumentList::InsertDocument() //insert document on basis of priority
{
    string docName;
    int priority;
    cout<<"Enter Document Name and priority(FROM 1-5)"<<endl;
    cin>>docName>>priority;
    if(priority>5 || priority<1)
        priority=5;
    Document *NewDocument=new Document;
    NewDocument->DocumentName=docName;
    NewDocument->DocumentPriority=priority;
    NewDocument->DocumentStatus="spooling";
    if(isEmptyDocList())//adding first document of a user.
    {
        NewDocument->link=NULL;
        NewDocument->previousLink=NULL;
        front=NewDocument;
        rear=NewDocument;
    }
    else
    {
        /*
         * Every document to be printed should have a priority from 1-5 i.e. 1(most prior) to 5(least
         * prior).
         * Insertion of document in user linked list should be on the basis of priority. High priority
         * documents should be entertained first. In case of same priority documents First come first
         * serve scheduling should be followed.
         */
        if(priority>=rear->DocumentPriority)//insert at end
        {
            rear->link=NewDocument;
            NewDocument->link=NULL;
            NewDocument->previousLink=rear;
            rear=NewDocument;

        }
        else
        {
            if(priority<front->DocumentPriority)//If most priority document come then insert at start
            {
                NewDocument->link=front;
                front->previousLink=NewDocument;
                front=NewDocument;
                front->previousLink=NULL;
            }
            else if(priority==front->DocumentPriority)//insert second node then on first come first serve basis
            {
                NewDocument->link=front->link;
                NewDocument->previousLink=front;
                front->link=NewDocument;
            }
            else
            {
                bool flag=true;
                Document *temp=front->link;
                while(flag && temp!=rear )
                {

                    if (priority < temp->DocumentPriority) {
                        NewDocument->link = temp;
                        NewDocument->previousLink = temp->previousLink;
                        Document *tempNew = temp->previousLink;
                        temp->previousLink = NewDocument;
                        tempNew->link = NewDocument;
                        flag = false;
                    } else if (priority == temp->DocumentPriority)//first come first serve basis
                    {
                        NewDocument->previousLink=temp;
                        NewDocument->link=temp->link;
                        temp->link=NewDocument;
                    }
                    else
                    {
                        temp = temp->link;
                    }
                }
            }
        }
    }
    
    
}
void DocumentList::DeleteDocument()
{
    if (isEmptyDocList())
    {
        cout<<"Document List is empty"<<endl;
    }
    else if(front->link==NULL && front->previousLink==NULL)// a single document
    {
        delete front;
        front=NULL;
        rear=NULL;
    }
    else // delete document from front.
    {
        Document *temp=front->link;
        delete front;
        temp->previousLink=NULL;
        front=temp;
    }
}
void DocumentList::PrintDocumentQueue()
{
    Document *temp=front;
    if(temp==NULL)
    {
        cout<<"DOCUMENTS QUEUE IS EMPTY YET"<<endl;
        cout<<"##################"<<endl;
        cout<<"##################"<<endl;
        cout<<endl;
    }
    else
    {
        while (temp!=NULL)
        {
            cout<<"DOCUMENT NAME : "<<temp->DocumentName<<endl<<"DOCUMENT PRIORITY : "<<temp->DocumentPriority<<endl;
            temp=temp->link;
        }
        cout<<"##################"<<endl;
        cout<<"##################"<<endl;
    }

}
DocumentList::~DocumentList()
{
    Document *ptr=front;
    while(ptr!=rear)
    {
        ptr=ptr->link;
        delete ptr->previousLink;
    }
    delete rear;
    rear=NULL;
    front=NULL;
    ptr=NULL;
}
//############################################################################################################
//                                implementation of user class
UserClass::UserClass()
{
    head=NULL;
    tail=NULL;
}
void UserClass::AddUser()
{
    system("Color 0E");
    string Uname;
    int Uid;
    cout<<"ENTER USER NAME, USER ID "<<endl;
    cin>>Uname>>Uid;
    User *NewUser=new User;
    NewUser->UserName=Uname;
    NewUser->UserID=Uid;
    if(isEmptyUserList())//First user
    {
        NewUser->link=NULL;
        NewUser->previousLink=NULL;
        head=NewUser;
        tail=NewUser;
    }
    else
    {
        NewUser->link=NULL;
        NewUser->previousLink=tail;
        tail->link=NewUser;
        tail=NewUser;
    }
}
bool UserClass::isEmptyUserList()
{
    if(head==NULL && tail==NULL)
        return true;
    else
        return false;
}
UserClass::~UserClass()
{
    User *ptr=head;
    while(ptr!=tail)
    {
        ptr=ptr->link;
        delete ptr->previousLink;
    }
    delete tail;
    head=NULL;
    tail=NULL;
    ptr=NULL;
}
//###############################################################################################################
//                                 implementation of Printers class
Printers::Printers()
{
    printersHead=NULL;
    printersTail=NULL;
}
void Printers::AddPrinter()
{
    //this method adds a new printer.
    int p_ID;
    system("Color 07");
    cout<<"ENTER PRINTER'S ID"<<endl;
    cin>>p_ID;
    while(cin.fail())//validate input for integers
    {
        cout << "Error" <<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> p_ID;
    }
    PrinterSpooler *NewPrinter=new PrinterSpooler;
    NewPrinter->printerID=p_ID;
    if (isEmptyPrinters())//first printer
    {
        NewPrinter->link=NULL;
        NewPrinter->previousLink=NULL;
        printersHead=NewPrinter;
        printersTail=NewPrinter;
    }
    else
    {
        NewPrinter->link=NULL;
        NewPrinter->previousLink=printersTail;
        printersTail->link=NewPrinter;
        printersTail=NewPrinter;
    }
}
bool Printers::isEmptyPrinters()
{
    if(printersTail==NULL && printersHead==NULL)
        return true;
    else
        return false;
}
void Printers::RemovePrinter()
{
    int p_ID;
    cout<<"Enter printers ID "<<endl;
    cin>>p_ID;
    PrinterSpooler *temp=printersHead;
    bool flag=false;
    while(temp!=NULL)
    {
        if(temp->printerID==p_ID)
        {
            flag=true;
            break;
        }
        else
            temp=temp->link;
    }
    if (flag)
    {
        if(temp==printersHead)
        {
            temp->link->previousLink=NULL;
            printersHead=temp->link;
            delete temp;
            temp=NULL;
        }
        else if(temp==printersTail)
        {
            temp->previousLink->link=NULL;
            printersTail=temp->previousLink;
            delete temp;
            temp=NULL;
        }
        else
        {
            temp->previousLink->link=temp->link;
            temp->link->previousLink=temp->previousLink;
            delete temp;
            temp=NULL;
        }
    }
    else
        cerr<<"INVALID PRINTER ID"<<endl;

}
void Printers::ShowAvailablePrinters()
{
    system("Color 06");
    PrinterSpooler *temp=printersHead;
    while(temp!=NULL)
    {
        cout<<"PRINTER ID: "<<temp->printerID<<endl<<"PRINTER'S LOAD: "<<temp->load<<endl;
        cout<<"PRINTERS USERS:"<<endl;
        cout<<"---------------"<<endl;
        cout<<"---------------"<<endl;
        if(temp->user.head==NULL)
        {
            cout<<"NO USER YET"<<endl;
            cout<<"------------"<<endl;
            cout<<endl;
        }
        else
        {
            User *ptr=temp->user.head;
            while(ptr!=NULL) {
                cout << "USER NAME: " << ptr->UserName <<endl<< "USER ID " << ptr->UserID <<endl;
                cout << "USER DOCUMENTS: " << endl;
                cout<<"  --------------"<<endl;
                ptr->docList.PrintDocumentQueue();
                ptr = ptr->link;
            }
        }
        temp=temp->link;
    }
}
Printers::~Printers()
{
    PrinterSpooler *ptr=printersHead;
    while(ptr!=printersTail)
    {
        ptr=ptr->link;
        delete ptr->previousLink;
    }
    delete printersTail;
    printersHead=NULL;
    printersTail=NULL;
    ptr=NULL;
}
void Printers::AddUser()
{
    system("Color 0D");
    PrinterSpooler *temp=printersHead;
    /*
     * When a command is sent by the user for printing, it should be queued in the printer having
     * least burden
     */
    if(temp==NULL)//Adding user without printer insertion
    {
        cout<<"NO PRINTER AVAILABLE. ADD PRINTER FIRST TO ADD USER"<<endl;
    }
    else
    {
        int minimumLoad=printersHead->load;
        PrinterSpooler *printersAddress=printersHead;
        while(temp!=NULL)
        {
            if(minimumLoad>temp->load)
            {
                minimumLoad=temp->load;//choose printer with minimum load
                printersAddress=temp;//hold address of printer with min load
                break;
            }
            else
                temp=temp->link;
        }
        if(!isEmptyPrinters())
        {
            printersAddress->user.AddUser();
            printersAddress->load=printersAddress->load+1;//increase load by 1 of particular printer.
        }
        else
        {
            cerr<<"No printer!!! Add printer then add user."<<endl;
        }
    }
}
void Printers::AddDocuments()
{
    system("Color 09");
    string Uname;
    cout<<"ENTER USER NAME:  "<<endl;
    cin>>Uname;
    returnPointers *p=FindUser(Uname,printersHead);
    if(p->temp_u==NULL)
    {
        cerr<<"EITHER USER DOES NOT EXISTS OR USER NAME INCORRECT"<<endl;
    }
    else
    {
        p->temp_u->docList.InsertDocument();
    }
    delete p;
}
void Printers::Print()
{
    string Uname;
    cout<<"ENTER USER NAME WHOSE DOCUMENTS IS TO BE PRINTED "<<endl;
    cin>>Uname;
    /*
     * Every time when a user sends a print command a check is made if the user already exists in the
     * printerSpooler
     */
    bool status=CheckUser(printersHead,Uname);
    if(status)
    {
        /*If the user’s buffer already exists, the document node is inserted in the user
        linked list according to the priority of document*/
        cerr<<"USER ALREADY EXISTING IN SPOOLER."<<endl;
        AddDocuments();
    }
    else
    {
        /*
         * If the user’s buffer does not exist than a new node is inserted in the printerSpooler linked list
         */
        cerr<<"USER BUFFER DOES NOT EXIST IN PRINTER SPOOLER. "<<endl;
        AddUser();
    }
}
void Printers::PrintAllDocuments()
{
    system("Color 07");
    string Uname;
    cout<<"ENTER USER NAME: "<<endl;
    cin>>Uname;
    returnPointers *p=FindUser(Uname,printersHead);
    if(p->temp_u==NULL || p->temp_ps==NULL)
    {
        cerr<<"USER DOES NOT EXIST "<<endl;
    }
    else
    {
        cout<<"USER NAME: "<<Uname<<endl;
        cout<<"DOCUMENTS: "<<endl;
        cout<<"---------"<<endl;
        p->temp_u->docList.PrintDocumentQueue();
        cout<<"#*#*#*#*#*#*#*#*#"<<endl;
        cout<<"#*#*#*#*#*#*#*#*#"<<endl;
        cout<<"PRINTING ALL DOCUMENTS OF "<<Uname<<endl;
        cout<<"#*#*#*#*#*#*#*#*#"<<endl;
        cout<<"#*#*#*#*#*#*#*#*#"<<endl;
        while(!p->temp_u->docList.isEmptyDocList())
        {
            cout<<p->temp_u->docList.front->DocumentName<<" IS PRINTED "<<endl;
            system("pause");
            p->temp_u->docList.DeleteDocument();
        }
        cout<<endl;
        cout<<endl;
        cout<<"################"<<endl;
        cout<<Uname<<" ALL DOCUMENTS GOT PRINTED "<<endl;
        //user node get deleted.
        Deletion(p->temp_ps,p->temp_u);
        delete p;
    }

}
void Printers::DocumentStatus()
{
    system("Color 0F");
    string Uname;
    cout<<"ENTER USER NAME ? "<<endl;
    cin>>Uname;
    returnPointers *p=FindUser(Uname,printersHead);
    if(p->temp_u==NULL || p->temp_ps==NULL)
    {
        cerr<<"USER DOES NOT EXISTS"<<endl;
    }
    else
    {
        if(!p->temp_u->docList.isEmptyDocList())
        {
            cout<<"USER NAME: "<<Uname<<endl;
            cout<<"###########"<<endl;
            cout<<"DOCUMENTS:"<<endl;
            cout<<"----------"<<endl;
            cout<<"----------"<<endl;
            Document *ptr=p->temp_u->docList.front;
            while(ptr!=NULL)
            {
                cout<<"DOCUMENT NAME: "<<ptr->DocumentName<<endl<<"DOCUMENT STATUS : "<<ptr->DocumentStatus<<endl;
                ptr=ptr->link;
            }
            char choice;
            cout<<"DO YOU WANT TO CANCEL PRINTING FOR ANY DOCUMENT ? [y/n]"<<endl;
            cin>>choice;
            if(choice=='Y' || choice=='y')
            {
                string docName;
                ptr=p->temp_u->docList.front;
                cout<<"ENTER DOCUMENT NAME: "<<endl;
                cin>>docName;
                while(ptr!=NULL)
                {
                    if(ptr->DocumentName==docName)
                        break;
                    else
                        ptr=ptr->link;
                }
                if(ptr==p->temp_u->docList.front && ptr==p->temp_u->docList.rear)//a single node
                {
                    p->temp_u->docList.front=NULL;
                    p->temp_u->docList.rear=NULL;
                    delete ptr;
                    ptr=NULL;
                }
                else if(ptr==p->temp_u->docList.front)
                {
                    p->temp_u->docList.front->link->previousLink=NULL;
                    p->temp_u->docList.front=p->temp_u->docList.front->link;
                    delete ptr;
                    ptr=NULL;
                }
                else if(ptr==p->temp_u->docList.rear)
                {
                    p->temp_u->docList.rear->previousLink->link=NULL;
                    p->temp_u->docList.rear=p->temp_u->docList.rear->previousLink;
                    delete ptr;
                    ptr =NULL;
                }
                else
                {
                    ptr->previousLink->link=ptr->link;
                    ptr->link->previousLink=ptr->previousLink;
                    delete ptr;
                    ptr=NULL;
                }
            }
        }
        else
        {
            cerr<<Uname<< " DOCUMENT QUEUE IS EMPTY "<<endl;
        }
    }

}
void Deletion(PrinterSpooler *ptr_p,User *ptr_u)
{

    User *head=ptr_p->user.head;
    User *tail=ptr_p->user.tail;
    User *temp=ptr_u;
    if(temp==head && head==tail && temp->docList.isEmptyDocList())//single user
    {
        User *ptr=head;
        ptr_p->user.head=NULL;
        ptr_p->user.tail=NULL;
        ptr_p->load--;
        delete ptr;
        ptr=NULL;
    }
    else if(temp==head && temp->docList.isEmptyDocList())//first user but not a single user.
    {
        User *ptr=head;
        ptr_p->load--;
        ptr_p->user.head=ptr_p->user.head->link;
        ptr_p->user.head->previousLink=NULL;
        delete ptr;
        ptr=NULL;
    }
    else if(temp==tail && head!=tail && temp->docList.isEmptyDocList())//last user
    {
        ptr_p->user.tail->previousLink->link=NULL;
        User *ptr=ptr_p->user.tail;
        ptr_p->user.tail=ptr_p->user.tail->previousLink;
        delete ptr;
        ptr=NULL;
    }
    else if(temp->docList.isEmptyDocList())//somewhere random in user list
    {
        ptr_u->previousLink->link=ptr_u->link;
        ptr_u->link->previousLink=ptr_u->previousLink;
        delete ptr_u;
    }
}
//######################################################################################
int main()
{
    //start page
    system("Color 0B");
    cout<<"########  ########  #### ##    ## ######## ######## ########   ######  \n"
          "##     ## ##     ##  ##  ###   ##    ##    ##       ##     ## ##    ## \n"
          "##     ## ##     ##  ##  ####  ##    ##    ##       ##     ## ##       \n"
          "########  ########   ##  ## ## ##    ##    ######   ########   ######  \n"
          "##        ##   ##    ##  ##  ####    ##    ##       ##   ##         ## \n"
          "##        ##    ##   ##  ##   ###    ##    ##       ##    ##  ##    ## \n"
          "##        ##     ## #### ##    ##    ##    ######## ##     ##  ###### "<<endl;
    cout<<"------------------------------------------------------------------------\n";
    cout<<"------------------------------------------------------------------------\n";
    cout<<endl;
    cout<<"             _____ _    _ _____ _____  ______ \n"
          "             / ____| |  | |_   _|  __ \\|  ____|\n"
          "            | |  __| |  | | | | | |  | | |__   \n"
          "            | | |_ | |  | | | | | |  | |  __|  \n"
          "            | |__| | |__| |_| |_| |__| | |____ \n"
          "             \\_____|\\____/|_____|_____/|______|\n";
          cout<<endl;

    cout<<"     -----------------------------------------------\n";
    cout<<"     ------------------------------------------------\n";
    cout<<"        ADD PRINTER()       -->ADDS A NEW PRINTER IN LIST\n"
          "        REMOVES PRINTER     -->REMOVES A PRINTER FROM LIST\n"
          "        SHOW PRINTER()      -->PRINTS AVAILABLE PRINTERS WITH THERE USERS\n "
          "        ADD USER()          -->ADDS A USER\n"
          "        ADD USER DOCUMENT() -->ADDS DOCUMENT FOR EXISTING USER\n"
          "        PRINT()             -->ADD USER IF NOT EXISTING OTHERWISE ADD USERS DOCUMENTS \n"
          "        PRINT ALL()         -->PRINT ALL DOCUMENTS OF AN EXISTING USER\n"
          "        DOCUMENT STATUS()   -->VIEW STATUS OF DOCUMENT "<<endl;
    cout<<"------------------------------------------------------------------------\n";
    cout<<"------------------------------------------------------------------------\n";
    cout<<"             __                  _   _                 \n"
          "            / _|                | | (_)                \n"
          "           | |_ _   _ _ __   ___| |_ _  ___  _ __  ___ \n"
          "           |  _| | | | '_ \\ / __| __| |/ _ \\| '_ \\/ __|\n"
          "           | | | |_| | | | | (__| |_| | (_) | | | \\__ \\\n"
          "           |_|  \\__,_|_| |_|\\___|\\__|_|\\___/|_| |_|___/"<<endl;
    cout<<"------------------------------------------------------------------------\n";
    cout<<"------------------------------------------------------------------------\n";
    Printers obj;
    int choice=0;
    do {
        system("Color 0B");
        cout<<"1--> ADD PRINTER             2-->REMOVE PRINTER        3-->SHOW PRINTERS AND THERE DATA\n"
            <<"4--> ADD USER                5-->ADD USER DOCUMENTS    6-->PRINT\n"
            <<"7-->PRINT ALL DOCUMENTS      8-->DOCUMENT STATUS       9-->QUIT"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                obj.AddPrinter();
                break;
            }
            case 2:
            {
                obj.RemovePrinter();
                break;
            }
            case 3:
            {
                obj.ShowAvailablePrinters();
                break;
            }
            case 4:
            {
                obj.AddUser();
                break;
            }
            case 5:
            {
                obj.AddDocuments();
                break;
            }
            case 6:
            {
                obj.Print();
                break;
            }
            case 7:
            {
                obj.PrintAllDocuments();
                break;
            }
            case 8:
            {
                obj.DocumentStatus();
                break;
            }
            case 9:
            {
                cout<<"    //   ) ) \\\\    / /  //---/ /   \n"
                      "   //___/ /   \\\\  / /  //____      \n"
                      "  / __  (      \\\\/ /  // ____      \n"
                      " //    ) )      / /  //            \n"
                      "//____/ /      / /  //____/ /      \n";
                break;

            }
            default:
                break;
        }
        } while (choice<9);

    return 0;
}
