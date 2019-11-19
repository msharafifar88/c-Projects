// Assembly Line Project
// ItemSet.cpp
// Remo De Micheli - rde-micheli@myseneca.ca - 148218175
// 2019/03/03
#include <iomanip>
#include <iostream>
#include "Utilities.h"
#include "ItemSet.h"
using namespace std;

namespace sict {
	//	One-argument Constructor
	// Receive a string read from a file and extract 4 tokens
	// Input: string
	// Output: -
ItemSet::ItemSet(const std::string str) {
		size_t pos = 0u;
		
		try {
			Utilities util;

			dm_name =  util.extractToken(str, pos);

			std::string a = util.extractToken(str, pos);
			std::string::size_type sz;
			int i_dec = std::stoi(a, &sz);
			dm_serial_number = i_dec;

			a = util.extractToken(str, pos);
			i_dec = std::stoi(a, &sz);
			dm_no_item = i_dec;
			
			dm_description = util.extractToken(str, pos);
		}
		catch (char* msg) {
			cout << msg;
			exit(1);
		}
	
	}

	//  returns a reference to the name of the item
	// Input: -
	// Output: name
	const std::string& ItemSet::getName() const {
		return dm_name;	
	}

	// returns the serial number of the item
	// Input: -
	// Output: serial number
	const unsigned int ItemSet::getSerialNumber() const {
		return dm_serial_number;
	}
	// returns the remaining number of items in the set
	// Input: -
	// Output: Number of Items
	const unsigned int ItemSet::getQuantity() const {
		return dm_no_item;
	}

	// returns the description of item
	// Input: -
	// Output: description
	const std::string& ItemSet::getDescr() const {
		return dm_description;
	}

	// reduces the number of items in stock by one and increases the serial number by one
	// Input: -
	// Output: reference to the current object
	ItemSet& ItemSet::operator--() {
		dm_no_item--;
		dm_serial_number++;
		return *this;
	}
	
	// Display information
	void ItemSet::display(std::ostream& os, bool full) const {
		os << left << setw(Utilities::getFieldWidth()) << getName();
		os << " [" << setw(5) << getSerialNumber(); // << setfill('0');
		os << "] Quantity " << setw(3) << getQuantity();
		os << " Description: " << getDescr() << endl;
	}
	};
