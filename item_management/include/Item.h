#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
protected:
    std::string name;
    double price;
    double quantity;
    int stock;

public:
    Item(std::string name , double price , double quantity , int stock);
    virtual ~Item();

    virtual void addUnit() = 0;
    virtual void itemInfo() const = 0;

    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void reduceStock(double);
};

#endif