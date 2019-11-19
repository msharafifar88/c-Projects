// Assembly Line Project
// ItemSet.cpp
// 2019/July/09
//Mohammad Sharafifar
//Student ID: 143473171
//
#include <iomanip>
#include <iostream>
#include "Utilities.h"
#include "ItemSet.h"

using namespace std;

namespace sict {
//
//	One-argument Constructor
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

	const std::string& ItemSet::getName() const {
		return dm_name;	
	}

	const unsigned int ItemSet::getSerialNumber() const {
		return dm_serial_number;
	}
		
	const unsigned int ItemSet::getQuantity() const {
		return dm_no_item;
	}

	const std::string& ItemSet::getDescr() const {
		return dm_description;
	}


	ItemSet& ItemSet::operator--() {
		dm_no_item--;
		dm_serial_number++;
		return *this;
	}
		
	void ItemSet::display(std::ostream& os, bool full) const 
{
		os << left << setw(Utilities::getFieldWidth()) << getName();

		os << " [" << setw(5) << getSerialNumber(); // << setfill('0');

		os << "] Quantity " << setw(3) << getQuantity();

		os << " Description: " << getDescr() << endl;
	}
	};


