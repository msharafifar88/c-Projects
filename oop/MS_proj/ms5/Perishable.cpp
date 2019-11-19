/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include "Perishable.h"

using namespace std;

namespace ama {
	Perishable::Perishable(const char tag) :Product(tag) {

	}
	std::ostream& Perishable::write(std::ostream& out, int writeMode) const {
		Product::write(out, writeMode);
		if (!isEmpty() && !isClear()) {
			if (writeMode == write_human) {
				out.width(max_length_label);
				out << "Expiry Date: " << expiry_date << endl;
			}
			else if (writeMode == write_table) {
				out << " " << expiry_date << " |";
			}
			else if (writeMode == write_condensed) {
				out << ", " << expiry_date;
			}
		}
		return out;
	}
	std::istream& Perishable::read(std::istream& in, bool interractive) {
		Product::read(in, interractive);
		
		if (interractive == true) {
			cout.width(max_length_label);
			cout << "Expiry date (YYYY/MM/DD): ";
			expiry_date.read(in); 
			if (in.fail() || expiry_date.isGood() == false) {


				in.istream::setstate(ios::failbit);
				if (expiry_date.status() == error_year) {
					message("Invalid Year in Date Entry");
					
				}
				else if (expiry_date.status() == error_mon) {
					message("Invalid Month in Date Entry");
				}
				else if (expiry_date.status() == error_day) {
					message("Invalid Day in Date Entry");
				}
				else if (in.fail()) {
					message("Invalid Date Entry");
				}



			}
			


		}
		else if (interractive == false) {
			char rubbish;
			in >> rubbish >> expiry_date;
			
			in.clear();
			in.ignore(2000, '\n');
			
		}
		return in;
	}
}
