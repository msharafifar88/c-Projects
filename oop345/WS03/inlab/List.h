/*
 ============================================================================
 Name        : list.h
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
 Description :  defines a class template for a list of elements
 ============================================================================
 */



#ifndef SICT_List_h
#define SICT_List_h

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
namespace sict
{
    
    //Design a class template List
    template <typename T ,size_t N >
    class List
    {
        //a unsigned int (size_t) keep the number of elements in the array.
        size_t num_elements = 0 ;
        T array_list[N];
        
    public:
        //returns the number of elements 
        size_t size() const {
            
            return num_elements;
        }
        //in the overloaded operator we receives an index of size_t then
        //we returns a array_list to the object
        const T& operator[](size_t i) const {
            
            return array_list[i];
        
        }
        
        //an overloaded operator receives a reference
        //to an unmodifiable object t of type T.
        void operator+=(const T& t) {
            
        if(num_elements < N)
        {
            
            array_list[num_elements] = t;
            num_elements ++;
        }
        }
        
    };
    
}

#endif /* List_h */
