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

		pro_error = pText;


	}
	bool  Product::isClear() const {

		return (pro_error);


	}
	Product::Product(const char product_type) : type(product_type) {


		pro_sku[0] = '\0';
		pro_unit[0] = '\0';
		productName = nullptr;
		qntity_on_hand = 0;
		qntity_need = 0;
		pro_price = 0;
		taxStatus = true;




	}
	Product::Product(const char* SKU, const char* name, const char* unit, double price, int quantity, int onHandQuantity, bool tax) :type('N') {
		if (name != nullptr && name[0] != '\0') {
			strncpy(pro_sku, SKU, max_length_sku);
			pro_sku[max_length_sku] = '\0';
			productName = new char[max_length_name];
			strncpy(productName, name, max_length_name);
			productName[max_length_name] = '\0';
			strncpy(pro_unit, unit, max_length_unit);
			pro_unit[max_length_unit] = '\0';
			pro_price = price;
			qntity_need = quantity;
			qntity_on_hand = onHandQuantity;
			taxStatus = tax;
		}
		else {
			*this = Product();
		}
	}
	Product::Product(const Product& product) : type(product.type) {
		strncpy(pro_sku, product.pro_sku, max_length_sku);
		pro_sku[max_length_sku] = '\0';
		strncpy(pro_unit, product.pro_unit, max_length_unit);
		pro_unit[max_length_unit] = '\0';
		pro_price = product.pro_price;
		qntity_need = product.qntity_need;
		qntity_on_hand = product.qntity_on_hand;
		taxStatus = product.taxStatus;
		if (product.productName != nullptr && product.productName[0] != '\0') {
			productName = new char[max_length_name];
			strncpy(productName, product.productName, max_length_name);
			productName[max_length_name] = '\0';


		}
		else {
			productName = nullptr;
		}


	}
	Product::~Product() {
		
		productName = nullptr;

	}
	Product&  Product:: operator=(const Product& product) {
		if (this != &product) {
			strncpy(pro_sku, product.pro_sku, max_length_sku);
			pro_sku[max_length_sku] = '\0';
			strncpy(pro_unit, product.pro_unit, max_length_unit);
			pro_unit[max_length_unit] = '\0';
			pro_price = product.pro_price;
			qntity_need = product.qntity_need;
			qntity_on_hand = product.qntity_on_hand;
			taxStatus = product.taxStatus;
			if (product.productName != nullptr) {
				productName = new char[max_length_name];
				strncpy(productName, product.productName, max_length_name);
				productName[max_length_name] = '\0';
			}
			else { productName = nullptr; }
		}
		return *this;

	}
	int  Product:: operator+=(int cnt) {
		if (cnt > 0) {
			qntity_on_hand += cnt;
		}
		return qntity_on_hand;
	}
	bool  Product::operator==(const char* sku) const {
		bool check;
		(strcmp(pro_sku, sku) == 0) ? check = true : check = false;
		return check;

	}
	bool Product:: operator>(const char* sku) const {
		bool check = true;
		(strcmp(pro_sku, sku) > 0) ? check = true : check = false;
		return check;

	}
	bool  Product::operator> (const iProduct& product) const {
		bool check;
		(strcmp(productName, product.name()) > 0) ? check = true : check = false;
		return check;



	}
	int  Product::qtyAvailable() const {
		return qntity_on_hand;


	}
	int  Product::qtyNeeded() const {

		return qntity_need;

	}
	double  Product::total_cost() const {
		double total;
		int cost;
		if (!taxStatus) {
			total = pro_price * qtyAvailable();
		}
		else {
			total = pro_price * qtyAvailable()*(1 + tax_rate);
		}
		cost = total * 100;
		total = cost;
		total = total / 100;
		return total;

	}
	bool  Product::isEmpty() const {

		return (productName == nullptr || productName[0] == '\0');


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
				pro_error.message("Only (Y)es or (N)o are acceptable!");

			}
			if (tax_p == 'y' || tax_p == 'Y' || tax_p == 'N' || tax_p == 'n') {
				cout.width(max_length_label);
				cout << "Price: ";
				in >> price_p;
				if (in.fail()) {
					in.setstate(ios::failbit);
					pro_error.message("Invalid Price Entry!");
				}
				else {
					cout.width(max_length_label);
					cout << "Quantity on hand: ";
					in >> q_a;
					if (in.fail()) {
						in.setstate(ios::failbit);
						pro_error.message("Invalid Quantity Available Entry!");
					}
					else {
						cout.width(max_length_label);
						cout << "Quantity needed: ";
						in >> q_n;

						if (in.fail()) {
							in.setstate(ios::failbit);
							pro_error.message("Invalid Quantity Needed Entry!");
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
		if (pro_error.message() != nullptr && pro_error.message()[0] != '\0') {
			out << pro_error;
		}

		else if (!isEmpty()) {
			if (writeMode == write_condensed) {
				out.setf(ios::fixed);
				out.precision(2);
				out << type << "," << pro_sku << "," << productName << "," << pro_unit << "," << pro_price << "," << taxStatus << "," << qntity_on_hand << "," << qntity_need;
			}
			else if (writeMode == write_table) {
				out << " ";
				out.setf(ios::right);
				out.width(max_length_sku);
				out << pro_sku << " | ";
				out.unsetf(ios::right);
				out.setf(ios::left);
				if (strlen(productName) <= 16) {
					out.width(16);
					out << productName << " | ";
				}
				else {
					int i;

					for (i = 0; i < 13; i++) {
						out << productName[i];
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
				out << pro_price << " | ";
				out.width(3);
				if (taxStatus) {
					out << "yes" << " | ";
				}
				else {
					out << "no" << " | ";
				}

				out.width(6);
				out << qntity_on_hand << " | ";
				out.width(6);
				out << qntity_need << " |";
				out.unsetf(ios::right);
				
			}
			else if (writeMode == write_human) {
				out.setf(ios::right);
				out.width(max_length_label);
				out << "Sku: " << pro_sku << endl;
				out.width(max_length_label);
				out << "Name: " << productName << endl;
				out.width(max_length_label);
				out.setf(ios::fixed);
				out.precision(2);
				out << "Price: " << pro_price << endl;
				out.width(max_length_label);
				out << "Price after Tax: ";
				if (!taxStatus) {
					out << pro_price << endl;
				}
				else {
					out << pro_price * (1 + tax_rate) << endl;
				}
				out.width(max_length_label);
				out << "Quantity Available: " << qntity_on_hand << " " << pro_unit << endl;
				out.width(max_length_label);
				out << "Quantity Needed: " << qntity_need << " " << pro_unit << endl;
			}

		}
				

		return out;
	}
	const char* Product::name() const {
		return productName;

	}

}