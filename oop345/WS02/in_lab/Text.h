/*
 ============================================================================
 Name        : Text.h
 Author      : Mohammad Sharafifar
 Email       : msharafifar@myseneca.ca
 Student #   : 147473171
 Course Code : OOP345
 Section     : SBB
 Date        : may 23, 2019 -
 Workshop    : Workshop 2 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : Describe what the file does
  ============================================================================ */
#ifndef Text_H
#define Text_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

namespace sict {

	class Text {

		std::string* m_stringArray;

		size_t num_strings;

	public:
		//a no-argument default constructor

		Text();

		//a 1-argument constructor that receives the address of a C-style null
		Text(const std::string&);

		//a copy constructor
		Text(const Text&);

		//a copy assignment operator
		Text& operator=(const Text&);

		//a destructor
		~Text();



		//size_t size() const a query that returns the number of records stored in the current object.

		size_t size() const;
	};
}
#endif
