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
    Currency total = calculateTotal();
    return account.withdraw(total);
}

Currency ShoppingCart::calculateTotal() const
{
    Currency total(0.0 , 1.0);
    for (const auto& item : items){
        total = total + item.getPrice();
    }
    return total;
}