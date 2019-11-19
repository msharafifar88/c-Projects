/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include <cstring>
#include <iostream>

namespace sict {
	// These number defines the output column width for a single data field

	const int COLUMN_WIDTH    = 15;
    const int max_data_value = 1000000000;
    const int smal_num_allow = 0 ;

	// max returns the largest item in data
    //
    template<typename T>
    T max (const T* data, int n){
        
       // T max = data[0];
double max = data[0];
        for (int i =1 ;i < n ; ++i)
        {
            if(max < data[i])
                max = data[i];
        }
        
        return max ;
    }

	// min returns the smallest item in data
	//
    template<typename T>
    T min(const T * data, int n)
    {
        // Initialize a max element
       // T min = data[0];
        double min = data[0];
        for (int i = 1; i < n; ++i)
        {
            if (min > data[i])
                min = data[i];
        }
        
        return min;
    }
    
	// sum returns the sum of n items in data
	//    
    template<typename T>
    T sum(const T * data, int n)
    {
        T sum = 0;
        
        for (int i = 0; i < n; ++i)
        {
            sum += data[i];
        }
        
        return sum;
    }
	// average returns the average of n items in data
	//
    template<typename T>
    double average(const T * data, int n)
    {
        return sum(data, n)/n;
    }
	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
    template<typename T>
    bool read(std::istream & input, T * data, int n)
    {
        for (int i = 0; i < n; ++i)
        {
          input.ignore();
            input >> data[i];

            if (input.fail())
            {
                return false;
            }
        }
        return true;
    }
    

   
    

	// display inserts n items of data into std::cout
	//
    template<typename T>
    void display(const char * name, const T * data, int n)
    {
        std::cout.width(20);
        std::cout << std::right << name;
        
        for(int i = 0; i < n; ++i)
        {
            std::cout.width(15);
            std::cout <<std::right  <<data[i];
        }
        std::cout << "\n";
    }

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

