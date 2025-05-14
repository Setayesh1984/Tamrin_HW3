#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(string name , double price , double quantity) : name(name) , price(price) , quantity(quantity){}
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

void Item::reduceStock(double amount){
    if (amount <= stock){
        stock -= amount;
    }
    else{
        cout << "mojodi kafi nist..." << endl;
    }
}