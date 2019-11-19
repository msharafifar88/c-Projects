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

    void Book::set(const char* g_name, const char* f_name, const char* rn_title, long long int isbn) {
        
        
        long long int isbn1 = isbn;
        int sum = 0;
        int even_num = 0;
        int odd_num = 0;
        int check_digit = isbn1 % 10;
        if (isbn > min_isbn_value && isbn < max_isbn_value)
        {
        
            isbn1 /= 10;
            
            for (int i = 0; i < 12; ++i) {
                if (i % 2 == 0) {
                    even_num += isbn1 % 10;
                }
                else {
                    odd_num += isbn1 % 10;
                }
                isbn1 /= 10;
            }
            sum = (even_num * 3) + odd_num;
            
        }
        else {
            given_name[0] = '\0';
            family_name[0] = '\0';
            title[0] = '\0';
            ISBN = 0;
            
        }
        if (10 - sum % 10 == check_digit) {
            ISBN = isbn;
            strncpy(family_name, f_name, max_name_size + 1);
            family_name[max_name_size] = '\0';
            strncpy(given_name, g_name, max_name_size + 1);
            given_name[max_name_size] = '\0';
            strncpy(title, rn_title, max_title_size + 1);
        }
        else
        {
            given_name[0] = '\0';
            family_name[0] = '\0';
            title[0] = '\0';
            ISBN = 0;
        }
        
        
    }
    
    

	void Book::set(int year, double price)
	{
		if (!isEmpty()) {
			m_year = year;
			m_price = price;
		}
	}

    bool Book::isEmpty() const
     {
     return !ISBN;
     }

		/*
         bool Book::isEmpty() const {
			if ((ISBN == 0) )//|| (ISBN > max_isbn_value) || ISBN < min_isbn_value)

				return true;
			else {
				return false;
			}

		}
         */


    void Book::display(bool linear) const {
        if (!linear) {
            if (!isEmpty()) {
                cout << "Author: " << family_name << ", " << given_name << endl;
                cout << "Title: " << title << endl;
                cout << "ISBN-13: " << ISBN << endl;
                cout << "Publication Year: " << m_year << endl;
                cout << "Price: " << m_price << endl;
            }
            else {
                cout << "The book object is empty!" << endl;
            }
            
        }
        
        else
        {
            if (!isEmpty()) {
                cout << "|";
                cout.width(max_name_size);
                cout << family_name << "|";
                cout.width(max_name_size);
                cout << given_name << "|";
                cout.setf(ios::left);
                cout.width(max_title_size);
                cout << title;
                cout.unsetf(ios::left);
                cout << "|";
                cout.width(13);
                cout << ISBN << "|";
                cout.width(4);
                cout << m_year << "|";
                cout.setf(ios::fixed);
                cout.precision(2);
                cout.width(6);
                cout << m_price << "|" << endl;
                cout.unsetf(ios::fixed);
                cout.precision(6);
            }
            else {cout << "|";
                cout.width(92);
                cout.setf(ios::left);
                cout << "The book object is empty!";
                cout << "|" << endl;
                cout.unsetf(ios::left);
            }
        }
    }

		/*bool Book::isEmpty() const
		{
			return !ISBN;
		}*/

		
	
}
