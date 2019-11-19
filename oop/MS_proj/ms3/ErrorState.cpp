
/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ErrorState.h"

using namespace std;
namespace ama
{
	ErrorState::ErrorState(const char* errorMessage)
	{
		if (errorMessage != nullptr && errorMessage[0] != '\0')
		{
			e_message = new char[strlen(errorMessage) + 1];
			strcpy(e_message, errorMessage);
		}
		else
			e_message = nullptr;
	}

	ErrorState:: ~ErrorState()
	{
		delete[]e_message;
		e_message = nullptr;
	}

	ErrorState::operator bool() const
	{
		if (e_message != nullptr && e_message[0] != '\0')
		{
			return true;
		}
		else
			return false;

	}

	ErrorState& ErrorState::operator=(const char* pText)
	{

		delete[] e_message;
		if (pText != nullptr && pText[0] != '\0')
		{
			e_message = new char[strlen(pText) + 1];
			strcpy(e_message, pText);
		}
		else {
			e_message = nullptr;
		}
		return *this;
	}

	void ErrorState::message(const char* pText)
	{
		*this = pText;

	}

	const char* ErrorState::message() const
	{

		return e_message;

	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& es)
	{
		if (es.message() != nullptr)
		{
			os << es.message();
		}
		return os;
    }
	void ErrorState::clear()
	{
		delete[]e_message;
		e_message = nullptr;
	}
	bool ErrorState::isClear() const
	{
		if (this->e_message == nullptr)
		{
			return true;
		}
		else
			return false;
	}

}

