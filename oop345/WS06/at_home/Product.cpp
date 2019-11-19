// its a product class that get a product and the price
// << overloader and taxableproduct
// Product.cpp
// Mohammad Sharafifar
// 5/july/2019

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "Product.h" 

extern int FW;


namespace sict{


	// default constructor
    //
	Product::Product() {

		num_product = 0;
		Price_product = 0.0;
	}
	// two argument constructor
    //
	Product::Product(int ProductNumber, double ProductPrice) {
		num_product = ProductNumber;
		Price_product = ProductPrice;
	}
	// price() function
    //
	double Product::price() const {
		return Price_product;
	}
	// display function
    //
	void Product::display(std::ostream & os) const {
		os << std::setw(FW)
			<< num_product
			<< std::setw(FW)
			<< Price_product ;

	}
    // readRecord functiion
    //
	iProduct * readRecord(std::ifstream & file)

	{   iProduct* product = nullptr;

		std::string line = {};
		int ProductNumber = 0;
		double ProductPrice = 0;
		char tax = '\0' ;

		while (std::getline(file, line, '\n'))
        {
		
            //check the num of space in single line
            //
			size_t count = std::count(line.begin(), line.end(), ' ');
            
			std::stringstream stream(line);
            
      // i took help from my friend in this part
      // check here if the number of space is equal to 2 then we have product numbber price and taxotherwise we have only product number and price
			if (count == 2){

				stream >> ProductNumber >> ProductPrice >> tax;
				product = new TaxableProduct(ProductNumber, ProductPrice, tax);
				break;
			}
			else
			{
				stream >> ProductNumber >> ProductPrice;
				product = new Product(ProductNumber, ProductPrice);
				break;
			}
         }

		return product;

	}

	// operator<< function
    //
	std::ostream & operator<<(std::ostream & os, const iProduct & p){   
		 p.display(os);
          return os;
}
    
	// three argument constructor
    //
   TaxableProduct::TaxableProduct(int ProductNumber, double ProductPrice, char status):

	   // calling two parameter constructor
       //
    Product(ProductNumber, ProductPrice){
        
        if(status == 'H')
        {tax_rate =0.13 ;}
            
        else  if( status == 'P' ) { tax_rate = 0.08;}
            
        }

   
    
   //price() function
   //
    double TaxableProduct::price() const{
		return Product::price() * (1 + tax_rate);
	}
    
	// display function
    //
	void TaxableProduct::display(std::ostream & os) const
	{   Product::display(os);
       if (tax_rate == 0.13)
			os << " HST";
		else
            os << " PST" ;
	}

}
