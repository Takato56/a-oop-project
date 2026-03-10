//
// Created by ntt12 on 3/9/2026.
//

#ifndef OOP_PROJECT_DRINK_H
#define OOP_PROJECT_DRINK_H
#include "Item.h"
#include <string>
using namespace std;

class Drink : public Item{
protected:
    string size;
public:
    Drink(const string & name, double price);
    void display() const override;
    double calculatedPrice() const;

};


#endif //OOP_PROJECT_DRINK_H