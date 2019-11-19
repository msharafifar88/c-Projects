/*
 ============================================================================
 Name        : Message.h
 Author      : Mohammad Sharafifar
 Email       : msharafifar@myseneca.ca
 Student #   : 147473171
 Course Code : OOP345
 Section     : SBB
 Date        : may 23, 2019 -
 Workshop    : Workshop 4 - Lab
 ============================================================================
 */

/*
 ============================================================================
 Description : read a String input and check the input by our condition to print them
 check massage tweet and name by using substr , find and npos
 ============================================================================*/


#ifndef  SICT_MESSAGE_H
#define  SICT_MESSAGE_H

#include<string>
#include<iostream>

using namespace std;

namespace sict {
    
    class Message {
        
          //or char
        string UserName;
        string Reply;
        string Tweet;
      
        
    public:
        
        Message();
        Message(const std::string&);
        bool empty() const;
        void display(std::ostream& os)const;
        
        
        // in at home part
        
        std::string getUser() const;
        
        std::string getReply() const;
        
        std::string getTweet() const;
    };
}


#endif /* Message_h */
