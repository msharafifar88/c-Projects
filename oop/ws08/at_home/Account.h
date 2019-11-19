/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"
using namespace std;
namespace sict {
    
    class Account : public iAccount {
    private:
        
        double current_balance;
   
    public:
        
        Account(double balance);
        
        
        bool credit(double amount);
        
       
        bool debit(double amount);
        
    protected:
        double balance() const;
    };
    
    
    iAccount* CreateAccount(const char* type, double balance);
}
#endif

