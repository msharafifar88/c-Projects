/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS	

#include <iostream>
#include<cstring>
#include"ErrorState.h"

using namespace std;

namespace ama {

	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage == nullptr || errorMessage[0] == '\0') {
			error_ms = nullptr;
		}
		else {
			int i;
			for (i = 0; errorMessage[i] != '\0'; i++) 
			{ 

			}
			error_ms = new char[i + 1];
			strncpy(error_ms, errorMessage, i);
			error_ms[i] = '\0';
		}
	}

	ErrorState::~ErrorState() {
		delete[] error_ms;
		error_ms = nullptr;
	}
	ErrorState::operator bool() const {
		return error_ms != nullptr;
	}
	ErrorState& ErrorState::operator=(const char* pText) {
		delete[] error_ms;
		if (pText == nullptr || pText[0] == '\0') {
			error_ms = nullptr;
		}
		else {
			int i;
			for (i = 0; pText[i] != '\0'; i++) {

			}
			error_ms = new char[i + 1];
			strncpy(error_ms, pText, i);
			error_ms[i] = '\0';
		}

		return *this;
	}
	void ErrorState::message(const char* pText) {
		*this = pText;
	}
	const char* ErrorState::message() const {
		return error_ms;
	}
	std::ostream& operator<<(std::ostream& os, const ErrorState& error) {
		if (error) 
		{
			cout << error.message();
		}
		return os;
	}


}