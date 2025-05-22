#include "seasoning.hpp"
#include <iostream>

// Constructor
Seasoning::Seasoning(std::string name, const Currency& price, double quantity, std::string flavor , Unit g)
    : Item(name, price, quantity , g), flavor(flavor) {}

// Destructor
Seasoning::~Seasoning() {}

void Seasoning::addUnit() {
    stock += 1;
    std::cout << "one unit added to " << name << std::endl;
    std::cout << "recent stock : " << stock << std::endl;
}

void Seasoning::itemInfo() const {
    std::cout << "Name: " << name << "\nPrice: ";
    price.print(); 
    std::cout << "Quantity: " << quantity << "\nFlavor: " << flavor << std::endl;
    std::cout << "Stock: " << stock << "\n";
}