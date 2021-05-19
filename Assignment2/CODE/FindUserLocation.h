//
// Created by abc on 5/17/2021.
//

#ifndef TRYTWO_FINDUSERLOCATION_H
#define TRYTWO_FINDUSERLOCATION_H

struct returnPointers
{
    User *temp_u;
    PrinterSpooler *temp_ps;
};
returnPointers* FindUser(string Uname,PrinterSpooler *p_head)
{
    returnPointers *x = new returnPointers;
    bool userFound=false;
    PrinterSpooler *temp=p_head;
    if (temp==NULL)//if search for user is made in without ant printer
    {
        x->temp_u=NULL;
        x->temp_ps=NULL;
        return x;
    }
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
    if(userFound)
    {
        x->temp_u=ptr;
        x->temp_ps=temp;
    }
    else
    {
        x->temp_u=NULL;
        x->temp_ps=NULL;
    }
    return x;
}

#endif //TRYTWO_FINDUSERLOCATION_H
