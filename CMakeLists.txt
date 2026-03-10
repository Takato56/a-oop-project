cmake_minimum_required(VERSION 4.1)
project(a_oop_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(a_oop_project main.cpp
        MenuManager.cpp
        Drink.cpp
        Food.cpp
        Item.cpp
        OrderCard.cpp
        Order.cpp
        Order.h
        SaveOrder.cpp
        SaveOrder.h
        CardManager.cpp
        CardManager.h
)
