/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


// TODO: insert header files
#include <iostream>
#include <algorithm>
#include <numeric>
#include "Fraction.h"

// TODO: continue the namespace
using namespace std;
namespace sict
{
	// TODO: implement the default constructor
    Fraction::Fraction(){
        numerator =0;
        denominator=0;
    }
	// TODO: implement the two-argument constructor
    Fraction::Fraction(int num ,int denom){
        
       
        if (num >=0 && denom >0){
            numerator = num ;
            denominator = denom;
           /* Generalized sum of init and *first, *(first+1), ... *(last-1) over binary_op,
            
            where generalized sum GSUM(op, a1, ..., aN) */
            reduce();
            
        }
            else{
                *this = Fraction();
            }
        
    }
	// TODO: implement the max query
    int Fraction::max(void) const{
        return std::max(numerator, denominator);
    }
    // TODO: implement the min query
    int Fraction::min(void) const{
        return std::min(numerator, denominator);
    }
	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    void Fraction::reduce(){
        int gcd_tmp = gcd();
        numerator /= gcd_tmp;
        denominator /= gcd_tmp;
        
    }

    // TODO: implement the display query
    void Fraction::display() const
    {
        if (isEmpty())
        {
            cout << "no fraction stored";
        }
        else if (denominator == 1)
        {
            cout << numerator;
        }
        else
        {
            cout << numerator << "/" << denominator;
        }
    }
    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const {
        return (numerator == 0 && denominator ==0);
        
    }
    // TODO: implement the + operator
   Fraction Fraction::operator+(const Fraction& rhs) const
    {
        Fraction tmp(1, -1);
        if (isEmpty() == false && rhs.isEmpty() == false){
            tmp.numerator = ((numerator*rhs.denominator) + (rhs.numerator*denominator));
            tmp.denominator =(denominator*rhs.denominator);
        }
        return tmp;
    }
    
    // TODO: implement the * operator
    Fraction Fraction::operator*(const Fraction& rhs) const{
        
        
        
        Fraction temp;
        //bool valid = isValid(*this) && isValid(rhs);
        if(rhs.numerator >= 0 && rhs.denominator > 0)
           // if(numerator.(*this) >=0 &&denominator.(*this) >0)
        {
            temp.numerator = this->numerator * rhs.numerator;
            temp.denominator = this->denominator * rhs.denominator;
            return temp;
        }
        else
        {
            temp = Fraction();
            return temp;
        }
    }
    
    bool Fraction::operator==(const Fraction& rhs) const
    {
        bool valid_Fraction =rhs.numerator >= 0 && rhs.denominator > 0;
        //this->num == rhs.num & this.donomi == rhs.denomi
        bool Equal_Fractions = Fraction_Equal(*this, rhs);
            return  valid_Fraction && Equal_Fractions;
            
        
    }
    
    bool Fraction::operator!=(const Fraction& rhs) const
    {
        //bool valid_Fraction =rhs.numerator >= 0 && rhs.denominator > 0 && (*this).numerator>=0 && this->denominator >0 ;
        //(*this).num
        bool valid_Fraction = rhs.isEmpty() && this->isEmpty();
        bool not_Equal_Fractions = !Fraction_Equal(*this, rhs);
        return  valid_Fraction && not_Equal_Fractions;
        
    }
    
    Fraction& Fraction::operator+=(const Fraction& rhs)
    {
        numerator = numerator * rhs.denominator + denominator * rhs.numerator;
        denominator = denominator * rhs.denominator;
        reduce();
        return *this;
    }
    
    bool Fraction::Fraction_Equal(const Fraction& a, const Fraction& b) const
    {
        bool numer_Equal = a.numerator == b.numerator;
        bool denom_Equal = a.denominator == b.denominator;
        return numer_Equal && denom_Equal;
    }
}
