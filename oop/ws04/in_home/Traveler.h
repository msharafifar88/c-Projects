

// TODO: add file header comments here

/**********************************************************
 * Name:			Mohammad Sharafiafar
 * Student ID:		143473171
 * Seneca email:	msharafifar@myseneca.ca
 * Section:			SHH
 **********************************************************/

// TODO: add header file guard here

#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

// TODO: declare your namespace here
namespace sict {
	// TODO: define the constants here
	const int max_destination_size = 32;
	const int max_name_size = 16;
	// TODO: define the Traveler class here
	class Traveler {

	private:

		char First_name[max_name_size + 1];
		char Last_name[max_name_size + 1];
		char Destinamtion[max_destination_size +1];
        int year_dep;
        int month_dep;
        int day_dep;
	public:
		Traveler();
		Traveler(const char* , const char* , const char* );
        Traveler(const char* , const char* , const char* ,int,int,int);
		bool isEmpty() const;
		void display() const;
        const char* name() const;
        bool canTravelWith(const Traveler&) const;

	};
}
#endif
