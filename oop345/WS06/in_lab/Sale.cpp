// that receives the address of contains the name of the file holding records of iProduct type.
// Sale.cpp
// Mohammad Sharafifar
// 5/july/2019
//


#include <fstream>
#include <string>
#include <iomanip>
#include "Sale.h"
#include "Product.h"

extern int FW;
namespace sict{
    // for disply the sale I did a for loop to get all the product
    //
    void Sale::display(std::ostream & os) const {
        
        double total = 0.0;
        
        os << '\n';
        os << "Product No" << std::setw(FW) << "Cost" << std::endl;
        
        
        for (auto& i : m_products) {
            os << *i;
            os << std::fixed
            << std::setprecision(2);
            
            total += i->price();
        }
        os << std::setw(FW)
        
        << " Total" << std::setw(FW)
        << total << std::endl;
        
    }
    //to check the file exist or can be open and save tem as string
    //
    Sale::Sale(const char* filename){
        
        if (filename != nullptr && filename[0] != '\0')
        {
            std::string saler_name;
            size_t filecounter = 0;
            
            std::ifstream fs;
            fs.open(filename);
            
            if (fs.is_open()) {
                
                while (std::getline(fs, saler_name))
                    filecounter++;
                
                fs.clear();
                fs.seekg(0, std::ios::beg);
                
                for (size_t i = 0; i < filecounter; i++)
                    
                    m_products.push_back(readRecord(fs));
                
                fs.close();
            }
            else  throw "filename cannot be opened";
            
        }else  throw "filename does not exist";
    }
    
}

