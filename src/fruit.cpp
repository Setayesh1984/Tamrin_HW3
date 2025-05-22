#include "fruit.hpp"

Fruit::Fruit(std::string name , const Currency& price , double quantity , std::string type, Unit Kg)
    : Item(name, price, quantity , Kg), type(type) {}

Fruit::~Fruit(){}

void Fruit::addUnit()
{
    stock += 1;
    std::cout << "one unit added to " << name << std::endl;
    std::cout << "recent stock : " << stock << std::endl; 
}

void Fruit::itemInfo() const {
    std::cout << "Fruit: " << name << ", " << "Type: " << type << ", ";
    price.print();
    std::cout << "Quantity: " << quantity << " Kg \n";
    std ::cout << "Stock: " << stock << "\n";
}