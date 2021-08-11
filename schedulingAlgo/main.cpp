/*
 *  DISK SCHEDULING ALGORITHN
 *  SSTF AND FCFS
 */

#include <iostream>
#include <cstdlib>//for rand
#include <list>
#include<cmath>
using namespace std;

struct sstfNode

{
    int value;
    bool entertained=false;

};

const int sstf_size=10;

list<sstfNode> SSTF_list;

list<sstfNode>::iterator itr;

    void Fill_list()

    {

        SSTF_list.clear();
        sstfNode obj;
        for (int i=0; i<sstf_size;i++)
        {
            int request_value=rand()%100;
            obj.value=request_value;
            obj.entertained=false;
            SSTF_list.push_back(obj);
        }
        cout<<"Total request Sequence is: "<<endl;
        for (itr=SSTF_list.begin();itr!=SSTF_list.end();itr++)
            cout<<itr->value<<" ";
        cout<<endl;


    }

//calculate the nearest head movement
    list<sstfNode>::iterator FindShortest(int head)

    {

        int minimum=100000;
        auto  itr_shortest=itr;

        for (itr=SSTF_list.begin();itr!=SSTF_list.end();itr++)
        {
            if ( abs(itr->value - head) < minimum && !itr->entertained)
            {
                minimum=abs(itr->value-head);
                itr_shortest=itr;

            }

        }

            cout<<"shortest chosen is "<<itr_shortest->value<<endl;
            return itr_shortest;

    }


    void SSTF(int start)

    {
        int saved=start;
        Fill_list();
        long int disk_movements = 0;
        list<sstfNode>::iterator itr_two;

            for (int i = 0; i <sstf_size; i++)

            {

                    itr_two=FindShortest(start);
                    disk_movements=disk_movements+(abs(start-itr_two->value));
                    start=itr_two->value;
                    itr_two->entertained=true;

            }

        cout<<"SEEK TIME IS "<<disk_movements<<" WITH GIVEN HEAD "<<saved<<endl;
        SSTF_list.clear();


    }


    void FirstComeFirstServe(int starting_point)
    {


        int request_array[10];//an array of requests of size 10.

        //fill array with total random numbers from 0-99

        for (int i=0;i<10;i++)

        {
            int request_number=rand()%10;
            request_array[i]=request_number;
        }


        long int disk_movements=0;//keep track of all disk movements needed to serve the request.
        int saved=starting_point;

        for (int i=0; i<10;i++)

        {
            int current_request=request_array[i];
            disk_movements+=abs(current_request - starting_point);
            starting_point=request_array[i];

        }
        cout<<"The seek operations needed to complete request is "<<disk_movements<<" with starting value "<<saved<<endl;




    }


    int main()
    {


        SSTF(50);




        return 0;
    }
