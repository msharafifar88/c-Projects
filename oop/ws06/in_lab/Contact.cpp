/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include <iostream>
#include "Contact.h"
#include <cstring>
#include <iomanip>
using namespace std;
using namespace sict;
namespace sict {
    Contact::Contact(){
        //safe state 
        name[0] = '\0';
        phoneNumbers = nullptr;
        current_num = 0;
    }



    Contact::Contact(const char* cName,const long long* pNumbers, int num){
        //safe state 
        name[0] = '\0';
        phoneNumbers = nullptr;
        current_num = 0;

        //Allocate mem
        if (pNumbers != nullptr && pNumbers[0] != '\0'){
            phoneNumbers = new long long[num];
        }
        //string areaCode;
        int countryCode;
        int areaCode;
        int phoneNumber;
        int x = 0;
        if (cName != nullptr && cName[0] != '\0'){
            strncpy(name, cName, (max_name_size-1));
            name[max_name_size] = '\0';
        }

        for (int i = 0; i < num; i++){
          
            if (pNumbers[i] > 10000000000 && pNumbers[i] < 999999999999){
                countryCode = (pNumbers[i] / 10000000000);
                areaCode = ( (pNumbers[i]%10000000000) / 10000000);
                phoneNumber = pNumbers[i] % 10000000;

                if (countryCode > 0 && countryCode <= 99 &&
                    areaCode > 0 && areaCode < 999 && to_string(areaCode).length() == 3 &&
                    phoneNumber >= 1000000 && phoneNumber <= 99999999){
                        phoneNumbers[x] = pNumbers[i];
                        x++;
                    }
                }
                current_num = x;
            }
    }
    void Contact::display(){
            int countryCode;
            int areaCode;
            int phoneNumber;
            //too lazy to do math with big array numbers!!!
            //so, I just format phoneNumber itself.
            int firstPartOfPhoneNumber;
            int secondPartOfPhoneNumber;

            if (isEmpty()){
                cout << "Empty contact!" << endl;
            } else {
                //name
                 cout << name << endl;
                //formated phone number
                if (phoneNumbers != nullptr && phoneNumbers[0] != '\0'){
                    for (int j = 0; j < current_num; j++){

                        countryCode = (phoneNumbers[j] / 10000000000);
                        areaCode = ( (phoneNumbers[j]%10000000000) / 10000000);
                        phoneNumber = phoneNumbers[j] % 10000000;

                        //styling @phoneNumber
                        firstPartOfPhoneNumber = phoneNumber / 10000;
                        secondPartOfPhoneNumber = phoneNumber % 10000;

                        cout << "(+" <<  countryCode << ") " << areaCode << " " <<setfill('0') << setw(3) << firstPartOfPhoneNumber << "-" << setfill('0') << setw(4) << secondPartOfPhoneNumber << endl;
                    }
                }
            }
    }


    Contact::~Contact(){
   
        delete [] phoneNumbers;
    }

    bool Contact::isEmpty() const{
        bool empty;
        if ( name[0] == '\0' && phoneNumbers == nullptr && current_num == 0){
            empty = true;
        } else {
            empty = false;
        }

        return empty;
    }



}
