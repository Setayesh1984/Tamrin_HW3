#ifndef SNACK_H
#define SNACK_H

#include "Item.h"
#include <iostream>
#include <string>

class Snack : public Item
{
private:
    int calories;

public:
    Snack(std::string name , double price , double quantity , int calories);
    ~Snack();

    void addUnit() override;
};

#endif