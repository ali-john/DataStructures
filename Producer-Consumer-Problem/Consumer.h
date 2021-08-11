//
// Created by abc on 6/6/2021.
//

#ifndef PRODUCER_CONSUMER_PROBLEM_CONSUMER_H
#define PRODUCER_CONSUMER_PROBLEM_CONSUMER_H
/*
 *  Consumer that consumes data from buffer while following mutual exclsuion.
 *  Consumer can not consume item if no item is present in buffer
 */
        void Consumer()
        {
                    while(true)
                    {
                            std::unique_lock<std::mutex> lck(ready_mutex);
                            _check.wait(lck, []() {return item_place>=1;});
                            int data=SharedMemory[item_place-1];
                            cout<<"Consumer Consumed "<<data<<" items left are "<<item_place-1<<endl;
                            item_place--;
                            lck.unlock();
                            _check.notify_one();
                            if(count==50 && item_place<=0)
                            {
                                //forcefully breaking the infinite loop
                                    cout<<"Problem stopped here. "<<endl;
                                    break;
                            }

                    }

        }
#endif //PRODUCER_CONSUMER_PROBLEM_CONSUMER_H
