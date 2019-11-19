/*
 ============================================================================
 Name        : list.h
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
 Description :  defines a class template for a list of elements
 
Accumulate receives an unmodifiable reference to and L type object and allows adding values according to it. This function requires a temporary object that holds the data coming from Sales.txt/References.txt, and that can use the functions of its base. To do this, cast the current object (*this) to a reference to the base class sub-object – ((List<T, N>&)*this). It also requires a V variable that holds the result of the addition. Using List<L,V>size() and List<L,V> [] it must look through all array members; only adding, using the Summable<L,V>sum(L& label, V& variable), the values of those members whose L type is equal to the specified by the argument. Finally, this function must return the result of this operation.
 

 ============================================================================
 */


#ifndef SICT_LIST_H
#define SICT_LIST_H

#include "LVPair.h"
namespace sict
{
    
    template <typename T, size_t N>
    class List
    {
        size_t noOfElements = 0u;
        T m_ListArray[N];
    public:
        size_t size()const {
            return noOfElements;
        }
        
        const T& operator[](size_t i)const {
            
            
            return m_ListArray[i];
            
        }
        
        void operator += (const T& t) {
            
            if (noOfElements < N) {
                
                m_ListArray[noOfElements] = t;
                
                noOfElements++;
            }
        }
    };
    
    //template class
    //  Accumulate receives an unmodifiable reference to and L type object and allows adding values according to it. This function requires a temporary object that holds the data coming from Sales.txt/References.txt, and that can use the functions of its base. To do this, cast the current object (*this) to a reference to the base class sub-object – ((List<T, N>&)*this). It also requires a V variable that holds the result of the addition. Using List<L,V>size() and List<L,V> [] it must look through all array members; only adding, using the Summable<L,V>sum(L& label, V& variable), the values of those members whose L type is equal to the specified by the argument. Finally, this function must return the result of this operation.
    

    
    template<typename T, typename L, typename V, size_t N>
    
    class LVList : public List<T, N> {
        
    public:
        
        V accumulate(const L& label) const {
            //This is equal to+ LVList<T,V,L,N> SOMETHING, where T = SummableLVPair<std::string,std::string>, L = V = std::string, and N = 50.

            SummableLVPair <L, V> temp;
            V totalSum = temp.getInitialValue();
            
            for (unsigned index = 0; index < ((List<T, N>&)*this).size(); index++)
            {
                //SummableLVPair<std::string, std::string> temp.sum(label,totalSum);

                temp = ((List<T, N>&)*this)[index];
                totalSum = temp.sum(label, totalSum);
                
            }
            return totalSum;
            
        }
    };
    
}

#endif
