#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include "currency.hpp"

class BankAccount 
{
    private:
    Currency balance;                       //mojodi
    double transferLimit;                   //max meghdari k mtnim bardarim



    public:
    BankAccount(double limit = 1000.0);     //pishfarz max enteghal
 
    void deposit(const Currency& amount);   //add money
    bool withdraw(const Currency& amount);  //kasr money(bool)
};

#endif
