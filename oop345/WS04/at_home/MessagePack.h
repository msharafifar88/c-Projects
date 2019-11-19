/*
 ============================================================================
 Name        : MessagePack.h
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

#include <iostream>
#include <string>

using namespace std;

namespace sict {
    class Message;
    
    class MessagePack {
        
        Message* msg_ptr = nullptr;
        size_t num_element;
        
        
    public:
        MessagePack();
        
        MessagePack(Message** , int);
        
        void display(std::ostream& os) const;
        
        size_t size() const;
        
        ~MessagePack();
        
        MessagePack& operator=(const MessagePack&);
        
        MessagePack& operator=(MessagePack&&);
        
        MessagePack(const MessagePack&);
        
        MessagePack(MessagePack&&);
        
        
        
        
        
    };
    std::ostream& operator<<(std::ostream& os, const MessagePack& rhs);
    
}

