#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(string name , double price , double quantity , int stock) : name(name) , price(price) , quantity(quantity){}
Item::~Item(){}

string Item::getName() const{
    return name;
}

double Item::getPrice() const{
    return price;
}

int Item::getQuantity() const {
    return quantity;
}
