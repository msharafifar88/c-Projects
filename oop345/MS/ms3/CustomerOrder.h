// Assembly Line Project
// CustomerOrder.h
// Mohammad Sharafifar
// Student ID : 143473171
// Email : msharafifar@myseneca.ca
// 2019/July/20
//
#ifndef _345_CUSTOMER_ORDER_H_
#define _345_CUSTOMER_ORDER_H_
#include <iostream>
#include <string>
#include <vector>
#include "ItemSet.h"

using namespace std;

namespace sict {

	class CustomerOrder {
		std::string M_CustomerName = "";
		std::string M_Product_Assembled = "";
		int Item_number = 0;

		struct ItemInfo
		{
			std::string Item_Name;
			int Item_SNumber;
			bool Item_Status;
		} info;

		ItemInfo* ptrItemInfo = nullptr;

	public:
		CustomerOrder();								// Default Constructor
		CustomerOrder(std::string);						// One-argument Constructor
		~CustomerOrder();								// Destructor
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;
		CustomerOrder(CustomerOrder &&) noexcept;
		CustomerOrder & operator=(CustomerOrder &&) noexcept;
//		CustomerOrder(const CustomerOrder &) = delete;
		CustomerOrder(const CustomerOrder &) { throw "***   ERROR   ***   Copy not allowe	d"; };

		CustomerOrder & operator=(const CustomerOrder &) = delete;
	};
}
#endif
