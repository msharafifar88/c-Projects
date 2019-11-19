// Assembly Line Project
// CustomerOrder.h
// Gurjot Saini
// 2019/07/11

#ifndef SICT_CUSTOMER_ORDER_H
#define SICT_CUSTOMER_ORDER_H

//header files
//
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include "ItemSet.h"

namespace sict
{

	//for managing and processing customer orders
	//
	class CustomerOrder {

		//class member
		//
		static size_t m_nameFW;

		//data members
		//
		std::string m_nameOfCustomer;
		std::string m_nameOfProduct;

		//struct that stores information about the item, such as its name of the item, its serial number, and its filled status
		//
		struct ItemInfo {
			std::string nameOfItem = "";
			unsigned int serialNumber = 0;
			bool filledStatus = false;
		};

		//vector to store struct ItemInfo objects
		std::vector<ItemInfo> m_items;

	public:

		//default constructor that sets the object to a safe empty state
		//
		CustomerOrder();

		//one-argument constructor that receives a reference to an unmodifiable string
		//
		CustomerOrder(const std::string& str);

		//move constructor
		//
		CustomerOrder(CustomerOrder&& customerOrder);

		//move assignment
		//
		CustomerOrder& operator=(CustomerOrder&& customerOrder);

		//Ensures that this object is not copyable
		//
		CustomerOrder(const CustomerOrder& customerOrder) = delete;

		//Ensures that this object is not copy assignable
		//
		CustomerOrder& operator=(const CustomerOrder& customerOrder) = delete;

		//modifier that receives a reference to an ItemSet object and an std::ostream object
		//
		void fillItem(ItemSet& item, std::ostream& os);

		//query that searches the list of items requested and returns true if all have been filled; false otherwise
		//
		bool isFilled() const;

		//query that receives the name of an item, search the item request list for that item
		//
		bool isItemFilled(const std::string& item) const;

		//query that returns the name of the customer and their product
		//
		std::string getNameProduct() const;

		//query that receives a reference to an std::ostream object os and a Boolean showDetail and inserts the data for the current object into stream os
		//
		void display(std::ostream& os, bool showDetail = false) const;

		//deallocates any memory that the object has allocated
		//
		~CustomerOrder();
	};
}

#endif