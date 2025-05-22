#ifndef SEASONING_H
#define SEASONING_H

#include "item.hpp"
#include <iostream>
#include <string>

class Seasoning : public Item
{
private:
    std::string flavor;

public:
Seasoning(std::string name , const Currency& price , double quantity , std::string flavor , Unit g);

    ~Seasoning();

    void addUnit() override;
    void itemInfo() const override;

};
#endif