#ifndef FRUIT_H
#define FRUIT_H

#include "Item.h"
#include <iostream>


class Fruit : public Item
{
private:
    std::string type;
public:
    Fruit(std::string name , double price , double quantity , std::string type);
    ~Fruit();

    void addUnit() override;
};
#endif