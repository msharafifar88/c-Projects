// Assembly Line Project
// Station.cpp
// Mohammad Sharafifar
// Student ID : 143473171
// Email : msharafifar@myseneca.ca
// 2019/July/20
//

#include "Station.h"
using namespace std;
namespace sict {
    
	// One-argument Constructor
    //
    
	Station::Station(const std::string& str) : itemset(str) {
	}

	// A query that receives a reference to an std::ostream object os and displays the data for its ItemSet on os.
    //
    
	void Station::display(std::ostream& os) const {
		itemset.display(os, false);
	}

	// A modifier that fills the last order in the customer order queue, if there is one. If the queue is empty, this function does nothing.
    //
    
	void Station::fill(std::ostream& os) {
		if (!customer_order .empty()) {
			customer_order .back().fillItem(itemset, os);
		}
	}

	// A forwarding query that returns a reference to the name of the ItemSet sub - object.
	//
    
	const std::string& Station::getName() const {
		return itemset.getName();
	}

	/*
     
     *   A query that returns the release state of the current object.This function returns true if the station has filled the item request(s)
     
     *   for the customer order at the front of the queue or the station has no items left; otherwise, it returns false.
     
      *  If there are no orders in the queue, this function returns false.
     
     */
    
	bool Station::hasAnOrderToRelease() const {
		bool ret = false;
		if (!customer_order .empty()) {
			if (customer_order .front().isItemFilled(itemset.getName()) || itemset.getQuantity() == 0) {
				ret = true;
			}
		}
		return ret;
	}

	/*
     
       A modifier that decrements the number of items in the ItemSet, increments the serial number for the next item,
	   and returns a reference to the current object.
	
   */
    
	Station& Station::operator--() {
		itemset.operator--();
		return *this;
	}

	/* A modifier that receives an rvalue reference to a customer order and moves that order to the back of the station’s
	//	queue and returns a reference to the current object.
	*/
    
	Station& Station::operator+=(CustomerOrder&& order) {
		customer_order .push_back(std::move(order));
		return *this;
	}

	/*
       A modifier that receives an lvalue reference to a customer order, removes the order at the front of the queue
	   and moves it to the calling function through the parameter list.This function returns true if the station filled its part of the order; false otherwise.
     
        If there are no orders in the queue, this function returns false.
	
     */
    
	bool Station::pop(CustomerOrder& co) {
		bool ret;
		if (!customer_order .empty()) {
			auto front = customer_order .begin();
			ret = (*front).isFilled();
			CustomerOrder order = std::move(*front);
			customer_order .pop_front();
			co = std::move(order);
		}
		else {
			ret = false;
		}
		return ret;
	}

	// A query that reports the state of the ItemSet object in the following format 
    //
    
	void Station::validate(std::ostream& os) const {
		os << " getName(): " << itemset.getName() << endl;
		os << " getSerialNumber(): " << itemset.getSerialNumber() << endl;
		os << " getQuantity(): " << itemset.getQuantity() << endl;
	}
};
