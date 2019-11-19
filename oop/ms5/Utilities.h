
/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#ifndef AMA_UTI_H
#define AMA_UTI_H
#include <iostream>
#include "Product.h"

namespace ama {
	double& operator+=(double& total, const iProduct& prod);
	std::ostream& operator<<(std::ostream& out, const iProduct& prod);
	std::istream& operator>>(std::istream& in, iProduct& prod);
	iProduct* createInstance(char tag);
}
#endif
