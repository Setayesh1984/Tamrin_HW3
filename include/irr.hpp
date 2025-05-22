#ifndef IRR_HPP
#define IRR_HPP
#include "currency.hpp"

class IRR : public Currency 
{
public:
    IRR(double val = 0.0); 
    void print() const override; 
};

#endif
