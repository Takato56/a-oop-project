//
// Created by ntt12 on 3/9/2026.
//

#ifndef OOP_PROJECT_MENU_H
#define OOP_PROJECT_MENU_H
#include <vector>
#include <iostream>
#include "Item.h"
#include "Drink.h"
#include "Food.h"
using namespace std;
class MenuManager{
private:
    vector<Item*> menu;
    int drinkCount = 0;
    int foodCount = 0;
public:
    void addItem(Item* item);
    void editItem(const string& name );
    void deleteItem(const string& name );
    string searchNameToId(const string& name);
    Item* findItemByName(const string& name);
    void displayMenu();
    void saveToFile();
    void loadFromFile();
    ~MenuManager() {
        for (Item*p : menu) {
            delete p;
        }
        menu.clear();
    }
};



#endif //OOP_PROJECT_MENU_H