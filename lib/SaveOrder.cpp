//
// Created by ntt12 on 3/10/2026.
//

#include "../SaveOrder.h"
#include <fstream>

#include "../include/Order.h"
using namespace std;

void SaveOrder::saveOrder(const Order& order) {
    ofstream outFile("daily_history.csv", ios::app);
    if (!outFile.is_open()) {
        outFile << order.cardNumber << ","
                << order.itemName << ","
                << order.price << ","
                << order.quantity << ","
                << order.price * order.quantity << endl;
        outFile.close();
    }
}
