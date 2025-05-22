#ifndef FRUIT_H
#define FRUIT_H

#include "item.hpp"
#include <iostream>


class Fruit : public Item
{
private:
    std::string type;

public:
Fruit(std::string name , const Currency& price , double quantity , std::string type, Unit Kg);
    virtual ~Fruit();
    void addUnit() override;
    void itemInfo() const override;

};
#endif