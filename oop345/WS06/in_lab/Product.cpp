// its a product class that get a product and the price 
// Product.cpp
// Mohammad Sharafifar
// 5/july/2019



#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Product.h"
    
    extern int FW;
    namespace sict{
        
        // default constructor
        //
        Product::Product() {
            
            num_product = 0;
            Price_product = 0.0;
            
        }
        // with 2 argoment number of product and price of product
        //
        Product::Product(int num_p, double price_p){
            
            num_product = num_p;
            Price_product = price_p ;
            
        }
        
        // price function 
        //
        
        double Product::price() const{
            return Price_product;
            
        }
        
        //display function
        //
        void Product::display(std::ostream& os) const {
            
            os << std::setw(FW)
            << num_product
            << std::setw(FW)
            << Price_product << std::endl;
        
        }
        // readRecord function
        //
        
        iProduct* readRecord(std::ifstream& file){
            iProduct* temp = nullptr;
            int p_num;
            double p_price;
            file >> p_num >> p_price;
            temp = new Product(p_num,p_price);
            
            return temp;
  
            
        }
        //operator <<
        //
        std::ostream& operator<<(std::ostream& os, const iProduct& p){
            
            p.display(os);
            return os;
            
            
        }
        
    }
