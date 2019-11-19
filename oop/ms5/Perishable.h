/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#pragma once
#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H
#include "Product.h"
#include "Date.h"

#include <iostream>
namespace ama {
	class Perishable : public Product {
		Date expiry_date;

	public:
		Perishable(const char = 'p');
		std::ostream& write(std::ostream& out, int writeMode) const;
		std::istream& read(std::istream& in, bool interractive);
	};

}
#endif
