
/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include "Product.h"

using namespace std;

namespace ama
{
    void Product::message(const char *ptext)
    {
        pro_error = ptext;
    }
    
    bool Product::isClear() const
    {
        return !pro_error;
    }
    
    Product::Product(char product) : type(product)
    {
        pro_sku[0] = '\0';
        pro_unit[0] = '\0';
        productName = nullptr;
        qntity_need = -1;
        qntity_on_hand = -1;
        pro_price = -1.0;
        taxStatus = false;
    }
    
    Product::Product(const char *p_sku, const char *p_name, const char *p_unit, double p_price, int p_qntity_need,int p_qntity_on_hand, bool p_tax) : type('N')
    {
        if(p_sku == nullptr || p_sku[0] == '\0' || p_name == nullptr || p_name[0] =='\0' || p_unit == nullptr || p_unit[0] == '\0' || p_price < 0.0 || p_qntity_need < 0 || p_qntity_on_hand < 0)
        {
            *this = Product();
        }
        else
        {
            strncpy(pro_sku, p_sku, max_length_sku);
            productName = new char[max_length_name + 1];
            strncpy(productName, p_name, max_length_name + 1);
            strncpy(pro_unit, p_unit, max_length_unit);
            qntity_need = p_qntity_need;
            qntity_on_hand = p_qntity_on_hand;
            pro_price = p_price;
            taxStatus = p_tax;
            
        }
    }
    
    Product::Product(const Product& copy) : Product(copy.type)
    {
        *this = copy;
    }
    
    Product::~Product()
    {
        delete [] productName;
    }
    
    Product& Product::operator=(const Product& a)
    {
        if(this != &a)
        {
            strncpy(pro_sku, a.pro_sku, max_length_sku);
            delete [] productName;
            
            if(a.productName != nullptr)
            {
                
                productName = new char[max_length_name + 1];
                strncpy(productName, a.productName, max_length_name);
               
            }
            else
            {
                productName = nullptr;
            }
            
            strncpy(pro_unit, a.pro_unit, max_length_unit);
            qntity_need = a.qntity_need;
            qntity_on_hand = a.qntity_on_hand;
            pro_price = a.pro_price;
            taxStatus = a.taxStatus;
        }
        return *this;
    }
    
    int Product::operator+=(int cnt)
    {
        if (cnt > 0)
        {
            qntity_on_hand += cnt;
            return qntity_on_hand;
        }
        else
        {
            return qntity_on_hand;
        }
    }
    
    bool Product::operator==(const char* s_sku) const
    {
        if (strcmp(pro_sku, s_sku) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool Product::operator>(const char *s_sku) const
    {
        if(strcmp(pro_sku, s_sku) > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool Product::operator>(const Product& product) const
    {
        if(strcmp(productName, product.productName) > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int Product::qtyAvailable() const
    {
        return qntity_on_hand;
    }
    
    
    int Product::qtyNeeded() const
    {
        return qntity_need;
    }
    
    double Product::total_cost() const
    {
        double tmp = 0;
        if(taxStatus) {
            tmp = (pro_price * qntity_on_hand)*(1+tax_rate);
        } else {
            tmp = pro_price*qntity_on_hand;
        }
        
        return round(tmp * 100) / 100;
    }
    
    bool Product::isEmpty() const
    {
        if (qntity_on_hand < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    istream& Product::read(istream& in, bool interractive)
    {
        if(interractive == false)
        {
            in.getline(pro_sku, max_length_sku,',');
            
            delete [] productName;
            
            productName = new char[max_length_name + 1];
            in.getline(productName, max_length_name,',');
            in.getline(pro_unit, max_length_unit,',');
            in >> pro_price;
            in.ignore();
            in >> taxStatus;
            in.ignore();
            in >> qntity_on_hand;
            in.ignore();
            in >> qntity_need;
            in.ignore();
            
        }
        
        else
        {
            char tmpsku[max_length_sku + 1];
            char tmpalocname[max_length_name + 1];
            char tmpunit[max_length_unit + 1];
            char tmptax;
            double tmpprice;
            int tmpqntity_on_hand;
            int tmpqntity_need;
            
            
            cout << setw(max_length_label) << right << "Sku: ";
            in.getline(tmpsku, max_length_sku);
            cout << setw(max_length_label) << right << "Name (no spaces): ";
            in.getline(tmpalocname, max_length_name);
            cout << setw(max_length_label) << right << "Unit: ";
            in.getline(tmpunit, max_length_unit);
            
            cout << setw(max_length_label) << right << "Taxed? (y/n): ";
            in >> tmptax;
            
            if(tmptax != 'y' && tmptax != 'Y' && tmptax != 'n' && tmptax != 'N')
            {
                in.setstate(ios::failbit);
                message("Only (Y)es or (N)o are acceptable!");
            }
            
            if(!in.fail())
            {
                cout << setw(max_length_label) << right << "Price: ";
                in >> tmpprice;
                if(in.fail() || tmpprice < 0.0)
                {
                    in.setstate(ios::failbit);
                    message("Invalid Price Entry!");
                }
            }
            
            if(!in.fail())
            {
                cout << setw(max_length_label) << right << "Quantity on hand: ";
                in >> tmpqntity_on_hand;
                if(in.fail() || tmpqntity_on_hand < 0)
                {
                    in.setstate(ios::failbit);
                    message("Invalid Quantity Available Entry!");
                }
            }
            
            if(!in.fail())
            {
                cout << setw(max_length_label) << right << "Quantity needed: ";
                in >> tmpqntity_need;
                if(in.fail() || tmpqntity_need < 0)
                {
                    in.setstate(ios::failbit);
                    message("Invalid Quantity Needed Entry!");
                }
            }
            if(!in.fail())
            {
                *this = Product(tmpsku, tmpalocname, tmpunit, tmpprice, tmpqntity_need, tmpqntity_on_hand, tmptax);
            }
        }
        
        in.ignore();
        
        return in;
    }
    ostream& Product::write(ostream& out, int writemode) const
    {
        if(isEmpty() || !isClear())
        {
            cout << pro_error;
        }
        else
        {
            
            if (writemode == write_condensed)
            {
                out << type << "," << pro_sku << ",";
                
                out << productName << ",";
                
                out << pro_unit << "," ;
                
                out << fixed << setprecision(2) << pro_price << setprecision(6);
                
                out << "," << (taxStatus?'1':'0') << "," << qntity_on_hand << "," << qntity_need;
                
            }
            
            else if (writemode == write_table)
            {
                out << " " << setw(max_length_sku) << right;
                
                out << pro_sku << " | " << left;
                
                if(strlen(productName) < 16)
                {
                    out << setw(16) << productName;
                }
                
                else
                {
                    for(int i = 0; i < 13; i++)
                    {
                        out << productName[i];
                    }
                    out << "...";
                }
                
                out << " | " ;
                
                out << setw(10) << pro_unit << " | " ;
                
                out << right << fixed << setw(7) << setprecision(2) << pro_price << setprecision(6);
                
                out.unsetf(ios::fixed);
                
                out << " | " << setw(3) << (taxStatus ? "yes" : "no") ;
                
                out << " | " << setw(6) << qntity_on_hand << " | " ;
                
                out << setw(6) << qntity_need << " |";
            }
            
            else if (writemode == write_human)
            {
                out << right << setw(max_length_label) <<
                "Sku: " << pro_sku << endl << setw(max_length_label) <<
                "Name: " << productName << endl << setw(max_length_label)<<
                "Price: " << fixed << setprecision(2) << pro_price << endl << setw(max_length_label) <<
                "Price after Tax: " << (taxStatus ? (pro_price * (1 + tax_rate)) : (pro_price)) << endl << setprecision(6);
                
                out.unsetf(ios::fixed);
                
                out << setw(max_length_label) <<
                "Quantity Available: " << qntity_on_hand << " " << pro_unit << endl << setw(max_length_label) <<
                "Quantity Needed: " << qntity_need << " " << pro_unit << endl;
            }
        }
        return out;
    }
}

