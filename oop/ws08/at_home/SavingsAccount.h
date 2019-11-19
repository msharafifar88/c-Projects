/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include <iostream>
#include "Account.h"
using namespace std;
namespace sict {
    class SavingsAccount : public Account {
    private:
        
        double interest_rate;
        
    public:
        
        SavingsAccount(double balance, double interestRate);
        
        void monthEnd();
        
   
        void display(ostream& out) const;
    };
}
#endif

