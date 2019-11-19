/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {
    
    const double interest = 0.05;
    const double transaction_fee = 0.50;
    const double monthly_fee = 2.00;
    
    
    
    iAccount* CreateAccount(const char* type, double balance) {
        iAccount *pointer_balance = nullptr;
        if (type[0] == 'S')
        {pointer_balance = new SavingsAccount(balance, interest);
            }
        else if (type[0] == 'C')
        {pointer_balance = new ChequingAccount(balance, transaction_fee, monthly_fee);}
        
        return pointer_balance;
    }
    
    
}

