/*
 ============================================================================
 Name        : MessagePack.cpp
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
 Description : In this part of code we are  receives the address of an array of Message objects
 and the number of elements in that array. If the number of messages > 0
 and the address  satisfied our condistion the we know the address is valid
 then we can  copies thos object.
 
 ============================================================================*/

#include <iostream>
#include <string>

#include "MessagePack.h"
#include "Message.h"

using namespace std;

namespace sict {
    // default constructor
    MessagePack::MessagePack() {
        msg_ptr = nullptr;
        num_element = 0u;
    }
    
    // destructor
    MessagePack::~MessagePack() {
        delete[] msg_ptr;
        msg_ptr = nullptr;
        
    }
    
    // size funcion
    
    size_t MessagePack::size() const
    {
        return size_t(num_element);
    }
    
    // two argument constructor
    
    MessagePack::MessagePack(Message** msg, int get_element)
    {
        
        if ((msg) && get_element > 0) {
            
            msg_ptr = new Message[get_element];
            
            int x = 0;
            
            for (int i = 0; i < get_element; i++)
            {
                if (!msg[i]->empty())
                {
                    msg_ptr[x] = *msg[i];
                    x++;
                }
            }
            
            num_element = x;
        }
    }
    
  
    // move constructor
    MessagePack::MessagePack(MessagePack&& rhs)
    {
        *this = std::move(rhs);
    }
    // move assignment operator
    MessagePack& MessagePack::operator=(MessagePack&& ref)
    {
        
        if (this != &ref) {
            
            delete[] msg_ptr;
            msg_ptr = ref.msg_ptr;
            num_element = ref.num_element;
            ref.msg_ptr = nullptr;
            ref.num_element= 0;
            
        }
        return *this;
    }
  
    // copy constructor
    MessagePack::MessagePack(const MessagePack& rhs) {
        *this = rhs;
    }
    // copy assignment operator
    MessagePack& MessagePack::operator=(const MessagePack& rhs) {
        if (this != &rhs) {
            delete[] msg_ptr;
            msg_ptr = new Message[rhs.num_element];
            for (size_t i = 0; i < rhs.num_element; i++) {
                msg_ptr[i] = rhs.msg_ptr[i];
            }
            num_element = rhs.num_element;
            
        }
        return *this;
    }
    
    
    
    // operator <<
    std::ostream& operator<<(std::ostream& os, const MessagePack& msg) {
        
        msg.display(os);
        return os;
     
    }
    
    // display () function
    void MessagePack::display(std::ostream& os) const
    {
    for (size_t i = 0; i < num_element; i++)
     {
        msg_ptr[i].display(os);
     }
    }
    
}
