#ifndef SNACK_H
#define SNACK_H

#include "item.hpp"
#include <iostream>
#include <string>

class Snack : public Item
{
private:
    int calories;

public:
Snack(std::string name , const Currency& price , double quantity , int calories , Unit Package);

    ~Snack();

    void addUnit() override;
    void itemInfo() const override;

};

#endif