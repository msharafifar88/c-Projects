
/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


// TODO: header file guard

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict{
    
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
        int numerator ;
        int denominator;
		// TODO: declare private member functions

	public:
		// TODO: declare public member functions
        Fraction();
        Fraction(int num ,int denom);
        int max() const;
        int min() const;
        int gcd() const;
        void reduce();
        bool isEmpty() const;
        void display() const;
        
        
		// TODO: declare the + operator overload
        Fraction operator+(const Fraction& rhs) const;
        Fraction operator*(const Fraction& rhs) const;
        bool operator==(const Fraction& rhs) const;
        bool operator!=(const Fraction& rhs) const;
        Fraction& operator+=(const Fraction& rhs);
        bool Fraction_Equal(const Fraction& a, const Fraction& b) const;
        
	};
}
#endif
