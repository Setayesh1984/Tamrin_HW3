#ifndef CURRENCY_HPP
#define CURRENCY_HPP

#include <iostream>

class Currency 
{


protected:
    // megdar pool bar asas arz
    double value; 
    // nesbat arz b dollar           
    double conversionRate; 
    
    

public:
    Currency(double val = 0.0, double rate = 1.0);
    
    virtual ~Currency() = default;  

    double getValue() const;
    double getConversionRate() const;

    void setValue(double val);
    void setConversionRate(double rate);

    // Operator overloads anche lazeme
    Currency operator+(const Currency& other) const;
    Currency operator-(const Currency& other) const;
    Currency operator*(double factor) const;
    Currency operator/(double divisor) const;

//Currency c1(10, 1.0);    10 دلار
//Currency c2(20, 1.0);    20 دلار
//Currency sum = c1 + c2;  30 دلار

    bool operator==(const Currency& other) const;
    bool operator!=(const Currency& other) const;
    bool operator<(const Currency& other) const;
    bool operator>(const Currency& other) const;

    virtual void print() const;  // chape arz

    friend std::ostream& operator<<(std::ostream& os, const Currency& currency);

};

#endif