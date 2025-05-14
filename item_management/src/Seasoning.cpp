#include "Seasoning.h"

Seasoning::Seasoning(std::string name , double price , double quantity , std::string flavor) : Item(name , price , quantity) , flavor(flavor){}
Seasoning::~Seasoning(){}

