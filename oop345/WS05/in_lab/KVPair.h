/*
 ============================================================================
 Name        : KVpair.h
 Author      : Mohammad Sharafifar
 Email       : msharafifar@myseneca.ca
 Student #   : 147473171
 Course Code : OOP345
 Section     : SBB
 Date        : may , 2019 -
 Workshop    : Workshop 5 - Lab
 ============================================================================
 */

/*
 ============================================================================
 Description : it an array of key value and value
 ============================================================================*/

#ifndef KVPair_H
#define KVPair_H

#include <iostream>
#include <iomanip>

extern int fieldWidth;

namespace sict {

  template<typename K, typename V>

  class KVPair
  {

    K m_key;
    V m_value;

  public:
    
    KVPair()
    {
        this->m_key=K();
        this->m_value=V();
    }

    //KVPair(const K& key, const V& value) constructor
    KVPair(const K& u_key, const V& u_value) {

      m_key = u_key;
      m_value = u_value;
    
    }

    // dispay function
    template<typename F>

    void display(std::ostream& os, F f) const
    {
      os << std::left << std::setw(fieldWidth) 
        << m_key << " " << ":" << " " 
        << std::right << std::setw(fieldWidth) 
        << m_value << std::setw(fieldWidth) 
        << f(m_value) << std::endl;
    }
  };


}

#endif 
