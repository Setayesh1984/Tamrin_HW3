#include "drinks.hpp"
#include <iostream>

Drinks::Drinks(std::string name, const Currency& price, double quantity, bool isCold , Unit bottle)
    : Item(name, price, quantity , bottle), isCold(isCold) {}

Drinks::~Drinks() {}

void Drinks::addUnit() {
    stock += 1;
    std::cout << "One drink added: " << name << ", Stock: " << stock << std::endl;
}

void Drinks::itemInfo() const {
    std::cout << "Drink: " << name << ", Type: " << (isCold ? "Cold" : "Hot") << ", ";
    price.print();
    std::cout << "Quantity: " << quantity << " bottle \n"; 
    std::cout << "Stock: " << stock << "\n";
}