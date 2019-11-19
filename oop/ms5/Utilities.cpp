/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include <iostream>	
#include "Utilities.h"
#include "Perishable.h"
#include "iProduct.h"

using namespace std;


namespace ama {

	double& operator+=(double& total, const iProduct& prod) {
		total = total + prod.total_cost();
		return total;
	}
	ostream& operator<<(ostream& out, const iProduct& prod) {
		prod.write(out, write_human);
		return out;
	}
	istream& operator>>(istream& in, iProduct& prod) {
		prod.read(in, true);
		return in;
	}
	iProduct* createInstance(char tag) {
		iProduct* iptr = nullptr;
		if (tag == 'N' || tag == 'n') {
			iptr = new Product();
		}
		if (tag == 'P' || tag == 'p') {
			iptr = new Perishable();
		}
		return iptr;



	}
}
























