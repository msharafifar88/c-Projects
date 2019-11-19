/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#include <iostream>
#include <cstring>
#include <string>
#ifndef ErrorState_h
#define ErrorState_h

namespace ama
{
    class ErrorState
    {
        //here
        char* msgaddress;
    public:
        explicit ErrorState(const char* mg = nullptr);
        ErrorState (const ErrorState&) = delete;
        ErrorState& operator=(const ErrorState& ) = delete;
        ~ErrorState();
        operator bool() const;
        ErrorState& operator=(const char* pText);
        void message(const char* pText);
        const char* message() const;
        
        
    };
    std:: ostream& operator<<(std::ostream&,const ErrorState&);
}
#endif // sict_ErrorState_h


