/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#ifndef ChequingAccount_h
#define ChequingAccount_h
#include "Account.h"

using namespace std;
namespace sict {
    
    class ChequingAccount : public Account {
        
        
    private:
        double transaction_fee;
        double month_end_fee;
    public:
        ChequingAccount(double balance, double transFee, double monthlyFee);
        bool credit(double amount);
        bool debit(double amount);
        void monthEnd();
        void display(ostream& out) const;
        
        
    };
    
}



#endif /* ChequingAccount_h */
