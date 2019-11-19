/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include <iostream>
#ifndef  ama_Data_H
#define	 ama_Data_H



namespace ama
{

    const int min_year = 2019;
    const int max_year = 2028;
    const int no_error = 0;
    const int error_year = 1;
    const int error_mon = 2;
    const int error_day = 3;
    const int error_invalid_operation = 4;
    const int error_input =5;
    
	class Date
	{
        int year, month, day;
        int error_state;
		void status(int newStatus);
		int mdays(int year,int month) const;
		bool isvild() const;
	public:
		Date();
		Date(int y,int m, int d);
		int status() const;
		void clearError();
		bool isGood() const;
		
		Date& operator+=(int days);
		Date& operator++();
		Date operator++(int);
		Date operator+(int days) const ;
		
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator>=(const Date & rhs) const;
		bool operator<=(const Date & rhs) const;
		
		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os ) const;

	};
	std::istream& operator>>(std::istream&,  Date&);
	std::ostream& operator<<(std::ostream&, const Date&);
		
}
#endif // ! ama_Data_H
