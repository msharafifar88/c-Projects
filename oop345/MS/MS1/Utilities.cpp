// Assembly Line Project
// 2019/July/09
//Mohammad Sharafifar
//Student ID: 143473171
// Utilities.cpp


//#include <iostream>
//#include <string>

//using namespace std;

#include "Utilities.h"

namespace sict {

	static char dm_delimiter;
	static size_t dm_width;
//
//Default Constructor
    //

	Utilities::Utilities() {
		dm_width = 1;
	}

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) 

       {
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

			if (str.substr(auxPos, 1) == std::string(1, dm_delimiter))
 {
				throw "Error - There are 2 delimiters in sequence";
			}
		}

		next_pos = auxPos;

		return auxToken;
	}

	const char Utilities::getDelimiter() const {
		return dm_delimiter;
	}
	
	size_t Utilities::getFieldWidth() {
		return dm_width;
	}

	void Utilities::setDelimiter(const char d) {
		dm_delimiter = d;
	}
	
	void Utilities::setFieldWidth(size_t w) {
		dm_width = w;
	}

	};
