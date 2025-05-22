#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "currency.hpp"

enum class Unit{Kg, g, Package , bottle};

inline std::string unitToString(Unit u)
{
switch (u)
{
case  Unit::Kg : return "Kg";
case  Unit::g : return "g";
case  Unit::Package : return "Package";
case Unit::bottle : return "Bottle";
default : return "namotabar";
}
}
class Item
{
protected:
    std::string name;
    Currency price;
    double quantity;
    int stock;
    Unit unit;

public: 

    Item(std::string name , const Currency& price , double quantity, Unit unit);
    virtual ~Item();


    virtual void addUnit() = 0;
    virtual void itemInfo() const = 0;
    virtual Currency getTotalPrice() const;

    std::string getName() const;
    Currency getPrice() const;
    
    int getQuantity() const;
    void reduceStock(double);

    Item& operator++();
    Item& operator--();

};

#endif