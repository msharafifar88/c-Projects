// Assembly Line Project
// CustomerOrder.cpp
// Mohammad Sharafifar - 148218175
// 2019/July/20
#include <iomanip>
#include <iostream>
#include "Utilities.h"
#include "CustomerOrder.h"
using namespace std;
static size_t width = 0;
namespace sict {

	//  Default Constructor
	// sets the object to a safe empty state
	CustomerOrder::CustomerOrder() {
		dm_cust_name = "";
		dm_prod_assembled = "";
		countItem = 0;
		ptrItemInfo = nullptr;
	}

	//	One-argument Constructor
	// extracts no less than 3 tokens from the string received
	// Input: a string that was read from file. The content is: Customer name, Product name, Item1, Item2, ...
	// Output: -
	CustomerOrder::CustomerOrder(std::string str) {
		size_t pos = 0u, auxpos = 0u;
//		string auxstr = " ";

		try {
			Utilities util;
//			auxstr = str;

			dm_cust_name = util.extractToken(str, pos); 
			if (width < dm_cust_name.size()) {
				width = dm_cust_name.size();
			}

			dm_prod_assembled = util.extractToken(str, pos);

			auxpos = pos;
//			if (auxpos == 9999) {
			if (str.size() < pos) {
				throw "Error - No item was requested in the Order";
			}
			
			while (pos < str.size() ) {
//				cout << str.size() << " ";
				std::string dummy = util.extractToken(str, pos);
				countItem++;
			}

//			str = auxstr;
			ptrItemInfo = new ItemInfo[countItem];
			pos = auxpos;

			for (int i = 0; i < countItem; i++) {
				ptrItemInfo[i].it_name = util.extractToken(str, pos);
				ptrItemInfo[i].it_filled_status = false;
				ptrItemInfo[i].it_serial_number = 0;
			}
		}
		catch (std::string msg) {
			cout << msg;
			exit(2);
		}
	}

	//  Destructor
	CustomerOrder::~CustomerOrder() {
			delete[] ptrItemInfo;
	}

	// This function checks each item requested, fills it if the requested item is available and the request has not been filled,
	// reports the filling
	// Input: Item requested and ostream
	// Output: -
	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		for (int i = 0; i < countItem; i++) {
			if (ptrItemInfo[i].it_name == item.getName()) {
				if (ptrItemInfo[i].it_filled_status == false) {
					if (item.getQuantity() > 0) {
//						item.operator--();
						ptrItemInfo[i].it_serial_number = item.getSerialNumber();
						ptrItemInfo[i].it_filled_status = true;
						item.operator--();
						os << " Filled " << getNameProduct() << "[" << ptrItemInfo[i].it_name << "][" << ptrItemInfo[i].it_serial_number << "]" << endl;
					}
					else {
						os << " Unable to fill " << getNameProduct() << "[" << ptrItemInfo[i].it_name << "][" << ptrItemInfo[i].it_serial_number << "]" << " out of stock" << endl;
					}
				}
				else {
					os << " Unable to fill " << getNameProduct() << "[" << ptrItemInfo[i].it_name << "][" << ptrItemInfo[i].it_serial_number << "]" << " already filled" << endl;
				}
			}
		}
	}

	// search the list of items requested and returns true if all have been filled; false otherwise
	// Input: -
	// Output: true / false
	bool CustomerOrder::isFilled() const {
		bool ret = true;

		for (int i = 0; i < countItem; i++) {
			if (ptrItemInfo[i].it_filled_status == false) {
				ret = false;
			}
		}
		
		return ret;
	}

	// search the item request list for the item received and returns 
	// - true if all requests for that item have been filled
	// - false, otherwise.
	// If the item is not in the request list, this function returns true.
	// Input: Name Item
	// Output: true / false
	bool CustomerOrder::isItemFilled(const std::string& item) const {
		bool ret = true;

		for (int i = 0; i < countItem; i++) {
			if (ptrItemInfo[i].it_name == item) {
				if (ptrItemInfo[i].it_filled_status == false) {
					ret = false;
				}
			}
		}
		return ret;
	}

	// return the name of the customer and their product in the following format : CUSTOMER[PRODUCT]
	// Input: -
	// Output: CUSTOMER[PRODUCT]
	std::string CustomerOrder::getNameProduct() const {
		std::string ret = dm_cust_name + " [" + dm_prod_assembled + "]";
		return ret;
	}

	// Display information
	// Input: ostream, boolean parameter, if true: display details.
	// Output: -
	void CustomerOrder::display(std::ostream& os, bool showDetail) const {
		os << left << setw(width + 1) << dm_cust_name << +"[" + dm_prod_assembled + "]" << endl;
		if (!showDetail) {
			for (int i = 0; i < countItem; i++) {
				os << setw(width + 1) << " " << ptrItemInfo[i].it_name << endl;
			}
		}
		else {
			for (int i = 0; i < countItem; i++) {
				os << setw(width + 1) << " " << "[" << ptrItemInfo[i].it_serial_number << "] " << ptrItemInfo[i].it_name << " - " << (ptrItemInfo[i].it_filled_status == 1 ? "FILLED" : "MISSING") << endl;
			}
		}
	}

// move constructor
//
	CustomerOrder::CustomerOrder(CustomerOrder && src) noexcept {
		*this = std::move(src);

}
// move assignment operator
//
	CustomerOrder & CustomerOrder::operator=(CustomerOrder && src) noexcept {
		if (this != &src) {
			delete[] ptrItemInfo;
			dm_cust_name = src.dm_cust_name;
			dm_prod_assembled = src.dm_prod_assembled;
			ptrItemInfo = src.ptrItemInfo;
			countItem = src.countItem;

			src.ptrItemInfo = nullptr;
			src.countItem = 0;
			src.dm_cust_name.clear();
			src.dm_prod_assembled.clear();
		}
		return *this;
}

};

