#ifndef EUR_HPP
#define EUR_HPP

#include "currency.hpp"

class EUR : public Currency 
{

// Constructor
public:
    EUR(double val = 0.0);  
    void print() const override; 
};

#endif