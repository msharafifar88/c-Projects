/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#define _CRT_SECURE_NO_WARNINGS	

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Product.h"
#include "ErrorState.h"
#include "Utilities.h"

using namespace std;

namespace ama {
	void Product::message(const char* pText) {

		error_pro = pText;


	}
	bool  Product::isClear() const {

		return (error_pro);


	}
	Product::Product(const char product_type) : pro_type(product_type) {


		pro_SKU[0] = '\0';
		pro_unit[0] = '\0';
		pro_name = nullptr;
		available_quan = 0;
		needed_quan = 0;
		proPrice = 0;
		taxable = true;




	}
	Product::Product(const char* SKU, const char* name, const char* unit, double price, int quantity, int onHandQuantity, bool tax) :pro_type('N') {
		if (name != nullptr && name[0] != '\0') {
			strncpy(pro_SKU, SKU, max_length_sku);
			pro_SKU[max_length_sku] = '\0';
			pro_name = new char[max_length_name];
			strncpy(pro_name, name, max_length_name);
			pro_name[max_length_name] = '\0';
			strncpy(pro_unit, unit, max_length_unit);
			pro_unit[max_length_unit] = '\0';
			proPrice = price;
			needed_quan = quantity;
			available_quan = onHandQuantity;
			taxable = tax;
		}
		else {
			*this = Product();
		}
	}
	Product::Product(const Product& product) : pro_type(product.pro_type) {
		strncpy(pro_SKU, product.pro_SKU, max_length_sku);
		pro_SKU[max_length_sku] = '\0';
		strncpy(pro_unit, product.pro_unit, max_length_unit);
		pro_unit[max_length_unit] = '\0';
		proPrice = product.proPrice;
		needed_quan = product.needed_quan;
		available_quan = product.available_quan;
		taxable = product.taxable;
		if (product.pro_name != nullptr && product.pro_name[0] != '\0') {
			pro_name = new char[max_length_name];
			strncpy(pro_name, product.pro_name, max_length_name);
			pro_name[max_length_name] = '\0';


		}
		else {
			pro_name = nullptr;
		}


	}
	Product::~Product() {
		
		pro_name = nullptr;

	}
	Product&  Product:: operator=(const Product& product) {
		if (this != &product) {
			strncpy(pro_SKU, product.pro_SKU, max_length_sku);
			pro_SKU[max_length_sku] = '\0';
			strncpy(pro_unit, product.pro_unit, max_length_unit);
			pro_unit[max_length_unit] = '\0';
			proPrice = product.proPrice;
			needed_quan = product.needed_quan;
			available_quan = product.available_quan;
			taxable = product.taxable;
			if (product.pro_name != nullptr) {
				pro_name = new char[max_length_name];
				strncpy(pro_name, product.pro_name, max_length_name);
				pro_name[max_length_name] = '\0';
			}
			else { pro_name = nullptr; }
		}
		return *this;

	}
	int  Product:: operator+=(int cnt) {
		if (cnt > 0) {
			available_quan += cnt;
		}
		return available_quan;
	}
	bool  Product::operator==(const char* sku) const {
		bool check;
		(strcmp(pro_SKU, sku) == 0) ? check = true : check = false;
		return check;

	}
	bool Product:: operator>(const char* sku) const {
		bool check = true;
		(strcmp(pro_SKU, sku) > 0) ? check = true : check = false;
		return check;

	}
	bool  Product::operator> (const iProduct& product) const {
		bool check;
		(strcmp(pro_name, product.name()) > 0) ? check = true : check = false;
		return check;



	}
	int  Product::qtyAvailable() const {
		return available_quan;


	}
	int  Product::qtyNeeded() const {

		return needed_quan;

	}
	double  Product::total_cost() const {
		double total;
		int cost;
		if (!taxable) {
			total = proPrice * qtyAvailable();
		}
		else {
			total = proPrice * qtyAvailable()*(1 + tax_rate);
		}
		cost = total * 100;
		total = cost;
		total = total / 100;
		return total;

	}
	bool  Product::isEmpty() const {

		return (pro_name == nullptr || pro_name[0] == '\0');


	}
	std::istream& Product::read(std::istream& in, bool interractive) {
		char sku_p[max_length_sku + 1];
		char unit_p[max_length_unit + 1];
		char name_p[max_length_name + 1];
		int q_a;
		int q_n;
		double price_p;
		char tax_p;
		bool check;

		if (interractive == false) {

			char comma;
			in.getline(sku_p, max_length_sku + 1, ',');
			in.getline(name_p, max_length_name + 1, ',');
			in.getline(unit_p, max_length_unit + 1, ',');
			in >> price_p >> comma >> check >> comma >> q_a >> comma >> q_n;

			*this = Product(sku_p, name_p, unit_p, price_p, q_n, q_a, check);
		}
		else if (interractive == true) {

			cout.setf(ios::right);
			cout.width(max_length_label);
			cout << "Sku: ";
			in >> sku_p;
			cout.width(max_length_label);
			cout << "Name (no spaces): ";
			in >> name_p;
			cout.width(max_length_label);
			cout << "Unit: ";
			in >> unit_p;
			cout.width(max_length_label);
			cout << "Taxed? (y/n): ";
			in >> tax_p;
			if (tax_p == 'y' || tax_p == 'Y') {
				check = true;
			}
			else if (tax_p == 'N' || tax_p == 'n') {
				check = false;
			}
			else {
				in.setstate(ios::failbit);
				error_pro.message("Only (Y)es or (N)o are acceptable!");

			}
			if (tax_p == 'y' || tax_p == 'Y' || tax_p == 'N' || tax_p == 'n') {
				cout.width(max_length_label);
				cout << "Price: ";
				in >> price_p;
				if (in.fail()) {
					in.setstate(ios::failbit);
					error_pro.message("Invalid Price Entry!");
				}
				else {
					cout.width(max_length_label);
					cout << "Quantity on hand: ";
					in >> q_a;
					if (in.fail()) {
						in.setstate(ios::failbit);
						error_pro.message("Invalid Quantity Available Entry!");
					}
					else {
						cout.width(max_length_label);
						cout << "Quantity needed: ";
						in >> q_n;

						if (in.fail()) {
							in.setstate(ios::failbit);
							error_pro.message("Invalid Quantity Needed Entry!");
						}
						else {
							*this = Product(sku_p, name_p, unit_p, price_p, q_n, q_a, check);
						}
					}

				}

			}
		}
		return in;
	}

	std::ostream&  Product::write(std::ostream& out, int writeMode) const {
		if (error_pro.message() != nullptr && error_pro.message()[0] != '\0') {
			out << error_pro;
		}

		else if (!isEmpty()) {
			if (writeMode == write_condensed) {
				out.setf(ios::fixed);
				out.precision(2);
				out << pro_type << "," << pro_SKU << "," << pro_name << "," << pro_unit << "," << proPrice << "," << taxable << "," << available_quan << "," << needed_quan;
			}
			else if (writeMode == write_table) {
				out << " ";
				out.setf(ios::right);
				out.width(max_length_sku);
				out << pro_SKU << " | ";
				out.unsetf(ios::right);
				out.setf(ios::left);
				if (strlen(pro_name) <= 16) {
					out.width(16);
					out << pro_name << " | ";
				}
				else {
					int i;

					for (i = 0; i < 13; i++) {
						out << pro_name[i];
					}
					out << "... | ";
				}

				out.width(10);
				out << pro_unit << " | ";
				out.unsetf(ios::left);
				out.setf(ios::right);
				out.width(7);
				out.setf(ios::fixed);
				out.precision(2);
				out << proPrice << " | ";
				out.width(3);
				if (taxable) {
					out << "yes" << " | ";
				}
				else {
					out << "no" << " | ";
				}

				out.width(6);
				out << available_quan << " | ";
				out.width(6);
				out << needed_quan << " |";
				out.unsetf(ios::right);
				
			}
			else if (writeMode == write_human) {
				out.setf(ios::right);
				out.width(max_length_label);
				out << "Sku: " << pro_SKU << endl;
				out.width(max_length_label);
				out << "Name: " << pro_name << endl;
				out.width(max_length_label);
				out.setf(ios::fixed);
				out.precision(2);
				out << "Price: " << proPrice << endl;
				out.width(max_length_label);
				out << "Price after Tax: ";
				if (!taxable) {
					out << proPrice << endl;
				}
				else {
					out << proPrice * (1 + tax_rate) << endl;
				}
				out.width(max_length_label);
				out << "Quantity Available: " << available_quan << " " << pro_unit << endl;
				out.width(max_length_label);
				out << "Quantity Needed: " << needed_quan << " " << pro_unit << endl;
			}

		}
				

		return out;
	}
	const char* Product::name() const {
		return pro_name;

	}

}

























