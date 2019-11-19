// Name Mohammad Sharafiafar         27/1/2019          lab section SAA        Student ID : 143473171

// TODO: include the necessary headers
#include <iostream>
#include "CellPhone.h"
using namespace std;
// TODO: the sict namespace
namespace sict
{
	// TODO: definition for display(...)
	void display(CellPhone& pPhones)
	{
		cout << "Phone " << pPhones.m_model << " costs $" << pPhones.m_price << "!" << endl;	
	}
	void display(CellPhone pPhones[], int element)
	{
            int i;
          double cheapPrice = 0.00;
               cout << "------------------------------" << endl;
            cout << "Phones available at the mall:" << endl; 
            cout<< "------------------------------" << endl;   
              for (i=0; i<element;i++)
               {
                 cout << i+1 << ". ";
                
                   display(pPhones[i]);
                  if(cheapPrice > pPhones[i].m_price);
                    cheapPrice = pPhones[i].m_price;
                      
                }
                    
                   cout << "------------------------------" << endl;
                      cout << "The cheapest phone costs $" << cheapPrice << "." << endl;
                      cout << "------------------------------" << endl;
                   
            } 

}
                
              
                   


	
	


