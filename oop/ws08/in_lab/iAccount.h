
/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/
#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <iostream>
using namespace std;
namespace sict {
    
    class iAccount {
    public:
    
        virtual bool credit(double) = 0;
        
        virtual bool debit(double) = 0;
        
        virtual void monthEnd() = 0;
        
        virtual void display(ostream& out) const = 0;
        
        virtual ~iAccount() {};
    };
    
    iAccount* CreateAccount(const char* type, double balance);
}
#endif


