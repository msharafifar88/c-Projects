/*
 ============================================================================
 Name        : taxable.h
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
 Description : Taxable that receives a value and returns
 the sum of the value with the tax on it.
 ============================================================================*/


#ifndef Taxable_H
#define Taxable_H

namespace sict {

  class Taxable
  {

    float tax_rate;

  public:

   
    Taxable(float prescribedTaxRate) {

      tax_rate = prescribedTaxRate;

    }
    
    
    float operator()(float price) const
    {

      return (1 + tax_rate) * price;

    }
  };
}
#endif 
