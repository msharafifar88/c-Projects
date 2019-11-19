// Assembly Line Project
// LineManager.h
// Mohammad Sharafifar
// Student ID : 143473171
// Email : msharafifar@myseneca.ca
// 2019/July/20
//

#ifndef _345_LINEMANAGER_H_
#define _345_LINEMANAGER_H_
#include <iostream>
#include <string>
#include <vector>
#include "CustomerOrder.h"
#include "Station.h"
using namespace std;

namespace sict {

	class LineManager {
		std::deque<CustomerOrder> completed;
		std::deque<CustomerOrder> notCompleted;

		std::deque<CustomerOrder> toFill;
		std::vector<Station*> stations;
		std::vector<size_t> check_vector;
		const size_t orderNumber;

		const size_t firstStation;
		size_t lastStation;


	public:
		LineManager(std::vector<Station*>& pstation, std::vector<size_t>& check, std::vector<CustomerOrder>& porders, size_t fstIx, std::ostream& os);
		void display(std::ostream& os) const;
		bool run(std::ostream& os);

		LineManager(LineManager &&) = delete;
		LineManager & operator=(LineManager &&) = delete;
		LineManager(const LineManager &) = delete;
		LineManager & operator=(const LineManager &) = delete;
	};
}
#endif
