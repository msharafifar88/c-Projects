/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include <iostream>
#include "Utilities.h"
using namespace std;

namespace ama
{
    double& operator+=(double& total, const iProduct& prod)
    {
        return total += prod.total_cost();
    }
    
    ostream& operator<<(ostream& out, const iProduct& prod)
    {
        return prod.write(out, write_human);
    }
    
    istream& operator>>(istream& in, iProduct& prod)
    {
        return prod.read(in, true);
    }
    
    iProduct* createInstance(char tag)
    {
        iProduct* i = nullptr;
        if (tag == 'N' || tag == 'n')
        {
            i = new Product;
        }
        return i;
    }
}

