/*
 ============================================================================
 Name        : LVP.h
 Author      : Mohammad Sharafifar
 Email       : msharafifar@myseneca.ca
 Student #   : 147473171
 Course Code : OOP345
 Section     : SBB
 Date        : Jun 2, 2019 -
 Workshop    : Workshop 3 - home
 ============================================================================
 */

/*
 ============================================================================
 Description :   Constructor that receives 2 arguments, unmodifiable reference to an L and V types, and then passes the argument to the Base constructor. It changes the size of the output field only if the submitted L type is bigger than the minimum field width. This function assumes that the L type has a member function named size().

 ============================================================================
 */
#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>
#include <fstream>
#include <string>
namespace sict
{
    
    template<typename L, typename V>
    
    class LVPair
    {
        L t_label;
        V t_value;
        
    public:
        
        //  default constructor
        LVPair() {};
        
        // two parameterized constructor
        //overloaded constructor to copies the values
        LVPair(const L& label, const V& value) :
        
        t_label(label), t_value(value) {};
        
        L getLabel() {
            
            return t_label;
        }
        
        V getValue() {
            
            return t_value;
            
        }
        
        // display function
        
        virtual void display(std::ostream& os)const {
            
            os << t_label << " : " << t_value << "\n";
        }
    };
    
    
    //function operator <<
    template <typename L, typename V>
    
    std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
    {
        pair.display(os);
        return os;
    }
    
    
    //class template SummableLVPair
    template <typename L, typename V>
    class SummableLVPair : public LVPair<L, V>
    {
        
        static V summation;
        static size_t min_width;
        
    public:
        
        SummableLVPair()
        {
            
        };
        
        //2-argument constructor SummableLVPair(const L& label, const V& value)
        //unmodifiable reference to an L and V types, and then passes the argument to the Base constructor. It changes the size of the output field only if the submitted L type is bigger than the minimum field width. This function assumes that the L type has a member function named size().

        SummableLVPair(const L& label, const V& value) : LVPair<L, V>(label, value) {
            
            if (min_width < label.size())
            {
                min_width = label.size();
            }
        }
        
        // getInitialValue() will return initial value of summation
        const V& getInitialValue()
        {
            return summation;
        }
        
        // sum(const L& label, const V& sum) this query receives two unmodifiable references
        //Function that receives 2 unmodifiable references, one to a L tyoe and another to a V type. This function returns the addition of the V value of the current object and the V parameter. TO DO THIS, IT MUST BE DEFINED 2 EXTRA QUERIES, FOR GETTING VALUE AND LABEL BECAUSE THOSE VAR ARE PRIVATE
        
        V sum(const L& label, const V& sum) const
        {
            
            V totalSum = sum;
            
            if (label == ((LVPair<L, V>&)*this).getLabel())
            {
                
                totalSum = ((LVPair<L, V>&)*this).getValue() + sum;
                
            }
            return totalSum;
        }
        
        // display will insert into the std::ostream object
        //    This function formatted the output by setting the std::ostream object to left-justified insertion and a field width equal to the minimum field width, before calling the display() function of its base.

        void display(std::ostream& os) const {
            
            os.width(min_width);
            
            os << std::left;
            
            LVPair<L, V>::display(os);
            
        }
    };
    
    template<typename L, typename V>
    
    // template declaration that initialize field width clas to 0
    

    size_t SummableLVPair  <L, V>::min_width {0};
    
    //template Specializations
    template <>
    
    // initialize the starting value to 0
    int SummableLVPair <std::string, int>::summation{0};
    
    // template specialization
    template <>
    
    // initialize the starting value to empty string
    std::string SummableLVPair <std::string, std::string>::summation{""};
    
    
    template <>
    //This is equal to+ LVList<T,V,L,N> SOMETHING, where T = SummableLVPair<std::string,std::string>, L = V = std::string, and N = 50.

    SummableLVPair <std::string, int>::SummableLVPair(const std::string& label, const int& value) : LVPair<std::string, int>(label, value)
    {
        if (min_width < label.size())
        {
            
            min_width = label.size();
        }
    }
    
    template<>
    SummableLVPair<std::string, std::string>::SummableLVPair(const std::string& label, const std::string& value) : LVPair<std::string, std::string>(label, value) {
        if (min_width < label.size()) {
            min_width = label.size();
        }
    }
    
    template<>
    std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& sum) const
    {
        
        std::string totalSum = sum;
        
        //SummableLVPair<std::string, std::string> AUX(label,reference);

        if (label == ((LVPair<std::string, std::string>&)*this).getLabel())  // i took help in this line from internet 
        {
            
            totalSum = sum + ' ' + ((LVPair<std::string, std::string>&)*this).getValue(); // i also took help in this line
            
        }
        return totalSum;
    }
   
  /*  template<>
    std::string SummableLVPair<std::string, std::string>::sum(const std::string& l, const std::string& s) const {
        return (s + " " + LVPair<std::string, std::string>::getValue());

*/
    
}
#endif
