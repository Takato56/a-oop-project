//
// Created by ntt12 on 3/10/2026.
//

#include "../include/Order.h"

double Order::getTotalPrice() const {
    return price * quantity;
}