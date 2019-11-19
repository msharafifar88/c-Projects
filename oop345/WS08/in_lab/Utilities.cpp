// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17
//Mohammad Sharafifar
//143473171
//2019/July/19

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

        for (size_t i = 0; i < desc.size(); i++) {
            for (size_t j = 0; j < price.size(); j++) {
                if (desc[i].code == price[j].code) {
                    Product* pointer = new Product(desc[i].desc, price[j].price);
                    pointer->validate();
                    priceList += pointer;
                    delete pointer;
                    pointer = nullptr;
                }
            }
        }
        







		return priceList;
	}
}
