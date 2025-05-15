#include "Snack.h"

Snack::Snack(std::string name , double price , double quantity , int calories) : Item(name , price , quantity) , calories(calories){}
Snack::~Snack(){}

void Snack::addUnit() 
{
    stock += 1;
    std::cout << "one snack added : " << name << std::endl;
    std::cout << "recent stock : " << stock << std::endl;
}