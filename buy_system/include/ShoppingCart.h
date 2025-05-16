#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include <iostream>
#include "Item.h"
#include "BankAccount.h"

class CartEntry
{
private:
    std::vector<Item> items;

public:
    void addItem(const Item& item);
    void printItems() const;
    bool checkout(BankAccount& account);
    Currency calculateTotal() const;
};

#endif