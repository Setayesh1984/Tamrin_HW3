#include "Seasoning.h"

Seasoning::Seasoning(std::string name , double price , double quantity , std::string flavor) : Item(name , price , quantity) , flavor(flavor){}
Seasoning::~Seasoning(){}

void Seasoning::addUnit() 
{
    stock += 1;
    std::cout << "one unit added to " << name << std::endl;
    std::cout << "recent stock : " << stock << std::endl;
}