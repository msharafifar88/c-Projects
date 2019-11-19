// Assembly Line Project
// Utilities.h
// Mohammad Sharafifar - 148218175
// 2019/July/20

#pragma once
#ifndef _345_UTILITIES_H_
#define _345_UTILITIES_H_
#include <iostream>
#include <string>
using namespace std;

namespace sict {

	class Utilities {

	public:
		Utilities();						//Default Constructor
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		static size_t getFieldWidth();
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
	};
}

#endif
