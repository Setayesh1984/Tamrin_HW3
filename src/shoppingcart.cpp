#include "shoppingcart.hpp"
#include <memory>
#include <iostream>

void CartEntry::addItem(std::shared_ptr<Item> item) {
    items.push_back(item);
}

void CartEntry::printItems() const
{
    if (items.empty()){
        std::cout << "Cart is empty..." << std::endl;
        return; 
    }

    for (const auto& item : items) {
        item->itemInfo(); 
    }
}

bool CartEntry::checkout(BankAccount& account)
{
    Currency total = calculateTotal();
    return account.withdraw(total);
}

Currency CartEntry::calculateTotal() const
{
    Currency total(0.0 , 1.0);
    for (const auto& item : items){
        total = total + item->getTotalPrice();
    }
    return total;
}

const std::vector<std::shared_ptr<Item>>& CartEntry::getItems() const {
    return items;
}