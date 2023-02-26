cmake_minimum_required(VERSION 3.24)
project(Amazin2_0)

set(CMAKE_CXX_STANDARD 11)

add_executable(Amazin2_0 main.cpp Queue.h Order.h Queue.cpp ShippingEvent.cpp PrepareEvent.cpp ArrivalEvent.cpp Order.cpp Node.cpp Company.cpp WorkingHour.cpp EventQueue.h Event.cpp EventQueue.cpp Revenue.cpp Helper.cpp)
