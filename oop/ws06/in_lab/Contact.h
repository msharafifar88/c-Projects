/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#ifndef CONTACT_H
#define CONTACT_H
// TODO: add namespace here
namespace sict{
    
    const int max_name_size =16;
	class Contact
	{
		char name[max_name_size +1];
		long long* phoneNumbers;
		int current_num;
        int outputNum ;
		
	public:
		
		Contact();
		Contact(const char*,const long long*, int );
		~Contact();
		void display();
		bool isEmpty() const;
	public:
		Contact(const Contact& other) = delete;
		Contact& operator=(const Contact& other) = delete;
	};
}
#endif

