/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include <iostream>
#include<iomanip>
#include"Utilities.h"
#include "Product.h"
using namespace std;

namespace ama
{
    std::ostream &operator<<(std::ostream &out, const Product &prod)
    {
        return prod.write(out, write_human );
    }
    std::istream & operator>>(std::istream & in, Product &prod)
    {
       return prod.read(in , true);
        
    }
    double operator+=(double &total, const Product &prod)
    {
        return  total += prod.total_cost();
    }
}

