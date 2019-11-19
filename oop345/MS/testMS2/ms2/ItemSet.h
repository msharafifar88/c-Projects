// Assembly Line Project
// ItemSet.h


#ifndef _345_ITEM_SET_H_
#define _345_ITEM_SET_H_
#include <iostream>
#include <string>
using namespace std;

namespace sict {

	class ItemSet {
		std::string dm_name;
		unsigned int dm_serial_number;
		unsigned int dm_no_item;
		std::string dm_description;

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