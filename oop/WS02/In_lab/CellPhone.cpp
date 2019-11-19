// TODO: include the necessary headers
#include <iostream>
#include "CellPhone.h"
using namespace std;
// TODO: the sict namespace
namespace sict {
    // TODO: definition for display(...) 
	void display(const CellPhone nCellPhone) {
		cout << "Phone "  << nCellPhone.m_model << " costs $" << nCellPhone.m_price << "!" << endl;
			
	}
}