//
// Created by ntt12 on 3/9/2026.
//

#include "Drink.h"
#include <iostream>

Drink::Drink(const string& n, double p) :
    Item(n, p) {}
void Drink::display() const {
    cout << "Drink: ";
    Item::display();
}
double Drink::calculatedPrice() const {
    if (size == "S")
        return price*0.8;
    else if (size == "M")
        return price;
    else if (size == "L")
        return price*1.1;
}