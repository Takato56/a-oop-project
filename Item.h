//
// Created by ntt12 on 3/9/2026.
//

#ifndef OOP_PROJECT_ITEM_H
#define OOP_PROJECT_ITEM_H
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
    string name, id;
    double price;
public:
    Item(string n, double p);
    void setId(const string& i);
    const string& getName() const;
    double getPrice() const;
    string getId() const;
    void setName(const string& n);
    void setPrice(double p);
    virtual void edit();
    virtual void display() const;
    virtual ~Item() {};
};


#endif //OOP_PROJECT_ITEM_H