#include "bankaccount.hpp"
#include <iostream>

//constractor...mojodi:0...nerkh:1....pishfarz:1000
BankAccount::BankAccount(double limit) : balance(0.0, 1.0), transferLimit(limit) {}

//operator+ mojodi
void BankAccount::deposit(const Currency& amount) 
{
    Currency converted(amount.getValue() * amount.getConversionRate(), 1.0);
    balance = balance + converted;
}


//check bardasht money<saghf & hesab
bool BankAccount::withdraw(const Currency& amount) 
{
    Currency converted(amount.getValue() * amount.getConversionRate(), 1.0);
    if (converted.getValue() > transferLimit) 
    {
        std::cout << "Error: Amount more than transfer limit!pleas try again and less" << std::endl;
        return false;
    }

//bi moshkel=true,else false
    if (converted.getValue() > balance.getValue()) 
    {
        std::cout << "Error: mojodi kafi nist!" << std::endl;
        return false;
    }
    balance = balance - converted;
    return true;
}


Currency BankAccount::getBalance() const 
{
    return balance;
}


void BankAccount::printBalance() const 
{
    std::cout << "Current Balance: ";
    balance.print();
}
