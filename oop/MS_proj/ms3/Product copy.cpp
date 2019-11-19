// Milestone 3
// Name: Steven Bouttarath
// Student #: 1011157188
// Course: OOP244 Winter 2019
// File: Product.cpp

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
        error = ptext;
    }
    
    bool Product::isClear() const
    {
        return !error;
    }
    
    Product::Product(char product) : type(product)
    {
        sku[0] = '\0';
        unit[0] = '\0';
        alocname = nullptr;
        current = -1;
        available = -1;
        price = -1.0;
        tax = false;
    }
    
    Product::Product(const char *p_sku, const char *p_name, const char *p_unit, double p_price, int p_current,int p_available, bool p_tax) : type('N')
    {
        if(p_sku == nullptr || p_sku[0] == '\0' || p_name == nullptr || p_name[0] =='\0' || p_unit == nullptr || p_unit[0] == '\0' || p_price < 0.0 || p_current < 0 || p_available < 0)
        {
            *this = Product();
        }
        else
        {
            strncpy(sku, p_sku, max_length_sku);
            alocname = new char[max_length_name + 1];
            strncpy(alocname, p_name, max_length_name + 1);
            strncpy(unit, p_unit, max_length_unit);
            current = p_current;
            available = p_available;
            price = p_price;
            tax = p_tax;
            
        }
    }
    
    Product::Product(const Product& copy) : Product(copy.type)
    {
        *this = copy;
    }
    
    Product::~Product()
    {
        delete [] alocname;
    }
    
    Product& Product::operator=(const Product& a)
    {
        if(this != &a)
        {
            strncpy(sku, a.sku, max_length_sku);
            delete [] alocname;
            
            if(a.alocname != nullptr)
            {
                //if(strlen(a.alocname) > max_length_name)
                //{
                alocname = new char[max_length_name + 1];
                strncpy(alocname, a.alocname, max_length_name);
                //}
            }
            else
            {
                alocname = nullptr;
            }
            
            strncpy(unit, a.unit, max_length_unit);
            current = a.current;
            available = a.available;
            price = a.price;
            tax = a.tax;
        }
        return *this;
    }
    
    int Product::operator+=(int cnt)
    {
        if (cnt > 0)
        {
            available += cnt;
            return available;
        }
        else
        {
            return available;
        }
    }
    
    bool Product::operator==(const char* s_sku) const
    {
        if (strcmp(sku, s_sku) == 0)
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
        if(strcmp(sku, s_sku) > 0)
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
        if(strcmp(alocname, product.alocname) > 0)
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
        return available;
    }
    
    
    int Product::qtyNeeded() const
    {
        return current;
    }
    
    double Product::total_cost() const
    {
        double tmp = 0;
        if(tax) {
            tmp = (price * available)*(1+tax_rate);
        } else {
            tmp = price*available;
        }
        
        return round(tmp * 100) / 100;
    }
    
    bool Product::isEmpty() const
    {
        if (available < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    const char* Product::getname() const
    {
        return alocname;
    }
    
    istream& Product::read(istream& in, bool interractive)
    {
        if(interractive == false)
        {
            in.getline(sku, max_length_sku,',');
            
            delete [] alocname;
            
            alocname = new char[max_length_name + 1];
            in.getline(alocname, max_length_name,',');
            in.getline(unit, max_length_unit,',');
            in >> price;
            in.ignore();
            in >> tax;
            in.ignore();
            in >> available;
            in.ignore();
            in >> current;
            in.ignore();
            
        }
        
        else
        {
            char tmpsku[max_length_sku + 1];
            char[max_length_name + 1];
            char tmpunit[max_length_unit + 1];
            char tmptax;
            double tmpprice;
            int tmpavailable;
            int tmpcurrent;
            
            
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
                in >> tmpavailable;
                if(in.fail() || tmpavailable < 0)
                {
                    in.setstate(ios::failbit);
                    message("Invalid Quantity Available Entry!");
                }
            }
            
            if(!in.fail())
            {
                cout << setw(max_length_label) << right << "Quantity on needed: ";
                in >> tmpcurrent;
                if(in.fail() || tmpcurrent < 0)
                {
                    in.setstate(ios::failbit);
                    message("Invalid Quantity Needed Entry!");
                }
            }
            if(!in.fail())
            {
                *this = Product(tmpsku, tmpalocname, tmpunit, tmpprice, tmpcurrent, tmpavailable, tmptax);
            }
        }
        
        in.ignore();
        
        return in;
    }
    ostream& Product::write(ostream& out, int writemode) const
    {
        if(isEmpty() || !isClear())
        {
            cout << error;
        }
        else
        {
            
            if (writemode == write_condensed)
            {
                out << type << "," << sku << ",";
                
                out << alocname << ",";
                
                out << unit << "," ;
                
                out << fixed << setprecision(2) << price << setprecision(6);
                
                out << "," << (tax?'1':'0') << "," << available << "," << current;
                
            }
            
            else if (writemode == write_table)
            {
                out << " " << setw(max_length_sku) << right
                
                out << sku << " | " << left;
                
                if(strlen(alocname) < 16)
                {
                    out << setw(16) << alocname;
                }
                
                else
                {
                    for(int i = 0; i < 13; i++)
                    {
                        out << alocname[i];
                    }
                    out << "...";
                }
                
                out << " | "
                
                out << setw(10) << unit << " | "
                
                out << right << fixed << setw(7) << setprecision(2) << price << setprecision(6)
                
                out << " | ";
                
                out.unsetf(ios::fixed);
                
                out << " | " << setw(3) << (tax ? "yes" : "no") << " | " << setw(6) << available << " | " << setw(6) << current << " | ";
            }
            
            else if (writemode == write_human)
            {
                out << right << setw(max_length_label) <<
                "Sku: " << sku << endl << setw(max_length_label) <<
                "Name: " << alocname << endl << setw(max_length_label)<<
                "Price: " << fixed << setprecision(2) << price << endl << setw(max_length_label) <<
                "Price after Tax: " << (tax ? (price * (1 + tax_rate)) : (price)) << endl << setprecision(6);
                
                out.unsetf(ios::fixed);
                
                out << setw(max_length_label) <<
                "Quantity Available: " << available << " " << unit << endl << setw(max_length_label) <<
                "Quantity Needed: " << current << " " << unit << endl;
            }
        }
        return out;
    }
}
