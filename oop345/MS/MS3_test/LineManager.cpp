// Assembly Line Project
// LineManager.cpp
// Mohammad Sharafifar - 148218175
// 2019/July/20
#include "LineManager.h"
using namespace std;

namespace sict {
	//This constructor moves the customer orders to the front of a queue holding the orders waiting to be filled 
	//and determines the index of the last station on the line.
	// Input: - a reference to an std::vector of Station addresses,
	//	      - a reference to an std::vector of size_t objects – each object contains the index in the vector of Station addresses
	//			that is the index the next station in the assembly line; for example, the vector{ 2, 3, 1, 5, 0 } represents 
	//			the following set of Station connections :
	//				- station 0->station 2
	//				- station 1->station 3
	//				- station 2->station 1
	//				- station 3->station 5
	//				- station 4->station 0
	//				- for an assembly line 4 -> 0 -> 2 -> 1 -> 3 -> 5
	//		  - a reference to an std::vector of CustomerOrder objects,
	//		  - the index of the starting station on the assembly line(4 in the example above) and
	//		  - a reference to an std::ostream object for displaying output.
	// Output: - 
	LineManager::LineManager(std::vector<Station*>& pstation, std::vector<size_t>& pix, std::vector<CustomerOrder>& porders,
		size_t fstIx, std::ostream& os)		:	stations(pstation), ix(pix), orderNumber(porders.size()), firstStation(fstIx) {
		for (size_t i = 0u; i < porders.size(); i++) {
			toFill.push_front(std::move(porders[i]));
		}

		lastStation = fstIx;
		
		for (size_t i = 0u; i < ix.size(); i++) {
			if (ix[lastStation] < stations.size()) {
				lastStation = ix[lastStation];
			}
		}
	}

	// A query that receives a reference to an std::ostream object os and displays the completed and incomplete orders at the end of the line.
	// Input: std::ostream
	// Output: -
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

	// If there is a customer order on the back of the queue of orders waiting to be filled,
	// this function moves it to the starting station on the line.
	// Input: std::ostream
	// Output: True / False - This function returns true if all the orders have been processed; false otherwise.
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
					os << stations[ix[i]]->getName() << std::endl;
					*stations[ix[i]] += std::move(custOrder);
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

