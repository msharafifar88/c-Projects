// Assembly Line Project
// CustomerOrder.h
// Mohammad Sharafifar
// 2019/07/11

#ifndef _345_CUSTOMER_ORDER_H_
#define _345_CUSTOMER_ORDER_H_
#include <iostream>
#include <string>
#include <vector>
#include "ItemSet.h"
using namespace std;

namespace sict {

	class CustomerOrder {
		std::string name_of_customer;
		std::string name_of_product;
		int countItem = 0;
        
        //struct that stores information about the item
        //
		struct ItemInfo
		{
			std::string item_name= "";
			int item_serial_number = 0;
			bool item_status = false;
		} ;

		ItemInfo* ptrItemInfo = nullptr;

	public:
		CustomerOrder();								// Default Constructor
		CustomerOrder(std::string);						// One-argument Constructor
		~CustomerOrder();								// Destructor
        
        //modifier that receives a reference to an ItemSet object
        //
		void fillItem(ItemSet& item, std::ostream& os);
        
        //query that searches the list of items requested
        //
		bool isFilled() const;
        
        //query that receives the name of an item
        //
		bool isItemFilled(const std::string& item) const;
        
		std::string getNameProduct() const;
        
        //query that receives a reference to an std::ostream object os
        //
		void display(std::ostream& os, bool showDetail = false) const;
        
		CustomerOrder(CustomerOrder &&) noexcept;       //Move constructor
        
		CustomerOrder & operator=(CustomerOrder &&) noexcept;
        
		CustomerOrder(const CustomerOrder &) = delete;
        
		CustomerOrder & operator=(const CustomerOrder &) = delete;
	};
}
#endif
