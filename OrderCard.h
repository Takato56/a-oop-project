//
// Created by ntt12 on 3/10/2026.
//

#ifndef OOP_PROJECT_ORDERCARD_H
#define OOP_PROJECT_ORDERCARD_H
using namespace std;
#include <string>

class OrderCard {
protected:
    int cardNumber, quantity;
    string itemName;
    double price;
    bool isAactive;
public:
    OrderCard(int card, string name, double p, int q);
    int getCardNumber() const;
    double getTotalPrice() const;
    void display() const;
    void clearData();
};


#endif //OOP_PROJECT_ORDERCARD_H