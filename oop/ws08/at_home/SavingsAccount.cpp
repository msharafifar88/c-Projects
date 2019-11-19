/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/
#include <iostream>
#include "SavingsAccount.h"
using namespace std;
namespace sict {
    SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance) {
        if(interestRate>0)
            interest_rate = interestRate;
        else
            interest_rate = 0.0;
        
    }
    
    void SavingsAccount::monthEnd() {
        double interest = (balance() * interest_rate);
        credit(interest);
    }
    
    void SavingsAccount::display(ostream& out) const {
        out << "Account type: Savings" << endl;
        out.setf(ios::fixed);
        out.precision(2);
        out << "Balance: $" << balance() << endl;
        out << "Interest Rate (%): " << interest_rate * 100 << endl;
    }
    
}


