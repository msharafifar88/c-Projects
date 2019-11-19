/**********************************************************
 * Name:			Mohammad Sharafiafar
 * Student ID:		143473171
 * Seneca email:	msharafifar@myseneca.ca
 * Section:			SHH
 **********************************************************/

#include <iostream>
#include <cstring>
#include "Book.h"


using namespace std;
namespace sict {

	void Book::set(const char* g_name , const char* f_name, const char* rn_title, long long int isbn) {
		if (isbn > min_isbn_value && isbn < max_isbn_value) {
			strncpy(family_name, f_name, max_name_size + 1);
			family_name[max_name_size] = '\0';
			strncpy(given_name, g_name, max_name_size + 1);
			given_name[max_name_size] = '\0';
			strncpy(title, rn_title, max_title_size + 1);
			title[max_title_size] = '\0';
			ISBN = isbn;
		}
		else {
			strcpy(given_name, g_name);
			strcpy(family_name, f_name);
			strcpy(title, rn_title);
			ISBN = 0;
		}
	}
		bool Book::isEmpty() const {
			if ((ISBN == 0) || (ISBN > max_isbn_value) || ISBN < min_isbn_value)

				return true;
			else {
				return false;
			}

		}
		void Book::display() const {
			if (!isEmpty()) {
		
				cout << "Author: " << family_name << ", " << given_name << endl;
				cout << "Title: " << title << endl;
				cout << "ISBN-13: " << ISBN << endl;
			}
			else {

				cout << "The book object is empty!" << endl;
			}
				
		}

		
	
}
