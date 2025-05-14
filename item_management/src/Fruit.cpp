#include "Fruit.h"

Fruit::Fruit(std::string name , double price , double quantity , std::string type) : Item(name , price , quantity) , type(type){}

Fruit::~Fruit(){}
