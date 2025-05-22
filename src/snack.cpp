#include "snack.hpp"

Snack::Snack(std::string name , const Currency& price , double quantity , int calories , Unit Package)
    : Item(name, price, quantity, Package), calories(calories) {}

Snack::~Snack(){}

void Snack::addUnit() 
{
    stock += 1;
    std::cout << "one snack added : " << name << std::endl;
    std::cout << "recent stock : " << stock << std::endl;
}

void Snack::itemInfo() const {
    std::cout << "Snack: " << getName() << ", " << "Calories: " << calories << ", ";
    price.print();
    std::cout << "Quntity: " << quantity << "package \n";
    std::cout << "Stock: " << stock << "\n";
}