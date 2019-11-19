/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#pragma once
#ifndef AMA_ERROR_H
#define AMA_ERROR_H

#include <iostream>
namespace ama {

	class ErrorState {

		char * error_ms;

	public:


		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& other) = delete;
		ErrorState& operator=(const ErrorState& other) = delete;
		~ErrorState();
		operator bool() const;
		ErrorState& operator=(const char* pText);
		void message(const char* pText);
		const char* message() const;




	};
	std::ostream& operator <<(std::ostream& os, const ErrorState& errorstate);


}

#endif



