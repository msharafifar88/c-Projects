/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#pragma once
#ifndef SICT_PRODUCT_H__
#define SICT_PRODUCT_H__
#include <iostream>
#include "ErrorState.h"
#include "iProduct.h"
using namespace std;
namespace ama
{
	/*const int max_length_label = 30;
	const int max_length_sku = 7;
	const int max_length_name = 75;
	const int max_length_unit = 10;
	const int write_condensed = 0;
	const int write_table = 1;
	const int write_human = 2;
	const double tax_rate = 0.13;
*/
	class Product : public iProduct
	{
	private:
        //add const here yeh okk and then
        const char type;
	    char pro_sku[max_length_sku + 1];
		char pro_unit[max_length_unit + 1];
        // error was here u used const for pointer
        char * productName;
		int qntity_on_hand;
		int qntity_need;
		double pro_price;
	    bool taxStatus;
		ErrorState pro_error;

	protected:
		void message(const char* pText);
		bool isClear() const;

	public:
		 Product(char  = 'N');
		 Product(const char* addrs, const char* pro_name, const char* unit, double price = 0.0, int quantity_h = 0, int quantity_n = 0, bool status = true);
		 Product(const Product& pro);
		 ~Product();
		 Product& operator=(const Product & pro);
		 int operator+=(int cnt);
		 bool operator==(const char* sku) const;
		 bool operator> (const char* sku) const;
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
