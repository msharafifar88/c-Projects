#ifndef SICT_ASSEMBLY_LINE_H
#define SICT_ASSEMBLY_LINE_H
// Assembly Line Project
// AssemblyLine.h
// Elliott Coleshill, Chris Szalwinski
// Mohammad Sharafifar
// Student ID : 143473171
// Email : msharafifar@myseneca.ca
// 2019/July/20

#include <iostream>
#include <vector>
#include "ItemSet.h"
#include "Station.h"
#include "CustomerOrder.h"

namespace sict {
	class AssemblyLine {
		std::vector<ItemSet> inventory;
		std::vector<CustomerOrder>orders;
		std::vector<Station*> line;
		std::vector<size_t> nextStation;
		size_t firstStation{ 0u };
		const char* fInventory { nullptr };
        const char* fOrders    { nullptr };
		const char* fLine      { nullptr };
	public:
		AssemblyLine(char* filename[], int nfiles);
		void loadInventory(std::ostream& os);
		void loadOrders(std::ostream& os);
		void configureLine(std::ostream& os);
		void run(std::ostream& os);
	};
}
#endif
