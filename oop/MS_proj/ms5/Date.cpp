
/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#include<iostream>
#include <iomanip>
#include "Date.h"
using namespace std;
using namespace ama;

void ama::Date::status(int newStatus)
{
	error_state = newStatus;
}

int ama::Date::mdays(int year, int mon) const
{
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
	int month = mon >= 1 && mon <= 12 ? mon : 13;
	month--;
	return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

}
ama::Date::Date()
{
	year = 0;
	month = 0;
	day = 0;
	error_state = no_error;

}
bool ama::Date::isvild() const
{
	if (year >= min_year && year <= max_year && month >= 1 && month <= 12 && day >= 1 && day <= mdays(year, month) && error_state == no_error)
	{
		return true;
	}
	else
	{
		return false;
	}

}
ama::Date::Date(int y, int m, int d)
{
	int error = 0;
	if (y >= min_year && y <= max_year)
	{
		if (m >= 1 && m <= 12)
		{
			if (!(d >= 1 && d <= mdays(y, m)))
			{
				error = error_day;
			}
			else
			{
				error_state = no_error;
			}


		}
		else
		{
			error = error_mon;
		}
	}
	else
	{
		error = error_year;
	}

	if (error == no_error)
	{
		year = y;
		month = m;
		day = d;
	}
	else
	{
		*this = Date();
		error_state = error;
	}
}
int ama::Date::status() const
{
	return error_state;
}
void ama::Date::clearError()
{
	error_state = no_error;
}
bool ama::Date::isGood() const
{


	if (isvild())
	{
		return true;
	}
	else
	{
		return false;
	}
}


Date& ama::Date::operator+=(int days)
{

	if (isvild() && day + days <= mdays(year, month) && day + days >= 0)
	{
		day += days;
	}
	else
	{
		error_state = error_invalid_operation;
	}

	return *this;
}
Date& ama::Date::operator++()
{
	*this += 1;
	return *this;
}
Date ama::Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return  tmp;
}
Date ama::Date::operator+(int days) const

{
	Date tmp = *this;
	tmp += days;

	if (tmp.error_state != error_invalid_operation)
	{
		return tmp;
	}
	else
	{

		return tmp;
	}
}
bool ama::Date::operator==(const Date & rhs) const
{
	if (this->year == rhs.year&&this->month == rhs.month&&this->day == rhs.day)
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool ama::Date::operator!=(const Date & rhs) const
{
	if (!(*this == rhs))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ama::Date::operator<(const Date & rhs) const
{
	if (this->year < rhs.year)
	{
		return true;
	}
	else if (this->month < rhs.month)
	{
		return true;
	}
	else if (this->day < rhs.day)
	{
		return true;
	}
	return false;
}

bool ama::Date::operator>(const Date & rhs) const
{
	if (this->year > rhs.year)
	{
		return true;
	}
	else if (this->month > rhs.month)
	{
		return true;
	}
	else if (this->day > rhs.day)
	{
		return true;
	}
	return false;
}
bool ama::Date::operator<=(const Date & rhs) const
{
	if (this->year <= rhs.year&&this->month <= rhs.month&&this->day <= rhs.day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool ama::Date::operator>=(const Date & rhs) const
{
	if (this->year >= rhs.year&&this->month >= rhs.month&&this->day >= rhs.day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

istream& Date::read(std::istream & is)
{




	char a = '\n';
	is >> year >> a >> month >> a >> day;

	Date tmp(year, month, day);
	if (tmp.error_state != no_error)
	{

		*this = Date();

	}
	error_state = tmp.error_state;

	if (is.fail())
	{
		Date();
		error_state = error_input;
	}

	return  is;


	/*

	 if(!(is.fail())){
	 *this = Date();
	 status(error_input);

	 }else if (year < min_year || year > max_year) {
	 *this = Date();
	 status( error_year);
	 }else if (month < 1 || month > 12) {
	 *this = Date();
	 stat = error_mon;
	 }else if (day < 1 || day > mdays(year , month)) {
	 *this = Date();
	 stat = error_day;
	 }
	 else {

	 *this = Date (year, month, day);
	 }

	 return is;
	 */
}
ostream& Date::write(std::ostream & os) const
{
	os.setf(ios::right);
	os << setfill('0') << setw(4) << this->year << "/" << setw(2) << month << "/" << setw(2) << day << setfill(' ');
	return os;

}

std::istream & ama::operator>>(std::istream & is, Date & dt)
{
	dt.read(is);
	return     is;

}
std::ostream & ama::operator<<(std::ostream & os, const Date &dt)
{


	dt.write(os);
	return os;


}

