// Assembly Line Project
// CustomerOrder.cpp
// Mohammad Sharafifar
// Student ID : 143473171
// Email : msharafifar@myseneca.ca
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
    //
    
	CustomerOrder::CustomerOrder() {
		M_CustomerName = "";
		M_Product_Assembled = "";
		Item_number = 0;
		ptrItemInfo = nullptr;
	}

	//	One-argument Constructor
	// extracts no less than 3 tokens from the string received
    //
	CustomerOrder::CustomerOrder(std::string str) {
		size_t pos = 0u, auxpos = 0u;


		try {
			Utilities util;


			M_CustomerName = util.extractToken(str, pos);
			if (width < M_CustomerName.size()) {
				width = M_CustomerName.size();
			}

			M_Product_Assembled = util.extractToken(str, pos);

			auxpos = pos;

			if (str.size() < pos) {
				throw "Error - No item was requested in the Order";
			}
			
			while (pos < str.size() ) {

				std::string dummy = util.extractToken(str, pos);
				Item_number++;
			}

			ptrItemInfo = new ItemInfo[Item_number];
			pos = auxpos;

			for (int i = 0; i < Item_number; i++) {
				ptrItemInfo[i].Item_Name = util.extractToken(str, pos);
				ptrItemInfo[i].Item_Status = false;
				ptrItemInfo[i].Item_SNumber = 0;
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

	// checks each item requested if the requested item is available and the request has not been filled,
    //
    
    
	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		for (int i = 0; i < Item_number; i++) {
			if (ptrItemInfo[i].Item_Name == item.getName()) {
				if (ptrItemInfo[i].Item_Status == false) {
					if (item.getQuantity() > 0) {
						ptrItemInfo[i].Item_SNumber = item.getSerialNumber();
						ptrItemInfo[i].Item_Status = true;
						item.operator--();
						os << " Filled " << getNameProduct() << "[" << ptrItemInfo[i].Item_Name << "][" << ptrItemInfo[i].Item_SNumber << "]" << endl;
					}
					else {
						os << " Unable to fill " << getNameProduct() << "[" << ptrItemInfo[i].Item_Name << "][" << ptrItemInfo[i].Item_SNumber << "]" << " out of stock" << endl;
					}
				}
				else {
					os << " Unable to fill " << getNameProduct() << "[" << ptrItemInfo[i].Item_Name << "][" << ptrItemInfo[i].Item_SNumber << "]" << " already filled" << endl;
				}
			}
		}
	}

    // search the list of items requested and returns true if all have been filled; false otherwise
    //
    
	bool CustomerOrder::isFilled() const {
		bool ret = true;

		for (int i = 0; i < Item_number; i++) {
			if (ptrItemInfo[i].Item_Status == false) {
				ret = false;
			}
		}
		
		return ret;
	}

	// search the item request list for the item received and returns 
	// - true if all requests for that item have been filled
	// - false, otherwise.
	// If the item is not in the request list, this function returns true.
    //
    
	bool CustomerOrder::isItemFilled(const std::string& item) const {
		bool ret = true;

		for (int i = 0; i < Item_number; i++) {
			if (ptrItemInfo[i].Item_Name == item) {
				if (ptrItemInfo[i].Item_Status == false) {
					ret = false;
				}
			}
		}
		return ret;
	}

	// return the name of the customer and their product in the following format : CUSTOMER[PRODUCT]
	//
    
	std::string CustomerOrder::getNameProduct() const {
		std::string ret = M_CustomerName + " [" + M_Product_Assembled + "]";
		return ret;
	}

	// Display information
	//
    
	void CustomerOrder::display(std::ostream& os, bool showDetail) const {
		os << left << setw(width + 1) << M_CustomerName << +"[" + M_Product_Assembled + "]" << endl;
		if (!showDetail) {
			for (int i = 0; i < Item_number; i++) {
				os << setw(width + 1) << " " << ptrItemInfo[i].Item_Name << endl;
			}
		}
		else {
			for (int i = 0; i < Item_number; i++) {
				os << setw(width + 1) << " " << "[" << ptrItemInfo[i].Item_SNumber << "] " << ptrItemInfo[i].Item_Name << " - " << (ptrItemInfo[i].Item_Status == 1 ? "FILLED" : "MISSING") << endl;
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
			M_CustomerName = src.M_CustomerName;
			M_Product_Assembled = src.M_Product_Assembled;
			ptrItemInfo = src.ptrItemInfo;
			Item_number = src.Item_number;

			src.ptrItemInfo = nullptr;
			src.Item_number = 0;
			src.M_CustomerName.clear();
			src.M_Product_Assembled.clear();
		}
		return *this;
}

};

