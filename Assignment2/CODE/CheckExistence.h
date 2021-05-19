//
// Created by abc on 5/17/2021.
//

#ifndef TRYTWO_CHECKEXISTENCE_H
#define TRYTWO_CHECKEXISTENCE_H
bool CheckUser(PrinterSpooler *printer,string Uname)
{
    //printer pointer will get head of printer ll
    bool userFound=false;
    PrinterSpooler *temp=printer;
    if(temp==NULL)
        return false;
    User *ptr=temp->user.head;
    while(temp!=NULL)
    {
        while(ptr!=NULL)
        {
            if(ptr->UserName==Uname)
            {
                userFound=true;
                break;
            }
            else
                ptr=ptr->link;
        }
        if(userFound)
            break;
        else
        {
            temp=temp->link;
            if(temp==NULL)
                break;
            else
                ptr=temp->user.head;
        }
    }
    if(!userFound)
        return false;
    else
        return true;
}
#endif //TRYTWO_CHECKEXISTENCE_H
