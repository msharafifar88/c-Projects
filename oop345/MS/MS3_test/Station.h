// Assembly Line Project
// Station.h
// Mohammad Sharafifar - 148218175
// 2019/July/20
#ifndef _345_STATION_H_
#define _345_STATION_H_
#include <iostream>
#include <vector>
#include <deque>
//#include <queue>
#include "CustomerOrder.h"
#include "ItemSet.h"
using namespace std;

namespace sict {
	class Station {
		std::deque<CustomerOrder> cOrder;
		ItemSet itemset;

	public:
		Station(const std::string&);					// One-argument Constructor
		
		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;

		Station(Station &&) = delete;
		Station & operator=(Station &&) = delete;
		Station(const Station &) = delete;
		Station & operator=(const Station &) = delete;
	};
}
#endif
