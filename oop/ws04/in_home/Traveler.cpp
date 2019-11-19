// TODO: add file header comments here
/**********************************************************
 * Name:			Mohammad Sharafiafar
 * Student ID:		143473171
 * Seneca email:	msharafifar@myseneca.ca
 * Section:			SHH
 **********************************************************/

// TODO: add your headers here
#include <iostream>
#include "Traveler.h"
#include <cstring>

using namespace std;
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Traveler::Traveler() {
		First_name[0] = '\0';
		Last_name[0] = '\0';
		Destinamtion[0] = '\0';
        year_dep =0;
        month_dep=0;
        day_dep=0;

	}
	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char* fname, const char* lname, const char* dest) {
		if (fname == nullptr || lname == nullptr || dest == nullptr)
		{
			*this = Traveler();
		}
		else
		{
			strcpy(First_name, fname);
			strcpy(Last_name, lname);
			strcpy(Destinamtion, dest);
            year_dep = 2019;
            month_dep = 7;
            day_dep = 1;
            
		}
	}
    Traveler:: Traveler(const char* fname, const char* lname, const char* dest,int year,int month,int day){
        
        bool yearValid = year >= 2019&& year <= 2022;
        bool monthValid = month >= 1 && month <= 12;
        bool dayValid = day >= 1 && day <= 31;
        if (fname == nullptr || lname == nullptr || dest == nullptr || !yearValid || !monthValid || !dayValid)
        {
            *this = Traveler();
        }
        else
        {
            strcpy(First_name, fname);
            strcpy(Last_name, lname);
            strcpy(Destinamtion, dest);
            year_dep = year;
            month_dep = month;
            day_dep = day;
        }
    }

	// TODO: implement isEmpty query here
	bool Traveler::isEmpty() const
	{
		if (strlen(First_name) > 0 && strlen(Last_name) > 0 && strlen(Destinamtion) > 0) {
			return false;
		}
		else
		{
			return true;
		}
		
	}

	// TODO: implement display query here
	void Traveler::display() const {

		if (First_name[0] == '\0' || Last_name[0] == '\0' || Destinamtion[0] == '\0') {
			cout << "--> Not a valid traveler! <--" << endl;

		}else
		{ 
            cout << Last_name <<", "<< First_name << " goes to " << Destinamtion <<" on ";
            
            cout.fill( '0' );
            cout.width( 2 );
            cout<<year_dep<<"/";
            cout.fill( '0' );
            cout.width( 2 );
            cout<<month_dep<<"/";
            cout.fill( '0' );
            cout.width( 2 );
            cout<<day_dep <<endl;
		}
	}


const char* Traveler::name() const{
    return First_name;
    
}
    bool Traveler::canTravelWith(const Traveler& t) const
    {
        bool day = (*this).day_dep == t.day_dep;
        bool month = (*this).month_dep == t.month_dep;
        bool year = (*this).year_dep == t.year_dep;
        bool dest = strcmp((*this).Destinamtion ,(t.Destinamtion));
        // or int dest = strcmp((*this).Destinamtion ,(t.Destinamtion));
        bool match = day && month && year && !dest/*  or dest ==0*/;
        
        return match;
    }

}
