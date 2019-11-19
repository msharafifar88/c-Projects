/*
 ============================================================================
 Name        : String.h
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

#ifndef SICT_STRING_H
#define SICT_STRING_H
#define CRT_SECURE_NO_WARNINGS

#include<iostream>
namespace sict {

	//const int MAX_CHAR = 3;

	class String {

		//char srt_name[MAX_CHAR + 1];
        char *srt_name;
	public:
        ~String();
		String(const char*);
		void display(std::ostream&) const;

	};
	std::ostream& operator<<(std::ostream& os, const String& stringname);
}
#endif
