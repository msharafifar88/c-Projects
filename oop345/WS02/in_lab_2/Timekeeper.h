/*
 ============================================================================
 Name        : Timekeeper.h
 Author      : Mohammad Sharafifar
 Email       : msharafifar@myseneca.ca
 Student #   : 147473171
 Course Code : OOP345
 Section     : SBB
 Date        : may 23, 2019 -
 Workshop    : Workshop 2 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : Describe what the file does
  ============================================================================
 */


#ifndef SICT_TIMEKEEPER_H_
#define SICT_TIMEKEEPTER_H_

#include <chrono>

namespace sict {

	// maximum number of record objects
	const int MAX_SIZE = 10;

	// timekeeper class
	class Timekeeper {

		//The number records currently stored
		int num_record { 0 };

		//The start time for the current event
		std::chrono::steady_clock::time_point start_time;

		//The end time for the current event
		std::chrono::steady_clock::time_point end_time;


		struct {
			//The address of a C-style null-terminated string containing a message
			const char* message;

			//The address of a C - style null - terminated string containing a predefined
			const char* predefined;

			//The duration of the recorded event
			std::chrono::steady_clock::duration duration;
		}record_Struct[MAX_SIZE];
	public:
		//a default no-argument constructor
		Timekeeper();

		//modifier that starts the stopwatch for an event
		void start();

		//modifier that stops the stopwatch for an event
		void stop();

		//modifier that receives the address of a C-style null terminated string that holds the description of the event
		void recordEvent(const char*);

		//inserts the title “Execution Times:” into the object 
		//inserts each of the time records stored in the Timekeeper object.
		void report(std::ostream&) const;
	};
}

#endif
