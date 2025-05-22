#include "item.hpp"
#include <iostream>
using namespace std;

Item::Item(string name , const Currency& price , double quantity, Unit unit)
    : name(name) , price(price) , quantity(quantity), unit(unit) , stock(0){}


string Item::getName() const{
    return name;
}

Currency Item::getPrice() const {
    return price;
}

Currency Item::getTotalPrice() const{
    return price * quantity;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::reduceStock(double amount){
    if (amount <= stock){
        stock -= amount;
    }
    else{
        cout << "mojodi kafi nist..." << endl;
    }
}


Item& Item::operator++() {
    stock++;
    return *this;
}


Item& Item::operator--() {
    if (stock > 0) stock--;
    return *this;
}


Item::~Item() {}