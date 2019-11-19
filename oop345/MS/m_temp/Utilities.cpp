// Assembly Line Project
// Utilities.cpp
//Mohammad Sharafifar
//143473171

//#include <iostream>
//#include <string>
//using namespace std;
//
#include "Utilities.h"

namespace sict {
	static char dm_delimiter;
	static size_t dm_width;
//
// Default Constructor
// sets the object to a safe empty state
    //
	Utilities::Utilities() {
		dm_width = 1;
	}

	// Extract the next token in the string starting at the position next_pos, and ending immediately before the delimiter character
	// Input: string that was read from a file, token's initial position
	// Output: Token extracted
    //
	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		std::string auxStr = str.substr(next_pos);
		std::string auxToken = "";
		size_t auxPos = 0;
		bool lastField = false;

		if (auxStr.find(dm_delimiter) < auxStr.find("\n")) {
			auxToken = auxStr.substr(0, auxStr.find(dm_delimiter));
		} 
		else {
			auxToken = auxStr.substr(0, auxStr.npos);
			lastField = true;
		}

		auxPos = next_pos + auxToken.length() + 1;

		if (lastField == false) {
			if ((auxPos - next_pos - 1) > getFieldWidth()) {
				setFieldWidth(auxPos - next_pos - 1);
			}

			if (str.substr(auxPos, 1) == std::string(1, dm_delimiter)) {
				throw "Error - There are 2 delimiters in sequence";
			}
		}
		else {
			auxPos = 9999;
		}


		next_pos = auxPos;
		return auxToken;
	}

	// Return the delimiter character
	// Input: - 
	// Output: Delimiter
    //
	const char Utilities::getDelimiter() const {
		return dm_delimiter;
	}
	
	// Return the field width of the current object
	// Input: -
	// Output: width
    //
	size_t Utilities::getFieldWidth() {
		return dm_width;
	}

	// Set the delimiter character for all object of this class
	// Input: delimiter charcter
	// Output: -
    //
	void Utilities::setDelimiter(const char d) {
		dm_delimiter = d;
	}
	
	// Set the field width for the current object
	// Input: width
	// Output: -
    //
	void Utilities::setFieldWidth(size_t w) {
		dm_width = w;
	}

	};
