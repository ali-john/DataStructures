//
// Created by abc on 6/10/2021.
//

#ifndef PRODUCER_CONSUMER_PROBLEM_PRODUCER_H
#define PRODUCER_CONSUMER_PROBLEM_PRODUCER_H
/*
 *  Creating a method for generating random values by rand() using c++ standard library.
 */
    int Produce_Item()
    {
        /*
         *  Set range of values from 0-150.
         */
             int item=rand()%150;
             return item;
    }
/*
 *  Producer method. It will write data to shared memory while allowing mutual exclusion.
 *  Give solution to P-C problem and does not write more than buffer size
 */
        void Producer()
        {

             while(count<50)//produce only 150 items
            {
                    //critical section. Writing to buffer
                    std::unique_lock<std::mutex> lck (ready_mutex);
                    //call wait --> lambda function used
                    _check.wait(lck, []() {return item_place<max_size_of_buffer;});
                    //call above method to give a random value
                    int data=Produce_Item();
                    //place data in buffer
                    SharedMemory[item_place]=data;
                    cout<<"Producer produced random item"<<data<<" items place is "<<item_place+1<<endl;
                    //increment the next place holder of buffer
                    item_place++;
                    count++;
                    // unlock the mutex and notify the waiting process
                    lck.unlock();
                    _check.notify_one();

            }

        }
#endif //PRODUCER_CONSUMER_PROBLEM_PRODUCER_H
