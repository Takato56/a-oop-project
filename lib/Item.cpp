//
// Created by ntt12 on 3/9/2026.
//

#include "../include/Item.h"

Item::Item(string n, double p) :
    name(n), price(p) {}
void Item::setId(const string& i) {
    id = i;
}
const string& Item::getName() const{
    return name;
}
double Item::getPrice() const {
    return price;
}
string Item::getId() const {
    return id;
}
void Item::setName(const string& n) {
    name = n;
}
void Item::setPrice(double p) {
    price = p;
}
void Item::edit() {
    cout << "Enter new name: "; getline(cin, name);
    cout << "Enter new price: "; cin >> price;
}
void Item::display() const {
    cout << name << " - " << price << endl;
}