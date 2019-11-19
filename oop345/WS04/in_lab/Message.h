//
//  Message.hpp
//  mm
//
//  Created by Saam on 6/7/19.
//  Copyright © 2019 Saam. All rights reserved.
//



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
        
    };
}


#endif /* Message_h */
