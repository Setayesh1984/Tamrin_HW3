#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include <iostream>
#include "Item.h"
#include "BankAccount.h"

struct CartEntry
{
    Item* item;
    int quantity;

    CartEntry(Item* i , int q) : item(i) , quantity(q) {}
};

#endif