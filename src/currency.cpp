#include <currency.hpp>

// Constructor
Currency::Currency(double val, double rate) : value(val), conversionRate(rate) {}


double Currency::getValue() const 
{
    return value;
}


double Currency::getConversionRate() const 
{
    return conversionRate;
}






void Currency::setValue(double val) 
{
    value = val;
}

void Currency::setConversionRate(double rate) 
{
    conversionRate = rate;
}




Currency Currency::operator+(const Currency& other) const 
{
    double newValue = this->value + other.value;
    return Currency(newValue, this->conversionRate);
}

Currency Currency::operator-(const Currency& other) const 
{
    double newValue = this->value - other.value;
    return Currency(newValue, this->conversionRate);
}

Currency Currency::operator*(double factor) const 
{
    return Currency(this->value * factor, this->conversionRate);
}

Currency Currency::operator/(double divisor) const 
{
    return Currency(this->value / divisor, this->conversionRate);
}

    



bool Currency::operator==(const Currency& other) const 
{
    return this->value == other.value;
}

bool Currency::operator!=(const Currency& other) const 
{
    return !(*this == other);
}

bool Currency::operator<(const Currency& other) const 
{
    return this->value < other.value;
}

bool Currency::operator>(const Currency& other) const 
{
    return this->value > other.value;
}





void Currency::print() const 
{
    std::cout << "Value: " << value << ", Conversion Rate: " << conversionRate << std::endl;
}
