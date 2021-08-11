cmake_minimum_required(VERSION 3.17)
project(Producer_Consumer_Problem)

set(CMAKE_CXX_STANDARD 14)

add_executable(Producer_Consumer_Problem main.cpp SharedMemory.h Producer.h Consumer.h)