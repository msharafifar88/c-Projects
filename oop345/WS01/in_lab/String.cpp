/*
 ============================================================================
 Name        : String.cpp
 Author      : Mohammad Sharafifar
 Email       : mSharafifar@myseneca.ca
 Student #   : 147
 Course Code : OOP345
 Section     : SBB
 Date        : may 17, 2019 -
 Workshop    : Workshop 1 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : Describe what the file does
  ============================================================================
 */

#define CRT_SECURE_NO_WARNINGS

#include"String.h"
#include <cstring>

using namespace std;
extern int INITIAL;

namespace sict {

	// one argument constructor
	String::String(const char* stringname) {

		if (stringname != nullptr && stringname[0] != '\0') {
			strncpy(srt_name, stringname, MAX_CHAR);
			srt_name[MAX_CHAR] = '\0';

		}
		else {
			srt_name[0] = '\0';
		}
	}
	// void display(std::ostream&) const; function
	void String::display(std::ostream& os) const {
		os << srt_name;
	}
	// helper non friend operator
	std::ostream& operator<<(std::ostream& os, const String& stringname) {
		static int item = INITIAL;
		cout << item << ": ";
		stringname.display(os);
		item++;
		return os;
	}

}
