cmake_minimum_required(VERSION 4.1)
project(a_oop_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(a_oop_project main.cpp
        lib/MenuManager.cpp
        lib/Drink.cpp
        lib/Food.cpp
        lib/Item.cpp
        lib/OrderCard.cpp
        lib/Order.cpp
        lib/SaveOrder.cpp
        lib/CardManager.cpp
        include/CardManager.h
        include/Drink.h
        include/Food.h
        include/Item.h
        include/MenuManager.h
        include/Order.h
        include/OrderCard.h
        include/SaveOrder.h
)
