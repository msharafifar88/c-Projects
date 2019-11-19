// its a base class of product
// iProduct.h
// Mohammad Sharafifar
// 5/july/2019
//


#ifndef IPRODUCT_H
#define IPRODUCT_H

#include <iostream>
#include <fstream>


namespace sict

{

	class iProduct

	{

	public:

		virtual double price() const = 0;

		virtual void display(std::ostream& os) const = 0;

	};

	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);

}



#endif 
