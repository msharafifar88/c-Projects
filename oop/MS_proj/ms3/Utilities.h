/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#pragma once
#ifndef NAMESPACE_ERROSTATE_H 
#define NAMESPACE_ERRORSATE_H 
#include <iostream>
#include "Product.h"
using namespace std;
namespace ama
{
    std::ostream& operator<<(std::ostream& out, const Product& prod);
    
    
    std::istream& operator>>(std::istream& in, Product& prod);
    
    
    double operator+=(double& total, const Product& prod);
}
#endif
