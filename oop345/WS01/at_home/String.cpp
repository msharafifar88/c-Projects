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
            int length = strlen(stringname);
            if (length > 0){
            srt_name = new char[length + 1];
			strncpy(srt_name, stringname, length);
			srt_name[length] = '\0';
           // delete[] srt_name;
            }else {length =0 ;}
		}
		else {
			srt_name = nullptr ;
		}
	}
    
    // deleted the dynamic memory
    
    String::~String(){
    
        delete[] srt_name;
        
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
