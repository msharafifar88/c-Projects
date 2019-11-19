// where we define a product class
// Product.h
// Mohammad Sharafifar
// 5/july/2019
//
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace sict{

	class Product : public iProduct

	{

		int num_product;
        
		double Price_product;

	public:

		Product();

	    Product(int num_p, double price_p);

		double price() const ;

		void display(std::ostream& os) const ;

	};

	class TaxableProduct :public Product
	{
		double tax_rate;
        
		enum class Tax { HST, PST };

	public:

		TaxableProduct(int, double, char);

		double price() const ;
        
		void display(std::ostream&) const ;
	};

	iProduct* readRecord(std::ifstream& file);
    
    std::ostream& operator<<(std::ostream& os, const iProduct& p);

}

#endif 
