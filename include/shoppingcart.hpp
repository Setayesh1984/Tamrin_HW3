#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include <iostream>
#include "item.hpp"
#include "bankaccount.hpp"
#include <memory>


class CartEntry
{
private:
    std::vector<std::shared_ptr<Item>> items;

public:

    void addItem(std::shared_ptr<Item> item);  
    void printItems() const;
    bool checkout(BankAccount& account);
    Currency calculateTotal() const;
    const std::vector<std::shared_ptr<Item>>& getItems() const;

};

#endif