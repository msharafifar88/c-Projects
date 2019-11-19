// Assembly Line Project
// ItemSet.h
// Mohammad Sharafifar
// Student ID : 143473171
// Email : msharafifar@myseneca.ca
// 2019/July/20
//

#ifndef _345_ITEM_SET_H_
#define _345_ITEM_SET_H_
#include <iostream>
#include <string>
using namespace std;

namespace sict {

	class ItemSet {
		std::string Item_Name ;
		unsigned int Item_Serial_number;
		unsigned int Number_of_Item;
		std::string Item_description;

	public:
		ItemSet(const std::string str);						// One-argument Constructor
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		const std::string& getDescr() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
	};
}
#endif
