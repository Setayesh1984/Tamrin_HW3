#include "usd.hpp"
#include <iostream>

USD::USD(double val) : Currency(val, 1.0) {}

void USD::print() const 
{
    std::cout << "USD: " << value << std::endl;
}