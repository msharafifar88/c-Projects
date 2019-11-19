/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include <iostream>
#include "ChequingAccount.h"

using namespace std;
namespace sict{
    
    
    
    ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) : Account ( balance)
    {
        if(balance> 0)
            transaction_fee = transFee ;
        else
            transaction_fee = 0.0;
        
        if(monthlyFee>0)
            month_end_fee = monthlyFee ;
        else
            month_end_fee =0.0;
        
    }
    
    bool ChequingAccount::credit(double amount) {
        Account::debit(transaction_fee);
        return Account::credit(amount );
        
    }
    
    bool ChequingAccount::debit(double amount) {
        
        return Account::debit(amount + transaction_fee  );
        
    }
    
    void ChequingAccount::monthEnd(){
        
        Account::debit(month_end_fee   );
    }
    void ChequingAccount::display(ostream& out) const {
        out << "Account type: Chequing" << endl;
        out.setf(ios::fixed);
        out.precision(2);
        out.setf(ios::fixed, ios::floatfield);
        out << "Balance: $" << balance() << endl;
        out << "Per Transaction Fee: " << transaction_fee << endl;
        out << "Monthly Fee: " << month_end_fee << endl;
        
    }
}

