// Name Mohammad Sharafiafar         27/1/2019          lab section SAA        Student ID : 143473171
// TODO: header safeguards
#ifndef NAMESPACE_CELLPHONE_H 
#define NAMESPACE_CELLPHONE_H 

// TODO: sict namespace
namespace sict
{
	// TODO: define the structure CellPhone in the sict namespace
	struct CellPhone
	{
		char m_model[32];
		double m_price;
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(CellPhone& pPhones);
	void display(CellPhone pPhones[], int element);
	
}

#endif 
