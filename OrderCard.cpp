//
// Created by ntt12 on 3/10/2026.
//

#include "OrderCard.h"
#include <iostream>

OrderCard::OrderCard(int card, string name, double p, int q) :
    cardNumber(card), itemName(name), price(p), quantity(q), isAactive(true) {}

int OrderCard::getCardNumber() const {
    return cardNumber;
}

double OrderCard::getTotalPrice() const {
    return price * quantity;
}

void OrderCard::display() const {
    if (isAactive) {
        cout << "The #" << cardNumber << itemName
             << " | SL: " << quantity
             << " | Tong: " <<getTotalPrice() << " VND" << endl;
    }
}

void OrderCard::clearData() {
    cardNumber = -1;
    itemName = "";
    price = 0.0;
    quantity = 0;
    isAactive = false;
}
