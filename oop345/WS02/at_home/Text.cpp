/*
 ============================================================================
 Name        : Text.cpp
 Author      : Mohammad Sharafifar
 Email       : msharafifar@myseneca.ca
 Student #   : 147473171
 Course Code : OOP345
 Section     : SBB
 Date        : may 23, 2019 -
 Workshop    : Workshop 2 - home
 ============================================================================
 */

 /*
  ============================================================================
  Description :  In the file Text we are implemented how to properly implement copy constructors, as well as their operators
  while using pointers as private members of a class.
  we also work on std::strings and we work with the heap and stack memory.
  we also manages a dynamically allocated array of std::strings.
  ============================================================================*/


#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

using namespace std;
namespace sict {

	//Default no argument constructor
	Text::Text() {
		m_stringArray = nullptr;
		num_strings = 0;
	}

	//1-argument constructor
	Text::Text(const std::string& num_new_req) {
		m_stringArray = nullptr;
		num_strings = 0;

		//checks if the file isn't empty
		if (!num_new_req.empty()) {
			string newString;
			ifstream file(num_new_req);

			//counts number of records in the file
			while (getline(file, newString)) {
				num_strings++;
			}

			//allocates memory to string object
			m_stringArray = new string[num_strings];

			//copies the records
			int count = 0;
			while (getline(file, newString)) {
				m_stringArray[count] = newString;
				count++;
			}
		}
	}

	//Copy constructor
	Text::Text(const Text& rhs) {

		m_stringArray = nullptr;

		//direct call to the copy assignment operator
		*this = rhs;
	}

	//Copy assignment operator
	Text& Text::operator=(const Text& source) {

		//checks for self-assignment
		if (this != &source)
		{
			//shallow copy non-resource variables
			num_strings = source.num_strings;

			//deallocate previously allocated memory
			delete[] m_stringArray;

			//allocate new dynamic memory
			if (source.m_stringArray != nullptr) {
				m_stringArray = new std::string[num_strings];

				//copy the resource data
				for (size_t i = 0; i < num_strings; i++) {
					m_stringArray[i] = source.m_stringArray[i];
		    	}
	    	}
      }
        return *this;
    }


	//Move constructor
	 Text::Text(Text&& source) {
		// direct call to move assignment operator
		*this = move(source);
	}

	//Move assignment operator
	Text& Text::operator=(Text&& source) {

		//checks for self assignment - if the object isn't being called on itself
		if (this != &source) {

			//deallocating prevously allocated memory
			delete[] m_stringArray;

			// Move the source's data into current object
			num_strings = source.num_strings;
			m_stringArray = source.m_stringArray;

			//Making the source's data as empty
			source.m_stringArray = nullptr;
			source.num_strings = 0;
		}
		//returns a reference to *this
		return *this;
	}

	//Destructor
	Text::~Text() {

		//deallocating memory
		delete[] m_stringArray;
		m_stringArray = nullptr;
	}

	//a query that returns the number of records stored in the current object
	size_t Text::size() const {

		return num_strings;
	}
}

