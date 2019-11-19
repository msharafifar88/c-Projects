/*
 ============================================================================
 Name        : Text.cpp
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




#include<iostream>
#include <string>
#include "Message.h"
using namespace std;

namespace sict {
    
    //Message() default constructor that will put obeject into empty state
    Message::Message() {
        
        Tweet = " ";
        UserName = " ";
        Reply = " ";
        
    }
    // Message(const std::string& ) parses string into three parts
    Message::Message(const std::string& str)
    {
        size_t strposition = 0u;
        
        if (!str.empty()) {
            
            // newly constructed string obejects initializing to empty strings
            
            string user_name = " ";
            string user_reply = "";
            string user_tweet = " ";
            
            // Saving string into tempstr obeject
            string tempstr = str;
            
            // substr will parses the string and give its username
            user_name = tempstr.substr(0, tempstr.find(" "));
            strposition = user_name.length()+1;
            
            
         
            
            // erase function of string library will erase the string after username
            tempstr.erase(0, strposition);
            
            // checking for user reply
            if (tempstr[0] == '@') {
                user_reply = tempstr.substr(1, tempstr.find(" ")-1);
                strposition = user_reply.length() + 2;
                tempstr.erase(0, strposition);
            }
            
            user_tweet = tempstr.substr(0, tempstr.npos);
            
            if (user_tweet.length() != 0) {
                
                // copying usernmae tweet and reply to actual obejects
                Tweet = user_tweet;
                UserName = user_name;
                Reply = user_reply;
                
            }
        }
    }
    
    
    // empty() function return true if obeject in safe empty state
    bool Message::empty()const {
        
        bool result = false;
        
        if (UserName.empty()  && Reply.empty() && Tweet.empty())
        {
            result = true;
        }
        return result;
    }
    
    // display(std::ostream& ) finction will display username reply and tweet
    void Message::display(std::ostream& os) const{
        
        if (!empty()) {
            
            os << ">User  : " << UserName<< "\n";
            
            if (Reply.length() > 0) {
                os << " Reply : " <<Reply<< "\n";
            }
            os << " Tweet : " << Tweet << "\n";
        }
        
        
    }
}
