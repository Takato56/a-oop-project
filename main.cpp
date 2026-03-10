#include <iostream>
#include <limits>
#include "Drink.h"
#include "Item.h"
#include "MenuManager.h"
using namespace std;

int main() {
    MenuManager m;
    m.loadFromFile();
    int choice = 0;
    while (choice != 10) {
        cout << "Menu Manager Choice"
             << "\n1. Add Item"
             << "\n2. Edit Item"
             << "\n3. Delete Item"
             << "\n4. Print Menu"
             << "\n10. Exit";
        cout << "\nChoice: ";cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 1) {
            int subChoice;
            string name;
            double price;
            cout << "1. Add Drink."
                 << "\n2. Add Food";
            cout << "\nChoice: ";cin >> subChoice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter item name: ";
            getline(cin, name);
            cout << "Enter price: ";
            cin >> price;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (subChoice == 1) {
                m.addItem(new Drink(name, price));
            } else if (subChoice == 2) {
                m.addItem(new Food(name, price));
            }
            m.saveToFile();
            cout << "Item added!" << endl;
        }
        else if (choice == 2) {
            string name;
            cout << "Enter name to edit: ";
            getline(cin, name);
            m.editItem(name);
            m.saveToFile();
        }
        else if (choice == 3) {
            string name;
            cout << "Emter name to delete: "; cin >> name;
            m.deleteItem(name);
            m.saveToFile();
        }
        else if (choice == 4) {
            m.displayMenu();
        }
        else if (choice == 10) {
            cout << "Exiting..." << endl;
        }
    }
    return 0;
}