// TODO: header safeguards
#ifndef NAMESPACE_HEADERFILENAME_H
#define NAMESPACE_HEADERFILENAME_H
#include <iostream>

// TODO: sict namespace
namespace sict {
// TODO: define the structure CellPhone in the sict namespace
	struct CellPhone {
		char m_model[32];
		int m_price;

	};
// TODO: declare the function display(...),
//         also in the sict namespace

	void display(const CellPhone nCellPhone);

}

#endif