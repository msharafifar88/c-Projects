// Assembly Line Project
// ItemSet.cpp
// Mohammad Sharafifar
// Student ID : 143473171
// Email : msharafifar@myseneca.ca
// 2019/July/20
//

#include <iomanip>
#include <iostream>
#include "Utilities.h"
#include "ItemSet.h"
using namespace std;

namespace sict {
    
	//	One-argument Constructor
    // get the file and then extract the 4 tokens form the file
	// Input: string
	// Output: -
    //
    
ItemSet::ItemSet(const std::string str) {
		size_t pos = 0u;
		
		try {
			Utilities util;

			Item_Name  =  util.extractToken(str, pos);

			std::string a = util.extractToken(str, pos);
			std::string::size_type sz;
			int i_dec = std::stoi(a, &sz);
			Item_Serial_number = i_dec;

			a = util.extractToken(str, pos);
			i_dec = std::stoi(a, &sz);
			Number_of_Item = i_dec;
			
			Item_description = util.extractToken(str, pos);
		}
		catch (char* msg) {
			cout << msg;
			exit(1);
		}
	
	}

	//  returns the name of the item
    //
    
	const std::string& ItemSet::getName() const {
		return Item_Name ;
	}

	// returns the serial number of the item
	//
    
	const unsigned int ItemSet::getSerialNumber() const {
		return Item_Serial_number;
	}
	// returns the number of items in the set
    //
    
	const unsigned int ItemSet::getQuantity() const {
		return Number_of_Item;
	}

	// returns the description of item
    //
    
	const std::string& ItemSet::getDescr() const {
		return Item_description;
	}

	// reduces the number of items in stock by one ( Number_of_Item--; )
    // increases the serial number by one ( Item_Serial_number++; )
    //
    
	ItemSet& ItemSet::operator--() {
		Number_of_Item--;
		Item_Serial_number++;
		return *this;
	}
	
	// Display information
    //
    
	void ItemSet::display(std::ostream& os, bool full) const {
		os << left << setw(Utilities::getFieldWidth()) << getName();
		os << " [" << setw(5) << getSerialNumber();
		os << "] Quantity " << setw(3) << getQuantity();
		os << " Description: " << getDescr() << endl;
	}
	};
