#ifndef DRINKS_H
#define DRINKS_H

#include "item.hpp"
#include "currency.hpp"
#include <iostream>
#include <string>


class Drinks : public Item {
private:
    bool isCold;

public:
    Drinks(std::string name, const Currency& price, double quantity, bool isCold , Unit bottle);
    ~Drinks();

    void addUnit() override;
    void itemInfo() const override;
};

#endif