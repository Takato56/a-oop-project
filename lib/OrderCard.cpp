//
// Created by ntt12 on 3/10/2026.
//

#include "../include/OrderCard.h"
#include <iostream>

OrderCard::OrderCard(int id) :
    cardNumber(id), currentOrder(nullptr), isActive(false) {}

int OrderCard::getCardNumber() const {
    return cardNumber;
}

bool OrderCard::checkOccupied() const {
    return isActive;
}

void OrderCard::assignOrder(string name, double p, int q) {
    currentOrder = new Order{name, p, q ,cardNumber};
    isActive = true;
}

vector<Order> OrderCard::releaseCard() {
    vector<Order> temp = orderList;
    clearData();
    return temp;
}

vector <Order>& OrderCard::getOrderList() {
    return orderList;
}

double OrderCard::getTotalPrice() const {
    return price * quantity;
}

void OrderCard::addItem(string name, double p, int q) {
    for (auto& item : orderList) {
        if (item.itemName == name) {
            item.quantity += q;
            return;
        }
    }
    orderList.push_back({name, p, q, cardNumber});
    isActive = true;
}

void OrderCard::display() const {
    if (isActive) {
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
    isActive = false;
}
