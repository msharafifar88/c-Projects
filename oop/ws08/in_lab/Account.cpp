/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/
#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {
    Account::Account(double balance) {
        if(balance>0)
            current_balance = balance;
        else
            current_balance = 0;
    }
    
    bool Account::credit(double amount) {
        if (amount > 0) {
            current_balance += amount;
            return true;
        } else {
            return false;
        }
    }
    
    bool Account::debit(double amount) {
        if (amount > 0) {
            current_balance -= amount;
            return true;
        } else {
            return false;
        }
    }
    
    double Account::balance() const {
        return current_balance;
    }
}

