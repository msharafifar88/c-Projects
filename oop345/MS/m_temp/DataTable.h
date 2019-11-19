
//Mohammad Sharafifar
//143473171

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H
#include <iostream>
#include <fstream>
#include <math.h>
#include<algorithm>
#include<string>
#include<numeric>
#include<functional>
#include<vector>
#include<iomanip>
extern int FW;
extern  int ND;
int FT = 9;

namespace sict {
    // A class that is for holding and processing statistical data
    //
	template<typename T>
	class DataTable {
		int numberoflines=0;
		std::vector<T> x;
		std::vector<T> y;
		T m = 0;
 	public:
        
        //method that calculates the sum of the X and Y coordinates
        //
        
		DataTable(std::ifstream& file) {
			
			T x_;
			T y_;
			std::string auxxx;
			while (std::getline(file,auxxx))
			{
				++numberoflines;
			}

			file.clear();
			file.seekg(0, std::ios::beg);
			for (int i = 0; i < numberoflines; i++)
			{
				file >> x_ >> y_;
				if (file) {
					x.push_back(x_);
					y.push_back(y_);
				}
			}
			file.close();
			
			std::vector<T> pTemp = y;
			std::sort(pTemp.begin(), pTemp.end());

			m = pTemp[pTemp.size() / 2];
		};
        
        
        // a query that displays the x-y data in the format described in the workshop
        
        void displayData(std::ostream& os)const {
			os << "Data values" << std::endl;
			os << "------------" << std::endl;
			os << std::right << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;
			for (size_t i = 0u; i < x.size(); i++)
			{
				os << std::right << std::setw(FW) << std::fixed << std::setprecision(4) << x[i]<< std::setw(FW) << y[i]<< std::endl;
			}
			os<<std::endl;
		};
        
        
        //a query that displays the statistics for the current
        //object in the format described in the workshop
        //updated to display median, slope and intercept
        
        
		void displayStatistics(std::ostream& os)const {
			os << "\nStatistics" << "\n" << "-----------" << std::endl;
			os <<std::left<<std::setw(FW+2) << "y mean" <<"="<< std::right<<std::setw(FW)<< std::fixed << std::setprecision(4) << mean(y) << std::endl;
			os << std::left << std::setw(FW+2) <<"y sigma" << "=" << std::right << std::setw(FW) << std::fixed << std::setprecision(4) << sigma(y)<<std::endl;
			os << std::left << std::setw(FW + 2) << "y median" << "=" << std::right << std::setw(FW) << std::fixed << std::setprecision(4) << m << std::endl;
			os  << std::left << std::setw(FW+2) << "slope" << "=" << std::right << std::setw(FW) << std::fixed << std::setprecision(4) << slope(x, y) << std::endl;
			os << std::left << std::setw(FW+2) << "intercept" << "=" << std::right << std::setw(FW) << std::fixed << std::setprecision(4) << intercept(x,y) << std::endl;

		};
        
        // mean = sum of all the integers on the Y/ num of integers on the Y
        //
		T& mean(const std::vector<T>& var)const {
			T aux = T();
			aux = std::accumulate(var.begin(), var.end(), (T) 0) / static_cast<T>(this->numberoflines);
			aux = 10000 * aux;
			aux = round(aux);
			aux = aux / 10000;
			
			return std::ref(aux);

		}

        //  method that calculates the sample standard deviation
        //
        
		T& sigma(const std::vector<T>& var)const {
			T avg = mean(var);
			std::vector<T> temp(var.size(), avg);
			T output = std::inner_product(var.begin(), var.end(), temp.begin(),(T)0, std::plus<T>(), [](T X, T Y) {return pow((X - Y), 2); });
			T aux = sqrt(output / (static_cast<T>(this->numberoflines - 1)));
			aux = 10000 * aux;
			aux = round(aux);
			aux = aux / 10000;
			return std::ref(aux);

		}
        
        //slope function
        //
        
		T& slope(const std::vector<T>& var1, const std::vector<T>& var2)const {
			T temp1,temp2,temp3,temp4,aux= T();

			std::vector<T> tempvector(numberoflines,0);
			temp1 = std::inner_product(var1.begin(), var1.end(), var2.begin(), (T)0);
			temp2 = std::accumulate(var1.begin(), var1.end(), (T)0);
			temp4 = std::accumulate(var2.begin(),var2.end(),(T)0);	
			std::transform(var1.begin(), var1.end(), tempvector.begin(), [](T i) {return pow(i, 2); });
			temp3 = std::accumulate(tempvector.begin(), tempvector.end(), (T)0);
			
			aux = ((numberoflines*temp1)-(temp2*temp4))/(numberoflines*temp3-(pow(temp2,2)));
			aux = 10000 * aux;
			aux = round(aux);
			aux = aux / 10000;
			return std::ref(aux);
		}
        //intercept function
        //
        
		T& intercept(const std::vector<T>& var1,const std::vector<T>& var2)const {
			T temp1, temp2, temp3,aux = T();
			temp1 = std::accumulate(var2.begin(), var2.end(), (T)0);
			temp2 = std::accumulate(var1.begin(), var1.end(), (T)0);
			temp3 = slope(var1, var2);
			aux = (temp1 - temp3 * temp2) / numberoflines;
			aux = 10000 * aux;
			aux = round(aux);
			aux = aux / 10000;
			return std::ref(aux - 0.0001);

		}

	};

}
#endif 
