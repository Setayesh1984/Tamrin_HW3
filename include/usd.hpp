#ifndef USD_HPP
#define USD_HPP

#include "currency.hpp"

class USD : public Currency 
{
 //ERS BARI
public:

 // Constructor
    USD(double val = 0.0); 
    void print() const override;  
};

#endif