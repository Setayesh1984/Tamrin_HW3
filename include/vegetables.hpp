#ifndef VEGETABLES_H
#define VEGETABLES_H

#include "item.hpp"
#include "currency.hpp"
#include <iostream>
#include <string>

class Vegetables : public Item {
private:
    std::string color;

public:
    Vegetables(std::string name, const Currency& price, double quantity, std::string color , Unit Kg);
    ~Vegetables();

    void addUnit() override;
    void itemInfo() const override;
};

#endif