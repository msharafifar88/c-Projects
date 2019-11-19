/*
 ============================================================================
 Name        : Notifications.cpp
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
 Description :In this part of code we are modifier that receives a reference
 to an unmodifiable Message object.
 If the object is not empty and the current object
 has room to store an address to a Message object we save the address
 but if the current address existed we are removed it.
 ============================================================================*/



#include <iostream>
#include <string>
#include "Notifications.h"

using namespace std;

namespace sict {

	// default constructor
	Notifications::Notifications() {
		notification_msg_ptr = nullptr;
		notification_elements = 0;
		current_notification = 0;
	}

	// one argument constructor
	Notifications::Notifications(int num_elem) {
		if (num_elem > 0) {
			notification_msg_ptr = new const Message*[num_elem];
			notification_elements = num_elem;
		}
		else {
			*this = Notifications();
		}
	}

	//  move constructor
	Notifications::Notifications(Notifications&& rhs) {
		*this = std::move(rhs);
		rhs.notification_msg_ptr = nullptr;
	}

	//move assignment operator
	Notifications&& Notifications::operator=(Notifications&& rhs) {

		if (this != &rhs)
		{

			current_notification = rhs.current_notification;
			notification_msg_ptr = rhs.notification_msg_ptr;
			rhs.notification_msg_ptr = nullptr;
			rhs.current_notification = 0;
		}
		return std::move(*this);
	}


	// operator += for Notification module
	Notifications& Notifications::operator+=(const Message& msg)
	
	{
		if (!msg.empty() && notification_elements	> 0)
		{
			notification_msg_ptr[current_notification++] = &msg;
		}
		return *this;
	}

	//Notification -= operator
	Notifications& Notifications::operator-=(const Message& msg) {

		bool check = false;
		

		for (int i = 0; i < notification_elements && !check; i++)
		{
			if (notification_msg_ptr[i] == &msg) {
				check = true;
			}
			if (check)
			{

				for (int i = 0; i < current_notification; i++) {
					if (i < notification_elements)
						notification_msg_ptr[i] = notification_msg_ptr[i + 1];
					else
						notification_msg_ptr[current_notification] = nullptr;
				}

				current_notification--;
			}
		}
		return *this;
	}

	// size function
	size_t Notifications::size() const 
	{
		return current_notification;
	}

	// operator <<

	std::ostream& operator<<(std::ostream& os, Notifications& msgNot) {
		msgNot.display(os);
		return os;
	}
	// display function
    
    void Notifications::display(std::ostream& os) const
    {
        for (int i = 0; i < current_notification; i++)
            (*notification_msg_ptr[i]).display(os);
    }
   

}
