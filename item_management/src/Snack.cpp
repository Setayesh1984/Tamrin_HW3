#include "Snack.h"

Snack::Snack(std::string name , double price , double quantity , int calories) : Item(name , price , quantity) , calories(calories){}
Snack::~Snack(){}

