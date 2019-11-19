/**********************************************************
 * Name:			Mohammad Sharafiafar
 * Student ID:		143473171
 * Seneca email:	msharafifar@myseneca.ca
 * Section:			SHH
 **********************************************************/
#ifndef SICT_BOOK_H
#define SICT_BOOK_H
#include <iostream>

namespace sict {
	const int max_title_size = 32;
	const int max_name_size = 16;
	const long long int min_isbn_value = 1000000000000;
	const long long int max_isbn_value = 9999999999999;

	class Book {
		char family_name[max_name_size];
		char given_name[max_name_size];
		long long int ISBN;
		char title[max_title_size+1];
		

		public:
			void set(const char* g_name, const char* f_name, const char* rn_title,long long int isbn);
			bool isEmpty() const;
			void display() const;
		

	};
}
#endif