

/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include<iostream>
#include<cstring>
#include "ErrorState.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace ama{
    
    ErrorState::ErrorState(const char * errorMessage )
    {
        if (errorMessage != nullptr && errorMessage[0] != '\0')
        {
         //   msgaddress = new char[strlen(errorMessage+1)];
            msgaddress = new char[strlen(errorMessage)+1];
            strcpy(msgaddress, errorMessage);
          //  msgaddress[strlen(errorMessage + 1)] = '\0';
        }
        else
        {
            msgaddress = nullptr;
        }
    }
    
    ErrorState::~ErrorState()
    {
        delete [] msgaddress;
        msgaddress = nullptr;
    }
    
    ErrorState::operator bool() const
    {
        if (msgaddress != nullptr && strlen(msgaddress) != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    ErrorState & ErrorState::operator=(const char * pText)
    {
        //ErrorState tmp(pText);
       // strncpy(msgaddress, tmp.msgaddress, (strlen(tmp.msgaddress + 1)));
        //here
       // return *this;
        
        delete[] msgaddress;
        if (pText != nullptr && pText[0] != '\0')
        {
            msgaddress = new char[strlen(pText)+1];
            strcpy(msgaddress, pText);
        }
        else {
            msgaddress = nullptr;
        }
        return *this;
    }
    
    void ErrorState::message(const char *pText)
    {
        *this = pText;
       // delete[] msgaddress;
       // msgaddress = new char[strlen(pText) + 1];
       // strcpy(msgaddress, pText);
    }
    
    const char * ErrorState::message() const
    {
        return  msgaddress;
    }
    
    ostream & operator<<(ostream & os,const ErrorState & tp)
    {
        if (tp.message() != nullptr)
        {
            os << tp.message();
        }
        
        return os;
    }
    
}

