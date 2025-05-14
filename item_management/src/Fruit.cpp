#include "Fruit.h"

Fruit::Fruit(std::string name , double price , double quantity , std::string type) : Item(name , price , quantity) , type(type){}

Fruit::~Fruit(){}

void Fruit::addUnit()
{
    stock += 1;
    std::cout << "one unit added to " << name << std::endl;
    std::cout << "recent stock : " << stock << std::endl; 
}