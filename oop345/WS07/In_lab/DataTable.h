// holding and processing statistical data.
// DataTable.h
// Mohammad Sharafifar
// 12/july/2019
// Chris, Szalwinski


#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

extern int FW;
extern int ND;

namespace sict
{
    template <typename T>
    class DataTable
    {
        std::vector<T> Product_Price , Product_num;
        
        int numOfRecords = 0;
        
        //private query, used to calculate and return sample standard deviation
        //
        T Sigma() const
        {
            T mean, sigma, Variance;
            std::vector<T> variation;
            
            T Mean = std::accumulate(Product_num.begin(), Product_num.end(), 0);
            mean = Mean
/ Product_num.size();
            
            for (long unsigned int i = 0; i < Product_num.size(); i++)
            {
                variation.push_back( (Product_num.at(i) - mean)*(Product_num.at(i) - mean) );
            }
            T accumulationOfVariances = std::accumulate(variation.begin(), variation.end(), 0);
            
            Variance = accumulationOfVariances / (variation.size() - 1);
            
            sigma = sqrt(Variance);
            
            return sigma;
        }
        
    public:
        
        //single argument constructor
        //
        
        DataTable(std::ifstream &obj)
        {
            std::string temp;
            
            int T_num = 0;
            double T_price = 0.0;
            
            if (obj.is_open())
            {
                while (!obj.eof() && obj.good())
                {
                    std::getline(obj, temp, '\n');
                    
                    size_t First_Space = temp.find(' ');
                    
                    T_price = std::stof(temp.substr(0, First_Space));
                    T_num = std::stof(temp.substr(First_Space, temp.length()));
                    
                    Product_Price.push_back(T_price);
                    Product_num.push_back(T_num);
                    
                    temp.clear();
                    T_num = 0;
                    T_price = 0.0f;
                    
                    numOfRecords++;
                }
            }
        }
        
        //display query, prints contents of deque to display
        //
        
        void displayData(std::ostream &os) const
        {
            int Field_Width = FW;
            int Precision = ND;
            
            if (numOfRecords == 0)
            {
                throw("ERROR: container is empty!");
            }
            else
            {
                os << "Data Values" << "\n------------" << std::endl;
                
                os << std::right << std::fixed
                << std::setw(Field_Width)
                << "x"
                << std::setw(Field_Width)
                << "y"
                << std::endl;
                
                for (int i = 0; i < numOfRecords; i++)
                {
                    os << std::right << std::fixed
                    << std::setw(Field_Width)
                    << std::setprecision(Precision) << Product_Price.at(i)
                    << std::setw(Field_Width)
                    << std::setprecision(Precision) << Product_num.at(i)
                    << std::endl;
                }
            }
        }
        
        //display query, displays the calculated statistics of the object's values
        //
        
        void displayStatistics(std::ostream &os) const
        {
            int Field_Width = FW;
            int Precision = ND;
            
            T Mean = std::accumulate(Product_num.begin(), Product_num.end(), 0);
            
            os << "\nStatistics" << "\n----------" << std::endl;
            
            os << std::right << std::fixed
            << std::setw(Field_Width + 1)
            << "y mean "
            << std::setw(4)
            << "="
            << std::right << std::fixed << std::setw(Field_Width+1)
            << std::setprecision(Precision) << Mean / Product_num.size()
            << std::endl;
            
            os << std::right << std::fixed
            << std::setw(Field_Width + 1)
            << "y sigma"
            << std::setw(4)
            << "="
            << std::right << std::fixed << std::setw(Field_Width +1)
            << std::setprecision(Precision) << Sigma()
            << std::endl;
        }
    };
}

#endif //SICT_DATA_TABLE_H
