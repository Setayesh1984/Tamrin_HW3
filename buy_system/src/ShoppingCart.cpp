#include "ShoppingCart.h"

#include <iostream>

void ShoppingCart::addItem(const Item& item)
{
    items.push_back(item);
}

void ShoppingCart::printItems() const
{
    if (items.empty()){
        std::cout << "Cart is empty..." << std::endl;
        return; 
    }

    for (const outo& item : items) {
        item.print();
    }
}

bool ShoppingCart::checkout(BankAccount& account)
{
    
}