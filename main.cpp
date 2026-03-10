#include <iostream>
#include <limits>
#include <iomanip>
#include "include/MenuManager.h"
#include "include/CardManager.h"
#include "include/Drink.h"
#include "include/Food.h"
using namespace std;

int main() {
    MenuManager m;
    CardManager pos(20);
    vector<Order> dailyHistory;
    m.loadFromFile();
    int choice = 0;
    while (choice != 5) {
        cout << "=====Menu Manager Choice====="
             << "\n1. Menu Manager"
             << "\n2. POS Manager"
             << "\n5. Exit";
        cout << "\nChoice: ";cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 1) {
            int subChoice1 = 0;
            while (subChoice1 != 5) {
                cout << "=====Menu Manager====="
                << "\n1. Add Item"
                << "\n2. Edit Item"
                << "\n3. Delete Item"
                << "\n4. Print Menu"
                << "\n5. Exit";
                cout << "\nChoice: ";cin >> subChoice1;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (subChoice1 == 1) {
                    int chooseType = 0;
                    string name;
                    double price;
                    cout << "1. Add Drink"
                         << "\n2. Add Food";
                    cout << "\nChoice: ";cin >> chooseType;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter item name: "; getline(cin, name);
                    cout << "Enter price: "; cin >> price;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (chooseType == 1) {
                        m.addItem(new Drink(name, price));
                    } else if (chooseType == 2) {
                        m.addItem(new Food(name, price));
                    }
                    m.saveToFile();
                    cout << "Item added!" << endl;
                }
                else if (choice == 2) {
                    string name;
                    cout << "Enter item name to edit: "; getline(cin, name);
                    m.editItem(name);
                    m.saveToFile();
                }
                else if (choice == 3) {
                    string name;
                    cout << "Enter item name to delete: "; getline(cin, name);
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
        }
        else if (choice == 2) {
            int subChoice2 = 0;
            while (subChoice2 != 7) {
                cout << "=====POS Manager====="
                << "1. New Order"
                << "\n2. Edit Order"
                << "\n3. Delete Order"
                << "\n4. Order Card currently in used"
                << "\n5. Payment"
                << "\n6. EOD Report"
                << "\n7. Exit";
                cout << "\nChoice: ";cin >> subChoice2;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (subChoice2 == 1) {
                    OrderCard* card = pos.getNewCard();
                    if (card) {
                        string n; double p; int q;
                        cout << "Item: "; getline(cin, n);
                        cout << "Price: "; cin >> p;
                        cout << "Quantity: "; cin >> q;
                        card->assignOrder(n, p ,q);
                    } else cout << "Out of card!" << endl;
                }
                else if (subChoice2 == 2) {
                    int id;
                    cout << "Card ID to edit order: "; cin >> id;
                    OrderCard* card = pos.findActiveCard(id);
                    if (card) {
                        int editChoice;
                        cout << "1. Edit order"
                             << "\n2. Add new item to order"
                             << "\n3. Choice: ";cin >> editChoice;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if (editChoice == 1) {
                            auto& list = card->getOrderList();
                            for (size_t i = 0; i < list.size(); ++i) {
                                cout << i + 1 << ". " << list[i].itemName << " (SL: " << list[i].quantity << ")\n";
                            }
                            int itemIdx;
                            cout << "Index of item: "; cin >> itemIdx;
                            cout << "New quantity: "; cin >> list[itemIdx - 1].quantity;
                        }
                        else if (editChoice == 2) {
                            string name;
                            cout << "Item name: "; getline(cin, name);
                            Item* item = m.findItemByName(name);
                            if (item) {
                                int q; cout << "Quantity: "; cin >> q;
                                card->addItem(item->getName(), item->getPrice(), q);
                            } else cout << "Item not found!\n";
                        }
                    } else cout << "Card not in use!\n";
                }
                else if (subChoice2 == 3) {}
                else if (subChoice2 == 4) {}
                else if (subChoice2 == 5) {}
                else if (subChoice2 == 6) {}
                else if (subChoice2 == 7) {
                    cout << "Exiting..." << endl;
                }
            }
        }
    }
    return 0;
}