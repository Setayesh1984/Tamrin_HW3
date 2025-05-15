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