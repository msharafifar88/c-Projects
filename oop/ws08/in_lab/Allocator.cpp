/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include "SavingsAccount.h"

namespace sict {
    
    const double interest = 0.05;
    
    
    iAccount* CreateAccount(const char* type, double balance) {
        iAccount *pointer_balance = nullptr;
        if (type[0] == 'S') pointer_balance = new SavingsAccount(balance, interest);
        return pointer_balance;
    }
}

