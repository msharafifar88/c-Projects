// Assembly Line Project
// CustomerOrder.cpp
// Gurjot Saini
// 2019/07/11

//header files
//
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sict
{

	//initialize the name field width to 0
	//
	size_t CustomerOrder::m_nameFW = 0;
	
	//default constructor that sets the object to a safe empty state
	//
	CustomerOrder::CustomerOrder() : m_nameOfCustomer(""), m_nameOfProduct("") {}

	//one-argument constructor that receives a reference to an unmodifiable string
	//
	CustomerOrder::CustomerOrder(const std::string& str) {

		//Creates an "Utilities" object
		//
		Utilities util;

		//initializes the delimiter position, and sets the delimiter type
		//
		size_t delimiterPos = 0;
		util.setDelimiter('|');

		//extracts the token for name of customer
		//
		m_nameOfCustomer = util.extractToken(str, delimiterPos);

		//sets the name field width
		//
		if (m_nameFW < m_nameOfCustomer.length()) {
			m_nameFW = m_nameOfCustomer.length();
		}

		//extracts the token for name of product
		//
		m_nameOfProduct = util.extractToken(str, delimiterPos);

		//checks if there are more tokens to be extracted
		//
		if (delimiterPos != std::string::npos) {

			ItemInfo itemInfo;

			//extracts the tokens for name of items
			//
			while (delimiterPos != std::string::npos) {
				
				itemInfo.nameOfItem = util.extractToken(str, delimiterPos);
				m_items.push_back(itemInfo);
			}
		}
		else {
			//throws an exception if there were no items to be extracted
			//
			throw("Error! No items have been requested to be added!");
		}
	}

	//move constructor
	//
	CustomerOrder::CustomerOrder(CustomerOrder&& customerOrder) {
		*this = std::move(customerOrder);
	}

	//move assignment
	//
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& customerOrder) {
		
		//copies the name of customer from the argument object
		//
		m_nameOfCustomer = customerOrder.m_nameOfCustomer;

		//copies the name of product from the argument object
		//
		m_nameOfProduct = customerOrder.m_nameOfProduct;

		//copies all of the item information from the argument object
		//
		m_items = customerOrder.m_items;

		//assigns the name of customer data member of the argument object to a default value
		//
		customerOrder.m_nameOfCustomer = "";

		//assigns the name of product data member of the argument object to a default value
		//
		customerOrder.m_nameOfProduct = "";

		//removes all of the item information from the items data member of the argument object
		//
		while ( !(customerOrder.m_items.empty()) ) {
			customerOrder.m_items.pop_back();
		}

		//returns the current object
		//
		return *this;
	}

	//modifier that receives a reference to an ItemSet object and an std::ostream object
	//
	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {

		//indicates if the specific item is found
		//
		bool isItemFound = false;

		//stores the index number of the specific item if found
		//
		size_t foundItemIndex = -1;

		//searches through the items vector object in order to find the specific item, and that it is not filled
		//
		for (size_t i = 0; i < m_items.size() && !isItemFound; ++i) {

			//stores the specific index if the item matches
			//
			if (m_items[i].nameOfItem == item.getName()) {
				foundItemIndex = i;

				//if specific item contains a status of not filled, flag will change states and stop the for-loop from further iterating  
				//
				if (m_items[i].filledStatus != true) {
					isItemFound = true;
				}
			}
		}

		//if an item is not found, all of the following code will not be executed
		//
		if (foundItemIndex != (size_t) -1) {

			//if an item is found and its filled status is true, the following code executes
			//
			if (m_items[foundItemIndex].filledStatus) {
				std::cout << " Unable to fill " << m_nameOfCustomer << " " << "[" << m_nameOfProduct << "]" << "[" << m_items[foundItemIndex].nameOfItem << "]" << "[" << m_items[foundItemIndex].serialNumber << "]" << " already filled" << std::endl;
			}

			//if the item's quantity from the inventory is empty, the following code executes
			//
			else if (item.getQuantity() == 0) {
				std::cout << " Unable to fill " << m_nameOfCustomer << " " << "[" << m_nameOfProduct << "]" << "[" << m_items[foundItemIndex].nameOfItem << "]" << "[" << item.getSerialNumber() << "]" << " out of stock" << std::endl;
			}

			//if an item is found and its filled status is false, the following code executes
			//
			else {
				//adds information to the specific index of the vector object
				m_items[foundItemIndex].serialNumber = item.getSerialNumber();
				m_items[foundItemIndex].filledStatus = true;

				//decrements the quantity of the item by 1, and increments its serial number by 1
				--item;

				std::cout << " Filled " << m_nameOfCustomer << " " << "[" << m_nameOfProduct << "]" << "[" << m_items[foundItemIndex].nameOfItem << "]" << "[" << m_items[foundItemIndex].serialNumber << "]" << std::endl;
			}
		}
		
	}

	//query that searches the list of items requested and returns true if all have been filled, false otherwise
	//
	bool CustomerOrder::isFilled() const {

		bool requestedFilledStatus = true;

		//range-based for loop is used to iterate through the vector object in order to find if there is any filled status that is false
		//
		for (auto& i : m_items) {
			
			//if any item has a false filled status, it changes the requestedFilledStatus to false
			//
			if ( !(i.filledStatus) ) {
				requestedFilledStatus = false;
			}
		}

		return requestedFilledStatus;
	}

	//query that receives the name of an item, search the item request list for that item
	//
	bool CustomerOrder::isItemFilled(const std::string& item) const {

		bool requestedFilledStatus = true;

		//range-based for loop is used to iterate through the vector object in order to find if there is any filled status that is false
		//
		for (auto& i : m_items) {

			//if the string argument matches the item name and if it has a false filled status, it changes the requestedFilledStatus to false
			//
			if( (i.nameOfItem == item) && !(i.filledStatus) ) {
				requestedFilledStatus = false;
			}
		}

		return requestedFilledStatus;
	}

	//query that returns the name of the customer and their product
	//
	std::string CustomerOrder::getNameProduct() const {
		
		//initializes the string type nameProduct to the name of customer 
		//
		std::string nameProduct = m_nameOfCustomer;
		
		//the counter begins at the customer name's length, and it adds a space to the nameProduct variable until the counter is 1 less than the max name field width 
		//
		for (size_t i = m_nameOfCustomer.length(); i < m_nameFW; ++i) {
			nameProduct += " ";
		}

		//adds the name of product to the nameProduct variable
		//
		nameProduct += " "; 
		nameProduct += "[" + m_nameOfProduct + "]";

		return nameProduct;
	}

	//query that receives a reference to an std::ostream object os and a Boolean showDetail and inserts the data for the current object into stream os
	//
	void CustomerOrder::display(std::ostream& os, bool showDetail) const {

		//outputs the name of product
		//
		os << getNameProduct() << std::endl;

		//if the Boolean is false the data consists of the name of the customer, the product being assembled, and the list of items on the order
		//
		if (!showDetail) {
			
			for (auto& i : m_items) {
				os << std::setw(m_nameFW + 1) << " " << i.nameOfItem << std::endl;
			}
		}
		//otherwise, the data consists of the name of the customer, the product being assembled, and the list of items with detailed information on the order such as name of the item, its serial number and its filled status
		//
		else {
			
			for (auto& i : m_items) {
				os << std::setw(m_nameFW + 1) << " " << "[" << i.serialNumber << "]" << " " << i.nameOfItem << " - " << (i.filledStatus ? "Filled" : "Not Filled") << std::endl;
			}
		}
	}

	//deallocates any memory that the object has allocated
	//
	CustomerOrder::~CustomerOrder() {}
}