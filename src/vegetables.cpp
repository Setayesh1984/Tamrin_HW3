#include "vegetables.hpp"
#include <iostream>

Vegetables::Vegetables(std::string name , const Currency& price , double quantity , std::string color , Unit Kg)
: Item(name , price , quantity , Kg) , color(color) {}

Vegetables::~Vegetables() {}

void Vegetables::addUnit()
{
    stock += 1;
    std::cout << "one vegetable added: " << name << ", " << "Stock: " << stock << "\n";
}

void Vegetables::itemInfo() const{
    std:: cout << "Vegetable: " << name << ", " << "Color: " << color << ", ";
    price.print();
    std::cout << "Quantity: " << quantity << " Kg \n";
    std::cout << "Stock: " << stock << "\n";
}