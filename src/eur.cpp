#include "eur.hpp"
#include <iostream>

EUR::EUR(double val) : Currency(val, 1.2) {} //arz eur nesbat be dollar

void EUR::print() const 
{
    std::cout << "EUR:" << value << std::endl;
}