/*
 ============================================================================
 Name        : Timekeeper.cpp
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
#include <iostream>
#include <iomanip>
#include "Timekeeper.h"

namespace sict {
	//a default no-argument constructor
	Timekeeper::Timekeeper() {
	
		num_record = 0;

	}

	//The start time for the stopwatch for an event
	void Timekeeper::start() {
		start_time = std::chrono::steady_clock::now();
	}

	//The end time or stops time for the stopwatch for an event
	void Timekeeper::stop() {
		end_time = std::chrono::steady_clock::now();
	}
	//receives the address of a C-style null terminated string that holds the description of the event
	void Timekeeper::recordEvent(const char* description) {

		//calculates the duration of the event
		auto duration_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
		if (num_record < MAX_SIZE) {
			// copies current message & predefined & duration

			this->record_Struct[num_record].message = description;
			this->record_Struct[num_record].predefined = " seconds";
			this->record_Struct[num_record].duration = duration_time;
			num_record++;

		}
	}
	//inserts the titl + inserts each of the time records stored in the Timekeeper object.
	void Timekeeper::report(std::ostream& os) const {
		os << "\nExecution Times:\n";
		for (int index = 0; index < num_record; index++) {
			os << record_Struct[index].message << ' ' << std::setw(5)
				<< record_Struct[index].duration.count() / 1000000
				<< record_Struct[index].predefined
				<< std::endl;
		}
	}
}

