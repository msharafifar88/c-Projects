// TODO: add file header comments here
/**********************************************************
 * Name:			Mohammad Sharafiafar
 * Student ID:		143473171
 * Seneca email:	msharafifar@myseneca.ca
 * Section:			SHH
 **********************************************************/

// TODO: add your headers here
#include <iostream>
#include "Traveler.h"
#include <cstring>

using namespace std;
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Traveler::Traveler() {
		First_name[0] = '\0';
		Last_name[0] = '\0';
		Destinamtion[0] = '\0';

	}
	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char* fname, const char* lname, const char* dest) {
		if (fname == nullptr || lname == nullptr || dest == nullptr)
		{
			*this = Traveler();
		}
		else
		{
			strcpy(First_name, fname);
			strcpy(Last_name, lname);
			strcpy(Destinamtion, dest);
		}
	}

	// TODO: implement isEmpty query here
	bool Traveler::isEmpty() const
	{
		if (strlen(First_name) > 0 && strlen(Last_name) > 0 && strlen(Destinamtion) > 0) {
			return false;
		}
		else
		{
			return true;
		}
		
	}

	// TODO: implement display query here
	void Traveler::display() const {

		if (First_name[0] == '\0' || Last_name[0] == '\0' || Destinamtion[0] == '\0') {
			cout << "--> Not a valid traveler! <--" << endl;

		}else
		{ 
			cout << First_name <<" "<< Last_name << " goes to " << Destinamtion << endl;
		}
	}
}
