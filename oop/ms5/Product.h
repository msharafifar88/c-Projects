/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#pragma once
#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include <iostream>
#include "ErrorState.h"
#include "iProduct.h"

namespace ama {

	class Product : public iProduct {
		const char  pro_type;
		char pro_SKU[max_length_sku + 1];
		char pro_unit[max_length_unit + 1];
		char* pro_name;
		int available_quan;
		int needed_quan;
		double proPrice;
		bool taxable;
		ErrorState error_pro;

	protected:
		void message(const char* pText);
		bool isClear() const;

	public:
		Product(const char = 'N');
		Product(const char*, const char*, const char*, double = 0, int = 0, int = 0, bool = true);

		Product(const Product&);
		~Product();
		Product& operator=(const Product&);
		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		bool operator>(const char* sku) const;
		bool operator> (const iProduct&) const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		double total_cost() const;
		bool isEmpty() const;
		const char* name() const;
		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;

	};


}
#endif 


