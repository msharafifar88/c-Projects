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
#include "iProduct.h"

namespace ama
{
	double& operator+=(double&, const iProduct&);
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	iProduct* createInstance(char tag);
}
#endif
