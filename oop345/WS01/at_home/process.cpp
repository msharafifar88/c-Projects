/*
 ============================================================================
 Name        : process.cpp
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

#include <iostream>
#include "String.h"
#include "String.h"

namespace sict {
	void process(const char* str) {
		String a = String(str);
		std::cout << a << std::endl;
	}
}
