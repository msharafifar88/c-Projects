/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#pragma once

#ifndef NAMESPACE_ERROSTATE_H 
#define NAMESPACE_ERRORSATE_H 
#include <iostream>
namespace ama
{
	class ErrorState
	{
		char* e_message;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& other) = delete;
		ErrorState& operator=(const ErrorState& other) = delete;
		~ErrorState();
		operator bool() const;
		ErrorState& operator=(const char* pText);
		void message(const char* pText);
		const char* message() const;
		void clear();
		bool isClear() const;

	};
	std::ostream& operator<<(std::ostream& os, const ErrorState&);

}

#endif
