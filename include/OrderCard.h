//
// Created by ntt12 on 3/10/2026.
//

#ifndef OOP_PROJECT_ORDERCARD_H
#define OOP_PROJECT_ORDERCARD_H
#include <vector>
using namespace std;
#include <string>
#include "Order.h"

class OrderCard {
protected:
    int cardNumber, quantity;
    string itemName;
    double price;
    bool isActive;
    Order* currentOrder;
    vector<Order> orderList;
public:
    OrderCard(int id);
    int getCardNumber() const;
    bool checkOccupied() const;
    double getTotalPrice() const;
    void assignOrder(string name, double p, int q);
    void display() const;
    void clearData();
    void addItem(string name, double p, int q);
    vector<Order>& getOrderList();
    vector<Order> releaseCard();
};


#endif //OOP_PROJECT_ORDERCARD_H