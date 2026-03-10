//
// Created by ntt12 on 3/10/2026.
//

#ifndef A_OOP_PROJECT_CARDMANAGER_H
#define A_OOP_PROJECT_CARDMANAGER_H
#include <stack>
#include <vector>
#include "OrderCard.h"
using namespace std;

class CardManager {
private:
    stack<int> unusedCards;
    vector<OrderCard*> activeCards;
public:
    CardManager(int totalCards);
    ~CardManager();
    OrderCard* getNewCard();
    OrderCard* findActiveCard(int id);
    void returnCard(int id, vector<Order>& history);
    void displayActiveCards() const;
    bool hasActiveCards() const;
};


#endif //A_OOP_PROJECT_CARDMANAGER_H