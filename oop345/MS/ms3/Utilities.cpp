// Assembly Line Project
// Utilities.cpp
// Mohammad Sharafifar
// Student ID : 143473171
// Email : msharafifar@myseneca.ca
// 2019/July/20
//

#include "Utilities.h"

namespace sict {
	static char delimiter;
	static size_t width;

    // Default Constructor
    // sets the object to a safe empty state
    //
    
	Utilities::Utilities() {
		width = 1;
	}

	/*  Extract the next token in the string & starting at the position next_pos,
        and ending immediately before the delimiter character
    */
    
	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		std::string auxStr = str.substr(next_pos);
		std::string auxToken = "";
		size_t auxPos = 0;
		bool lastField = false;

		if (auxStr.find(delimiter) < auxStr.find("\n")) {
			auxToken = auxStr.substr(0, auxStr.find(delimiter));
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

			if (str.substr(auxPos, 1) == std::string(1, delimiter)) {
				throw "Error - There are 2 delimiters in sequence";
			}
		}
		else {
			auxPos--;
		}

		next_pos = auxPos;
		return auxToken;
	}

	// Return the delimiter character
	
    
	const char Utilities::getDelimiter() const {
		return delimiter;
	}
	
	// Return the field  of the current object
	
    
	size_t Utilities::getFieldWidth() {
		return width;
	}

	// Set the delimiter character for all object of this class
	
    
	void Utilities::setDelimiter(const char d) {
		delimiter = d;
	}
	
	// Set the field width for the current object
	
    
	void Utilities::setFieldWidth(size_t w) {
		width = w;
	}

	};
