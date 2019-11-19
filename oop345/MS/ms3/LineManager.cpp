// Assembly Line Project
// LineManager.cpp
// Mohammad Sharafifar
// Student ID : 143473171
// Email : msharafifar@myseneca.ca
// 2019/July/20
//
#include "LineManager.h"
using namespace std;

namespace sict {
    
    /*
     
      This constructor moves the customer orders to the front of a queue holding the orders waiting to be filled
	and determines the index of the last station on the line.
     
	- a reference to an std::vector of Station addresses,
     
	- a reference to an std::vector of size_t objects
      object contains the index in the vector of Station addresses
	 			that is the index the next station in the assembly line; for example, the vector{ 2, 3, 1, 5, 0 }

                     - station 0->station 2
                     - station 1->station 3
                     - station 2->station 1
                     - station 3->station 5
                     - station 4->station 0
                     - for an assembly line 4 -> 0 -> 2 -> 1 -> 3 -> 5
    */
    
	LineManager::LineManager(std::vector<Station*>& pstation, std::vector<size_t>& check, std::vector<CustomerOrder>& porders,
		size_t first_check_vector, std::ostream& os)		:	stations(pstation), check_vector(check), orderNumber(porders.size()), firstStation(first_check_vector) {
		for (size_t i = 0u; i < porders.size(); i++) {
			toFill.push_front(std::move(porders[i]));
		}

		lastStation = first_check_vector;
		
		for (size_t i = 0u; i < check_vector.size(); i++) {
			if (check_vector[lastStation] < stations.size()) {
				lastStation = check_vector[lastStation];
			}
		}
	}

	// receives a reference to an std::ostream object os and displays the completed and incomplete orders
    //
    
	void LineManager::display(std::ostream& os) const {
		os << "COMPLETED ORDERS" << std::endl;
		for (size_t i = 0u; i < completed.size(); i++) {
			completed[i].display(os, true);
		}
		os << std::endl;
		os << "INCOMPLETE ORDERS" << std::endl;
		for (size_t i = 0u; i < notCompleted.size(); i++) {
			notCompleted[i].display(os, true);
		}
	}

	/*
       If there is a customer order on the back of the queue of orders waiting to be filled,
	   this function moves it to the starting station on the line.
       This function returns true if all the orders have been processed
    */
    
	bool LineManager::run(std::ostream& os)		{
		bool ret = false;

		if (!toFill.empty()) {
			*stations[firstStation] += std::move(toFill.back());
			toFill.pop_back();
		}

		for (size_t i = 0u; i < stations.size(); i++) {
			stations[i]->fill(os);
		}

		for (size_t i = 0u; i < stations.size(); ++i) {
			if (stations[i]->hasAnOrderToRelease()) {
				CustomerOrder custOrder;
				bool itIsComplete = stations[i]->pop(custOrder);
				os << " --> " << custOrder.getNameProduct() << " moved from " << stations[i]->getName() << " to ";
				if (i != lastStation) {
					os << stations[check_vector[i]]->getName() << std::endl;
					*stations[check_vector[i]] += std::move(custOrder);
				}
				else if (itIsComplete) {
					os << "Completed Set" << std::endl;
					completed.push_back(std::move(custOrder));
				}
				else {
					os << "Incomplete Set" << std::endl;
					notCompleted.push_back(std::move(custOrder));
				}
			}
		}

		if ((completed.size() + notCompleted.size()) == orderNumber) {
			ret = true;
		}

		return ret;
	}
}

