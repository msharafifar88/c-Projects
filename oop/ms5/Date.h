/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#ifndef DATE_H
#define DATE_H

#include <iostream>

namespace ama {

	const int min_year = 2019;
	const int max_year = 2028;
	const int no_error = 0;
	const int error_year = 1;
	const int error_mon = 2;
	const int error_day = 3;
	const int error_invalid_operation = 4;
	const int error_input = 5;

	class Date {
		int Year;
		int Month;
		int Day_of_The_Month;
		int Status;
		void status(int newStatus);
		int mdays(int year, int month) const;

	public:

		Date();
		Date(int, int, int);
		int status() const; 
		void clearError();
		bool isGood() const;
		Date& operator+=(int);
		Date& operator++();
		Date operator++(int);
		Date operator+(int);
		bool operator==(const Date& rhs) const;
		bool operator !=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator <=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os) const;
	};


	std::istream& operator>>(std::istream& is, Date& date);
	std::ostream& operator <<(std::ostream& os, const Date& date);

}

#endif
