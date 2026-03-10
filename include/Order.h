//
// Created by ntt12 on 3/10/2026.
//

#ifndef A_OOP_PROJECT_ORDER_H
#define A_OOP_PROJECT_ORDER_H
#include <iostream>
using namespace std;

struct Order {
    string itemName;
    double price;
    int quantity, cardNumber;

    double getTotalPrice() const;
};


#endif //A_OOP_PROJECT_ORDER_H