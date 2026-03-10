//
// Created by ntt12 on 3/10/2026.
//

#ifndef OOP_PROJECT_FOOD_H
#define OOP_PROJECT_FOOD_H
#include "../include/Item.h"

class Food : public Item {
protected:
    string id;
public:
    Food(string n, double p) : Item(n, p) {};
};


#endif //OOP_PROJECT_FOOD_H