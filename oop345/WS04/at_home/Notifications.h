/*
 ============================================================================
 Name        : Notifications.h
 Author      : Mohammad Sharafifar
 Email       : msharafifar@myseneca.ca
 Student #   : 147473171
 Course Code : OOP345
 Section     : SBB
 Date        : may 23, 2019 -
 Workshop    : Workshop 4 - home
 ============================================================================
 */

/*
 ============================================================================
 Description : read a String input and check the input by our condition to print them
 check massage tweet and name by using substr , find and npos
 ============================================================================*/



#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>
#include <string>
#include "Message.h"

using namespace std;

namespace sict {

	class Message;

	class Notifications {

		const Message** notification_msg_ptr = nullptr;
		int notification_elements = 0;
		int current_notification = 0;


	public:

		Notifications();
		Notifications(int);
                 size_t size() const;
		Notifications(Notifications&&);
		Notifications&& operator=(Notifications&&);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		
		
	};
	std::ostream& operator<<(std::ostream& os, Notifications& );
}



#endif 
