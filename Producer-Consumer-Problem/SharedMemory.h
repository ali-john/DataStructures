//
// Created by abc on 6/6/2021.
//

#ifndef PRODUCER_CONSUMER_PROBLEM_SHAREDMEMORY_H
#define PRODUCER_CONSUMER_PROBLEM_SHAREDMEMORY_H

/*
 *  Creating a dynamic size array which is used as a shared
 *  memory buffer
 */
int max_size_of_buffer=15;
int *SharedMemory=new int[max_size_of_buffer];
#endif //PRODUCER_CONSUMER_PROBLEM_SHAREDMEMORY_H
