//
// Created by ntt12 on 3/9/2026.
//

#include "MenuManager.h"
#include <string>
#include <iostream>
#include <fstream>

void MenuManager::addItem(Item* item) {
    if (dynamic_cast<Drink*>(item)) {
        drinkCount++;
        item->setId("D" + to_string(drinkCount));
    } else if (dynamic_cast<Food*>(item)) {
        foodCount++;
        item->setId("F" + to_string(foodCount));
    }
    menu.push_back(item);
}
void MenuManager::editItem(const string& name ) {
    for (Item* item : menu) {
        if (item->getName() == name) {
            cout << "Item founded! Editing..." << endl;
            item->edit();
            return;
        }
    }
    cout << "Item not found!" << endl;
}
void MenuManager::deleteItem(const string& name ) {
    for (auto item = menu.begin(); item != menu.end(); ++item) {
        if ((*item)->getName() == name) {
            delete *item;
            menu.erase(item);
            cout << "Item deleted!\n";
            return;
        }
    }
}
string MenuManager::searchNameToId(const string& name) {
    for (Item* item : menu) {
        if (item->getName() == name) {
            return item->getId();
        }
    }
    return "Not found!";
}
void MenuManager::displayMenu() {
    cout << "Menu" << endl;
    if (menu.empty()) {
        cout << "No menu available" << endl;
    }else {
        for (size_t i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". ";
            menu[i]->display();
        }
    }
}
void MenuManager::saveToFile() {
    ofstream file ("menu.txt");
    for (Item* item : menu) {
        file << item->getId() << " "
             << item->getName() << " "
             << item->getPrice() << " "  << endl;
    }
    file.close();
}
void MenuManager::loadFromFile() {
    ifstream file ("menu.txt");
    if (!file) return;
    string id, name;
    double price;
    while (file >> id >> name >> price) {
        Item* item;
        if (id[0] == 'D') {
            item = new Drink(name, price);
            drinkCount++;
        }
        else if (id[0] == 'F') {
            item = new Food(name, price);
            foodCount++;
        }
        item->setId(id);
        menu.push_back(item);
    }
    file.close();
}