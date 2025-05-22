#include "irr.hpp"
#include <iostream>

IRR::IRR(double val) : Currency(val, 0.00002) {}//arz nesbat b rial

void IRR::print() const 
{
    std::cout << "IRR: " << value << " Rials" << std::endl;
}