#ifndef SEASONING_h
#define SEASONING_H

#include "Item.h"
#include <iostream>
#include <string>

class Seasoning : public Item
{
private:
    std::string flavor;

public:
    Seasoning(std::string name , double price , double quantity , std::string flavor);
    ~Seasoning();

    void addUnit() override;
};
#endif