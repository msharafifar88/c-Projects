/*
 ============================================================================
 Name        : LVPair.h
 Author      : Mohammad Sharafifar
 Email       : msharafifar@myseneca.ca
 Student #   : 147473171
 Course Code : OOP345
 Section     : SBB
 Date        : may 29, 2019 -
 Workshop    : Workshop 3 - Lab
 ============================================================================
 */

/*
 ============================================================================
 Description :  defines a class template LVPair  for a label-value pair
 
 label and value objects that constitute LVPair object
 ============================================================================
 */

#ifndef LVPair_h
#define LVPair_h
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
namespace sict{
    
    template< typename L, typename V>
    class LVPair
    {
        
        L t_label;
        V t_value;
    public:
        
        
       // default construc
        LVPair() {}
        
        //overloaded constructor to copies the values
        LVPair(const L& label, const V& value) {
            
            t_label = label ;
            t_value = value ;
            
        }
        // display the file
        void display(std::ostream& os)const {
            
            os << t_label << " : " << t_value << std::endl;
        }
        
        
    };
    
    // a non - friend helper function that inserts into the
    // os object the LVPair object referenced in the 2nd function parameter
    template<typename L, typename V>
    std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair) {
        
        pair.display(os);
        
        return os;
    }
    
}

#endif /* LVPair_h */
