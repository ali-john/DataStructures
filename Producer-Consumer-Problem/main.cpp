/*
 *  Author: Syed Ali JOhn Naqvi
    Computer Engineering
    Degree 41 B
    ID: 307975
    Date: 6june 2021
 */

#include<iostream>
#include<stdlib.h>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

    std::mutex ready_mutex;
    std::condition_variable _check;
    int count=0;// keep track of max item produced, they should be less than 50 in all times
    int item_place=0;//place items in buffer.

    #include"SharedMemory.h"
    #include "Producer.h"
    #include "Consumer.h"

        int main()
    {

            cout<<"Producer consumer problem in operating system solution "<<endl;
            std::thread producer_thread(Producer);
            std::thread consumer_thread(Consumer);
            //join both threads in main thread.
            producer_thread.join();
            consumer_thread.join();
            cout<<"Successfully executed "<<endl;
            delete[] SharedMemory;
            return 0;
    }