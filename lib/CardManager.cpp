//
// Created by ntt12 on 3/10/2026.
//

#include "../include/CardManager.h"
#include "../include/SaveOrder.h"
#include <iostream>
using namespace std;

CardManager::CardManager(int totalCards) {
    for (int i = 1; i <= totalCards; ++i) {
        unusedCards.push(i);
    }
}

CardManager::~CardManager() {
    for (auto card : activeCards) delete card;
}

OrderCard* CardManager::getNewCard() {
    if (unusedCards.empty()) return nullptr;
    int id = unusedCards.top();
    unusedCards.pop();
    OrderCard* newCard = new OrderCard(id);
    activeCards.push_back(newCard);
    return newCard;
}

OrderCard *CardManager::findActiveCard(int id) {
    for (auto card : activeCards) {
        if (card->getCardNumber() == id) return card;
    }
    return nullptr;
}

void CardManager::returnCard(int id, vector<Order>& history) {
    for (auto it = activeCards.begin(); it != activeCards.end(); ++it) {
        if ((*it)->getCardNumber() == id) {
            vector<Order> items = (*it)->releaseCard();
            for (const auto& item : items) {
                history.push_back(item);
                SaveOrder::saveOrder(item);
            }
            unusedCards.push(id);
            delete *it;
            activeCards.erase(it);
            return;
        }
    }
    cout << "Not found card #" << id << endl;
}

void CardManager::displayActiveCards() const {
    if (activeCards.empty()) {
        cout << "No active card found." << endl;
        return;
    }
    for (const auto& card : activeCards)
        card->display();
}
