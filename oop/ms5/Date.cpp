/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Date.h"


using namespace std;
using namespace ama;
namespace ama {
	void Date::status(int newstatus) {

		Status = newstatus;

	}

	int Date::mdays(int year, int mon) const {

		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));


	}
	Date::Date() {
		Year = 0;
		Month = 0;
		Day_of_The_Month = 0;
		status(no_error);

	}
	Date::Date(int year, int month, int day) {
		if (year >= min_year && year <= max_year) {
			if (month > 0 && month <= 12) {
				if (day > 0 && day <= mdays(year, month)) {
					status(no_error);
					Year = year;
					Month = month;
					Day_of_The_Month = day;
				}
				else {
					*this = Date();
					status(error_day);
				}
			}
			else {
				*this = Date();
				status(error_mon);
			}
		}


		else {

			*this = Date();
			status(error_year);

		}

	}
	int Date::status() const {
		return Status;



	}
	void Date::clearError() {
		status(no_error);

	}
	bool Date::isGood() const {

		return (Status == no_error && Year != 0);

	}
	Date& Date::operator+=(int days) {
		if (isGood() == false || Year == 0 || Day_of_The_Month + days <= 0 || Day_of_The_Month + days > mdays(Year, Month)) {
			status(error_invalid_operation);

		}
		else {
			Day_of_The_Month = Day_of_The_Month + days;

		}

		return *this;

	}

	Date& Date::operator++()
	{

		if (isGood() == false || Year == 0 || (Day_of_The_Month + 1) > mdays(Year, Month)) {
			status(error_invalid_operation);

		}
		else {
			Day_of_The_Month++;
		}

		return *this;

	}
	Date Date::operator++(int days)
	{ 
		Date copy = *this;
		if (isGood() == false || Year == 0 || Day_of_The_Month + 1 > mdays(Year, Month)) {
			status(error_invalid_operation);
		}
		else {
			++(*this);
		}

		return copy;


	}
	Date Date::operator+(int days) {
		Date sum = *this;
		if (isGood() == false || Year == 0 || Day_of_The_Month + days > mdays(Year, Month)) {
			sum.status(error_invalid_operation);

		}
		else {
			sum.Day_of_The_Month = days + Day_of_The_Month;
		}


		return sum;
	}
	bool Date:: operator==(const Date& rhs) const {
		bool same;
		if (Year == rhs.Year && Month == rhs.Month && Day_of_The_Month == rhs.Day_of_The_Month) {
			same = true;
		}
		else {
			same = false;
		}

		return same;



	}
	bool Date::operator !=(const Date& rhs) const {

		bool notSame;
		if (Year == rhs.Year && Month == rhs.Month && Day_of_The_Month == rhs.Day_of_The_Month) {
			notSame = false;
		}
		else {
			notSame = true;
		}

		return notSame;
		

	}
	bool Date:: operator<(const Date& rhs) const {
		bool before;
		if (Year < rhs.Year) {
			before = true;
		}
		else if (Year == rhs.Year) {
			if (Month < rhs.Month) {
				before = true;
			}
			else if (Month == rhs.Month) {
				if (Day_of_The_Month < rhs.Day_of_The_Month) {
					before = true;
				}
				else {
					before = false;
				}
			}
			else {
				before = false;
			}
		}
		else {
			before = false;
		}
		return before;
	}
	bool Date::operator>(const Date& rhs) const {

		bool after;
		if (Year > rhs.Year) {
			after = true;
		}
		else if (Year == rhs.Year) {
			if (Month > rhs.Month) {
				after = true;
			}
			else if (Month == rhs.Month) {
				if (Day_of_The_Month > rhs.Day_of_The_Month) {
					after = true;
				}
				else {
					after = false;
				}
			}
			else {
				after = false;
			}
		}
		else {
			after = false;
		}
		return after;
	}
	bool Date::operator<=(const Date& rhs) const {
		bool lessEqual;
		if (*this < rhs || *this == rhs) {
			lessEqual = true;
		}
		else {
			lessEqual = false;
		}
		return lessEqual;
	}

	bool Date::operator>=(const Date& rhs) const {


		bool greaterEqual;
		if (*this > rhs || *this == rhs) {
			greaterEqual = true;
		}
		else {
			greaterEqual = false;
		}

		return greaterEqual;


	}
	std::istream& Date::read(std::istream& is) {
		char sChar;
		is >> Year >> sChar >> Month >> sChar >> Day_of_The_Month;
		if (is.fail()) {
			*this = Date();
			status(error_input);
		}
		else if (Year >= min_year && Year <= max_year && Month >= 1 && Month <= 12 && Day_of_The_Month <= mdays(Year, Month) && Day_of_The_Month >= 1) {

			status(no_error);
		}

		else if (Year < min_year || Year > max_year) {
			*this = Date();
			status(error_year);
		}
		else if (Month < 1 || Month > 12) {
			*this = Date();
			status(error_mon);
		}
		else if (Day_of_The_Month > mdays(Year, Month) || Day_of_The_Month < 1) {
			*this = Date();
			status(error_day);
		}
		return is;

	}
	std::ostream& Date::write(std::ostream& os) const {

		os.fill('0');
		os.width(4);
		os << Year << "/";
		os.setf(ios::right);
		os.width(2);
		os << Month << "/";
		os.width(2);
		os << Day_of_The_Month;
		os.unsetf(ios::right);
		os.fill(' ');
		return os;



	}

	std::istream&  operator>>(std::istream& is, Date& date) {
		date.read(is);
		return is;
	}

	std::ostream& operator<<(std::ostream & os, const Date& date) {
		date.write(os);
		return os;
	}

}
