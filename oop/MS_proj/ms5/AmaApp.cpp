/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include "AmaApp.h"
#include "iProduct.h"
#include "Perishable.h"
#include "Utilities.h"

using namespace std;
namespace ama {
	AmaApp::AmaApp(const char* filename) {
		if (filename != nullptr && filename[0] != '\0') {
			strcpy(m_filename, filename);
			for (int i = 0; i < 100; i++) {
				m_products[i] = nullptr;

			}

			m_noOfProducts = 0;
			loadProductRecords();
		}
	}
	AmaApp::~AmaApp() {
		
		for (int i = 0; i < 100; i++) {
			delete m_products[i];
			m_products[i] = nullptr;
		}

	}
	void AmaApp::pause() const {
		cout << "Press Enter to continue...";
		cin.ignore(1000, '\n');
		cout << endl;


	} 
	int AmaApp::menu() const {
		int selection;
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1- List products" << endl;
		cout << "2- Search product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to product quantity" << endl;
		cout << "6- Delete product" << endl;
		cout << "7- Sort products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> selection;
		cin.ignore(2000, '\n');
		if (selection >= 0 && selection <= 7) {


		}
		else {
			selection = -1;
		}
		return selection;
	}

	/*void AmaApp::loadProductRecords() {


		for (int i = 0; i < 100; i++) {
			delete m_products[i];
			m_products[i] = nullptr;
		}
		int index = 0;

		ifstream file(m_filename, ios::in);

		while (file.good()) {

			char id = file.get();
			file.ignore();
			if (!file.fail()) {
				if (id == 'N' || id == 'n') {
					m_products[index] = createInstance('N');
					m_products[index]->read(file, false);
					if (file.fail()) {
						file.clear();
					}
					index++;
				}
				else if (id == 'P' || id == 'p') {
					m_products[index] = createInstance('P');
					m_products[index]->read(file, false);
					if (file.fail()) {
						file.clear();
					}
					index++;
				}
			}
		}
		m_noOfProducts = index;
	}*/
	void AmaApp::loadProductRecords() {
		std::ifstream file;
		for (int i = 0; i < 100; i++) {
			delete m_products[i];
			m_products[i] = nullptr;
		}
		int index = 0;
		char tag;
		char err;

		iProduct *tmp;
		file.open(m_filename, ios::in);

		if (file.is_open()) {
			while (!file.eof()) {

				file.get(tag);
				tmp = createInstance(tag);

				if (tmp != nullptr) {
					m_products[index] = tmp;
					file.get(err);
					m_products[index]->read(file, false);

					index++;
				}

			}
		}

		m_noOfProducts = index - 1;
		file.close();

	}
	void AmaApp::saveProductRecords() const {
		std::ofstream file;
		file.open(m_filename, ios::out);
		if (file.is_open()) {
			for (int i = 0; i < m_noOfProducts; i++) {
				m_products[i]->write(file, ama::write_condensed);
				file << endl;
			}
		}
		file.close();

	}
	void AmaApp::listProducts() const {
		double total = 0;
		int i;
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl;
		cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

		for (i = 0; i < m_noOfProducts; i++) {
			cout << "|";
			cout.width(4);
			cout << i + 1 << " |";
			m_products[i]->write(cout, write_table) << endl;
		
			total += m_products[i]->total_cost();


		}
		if (i > 9 && i < 11) {
			total += 0.02;
		}
		else if (i > 10) {
			total += 0.03;
		}



		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                      Total cost of support ($): | ";
		cout.width(10);
		cout << total << " |" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl << endl;
		pause();


	}
	iProduct* AmaApp::find(const char* sku) const {
		iProduct* ptr = nullptr;
		for (int i = 0; i < m_noOfProducts; i++) {
			if (*m_products[i] == sku) {
				ptr = m_products[i];
				
			}
		}
		return ptr;

	}
	void AmaApp::addQty(iProduct* product) {
		int total;
		cout << endl << *product << endl << endl;
		cout << "Please enter the number of purchased items: ";
		cin >> total;

		if (cin.fail()) {
			cout << "Invalid quantity value!" << endl;
			cin.clear();
			cin.ignore(2000, '\n');
		}
		else {
			if (total > (product->qtyNeeded() - product->qtyAvailable())) {

				cout << "Too many items; only " << product->qtyNeeded() - product->qtyAvailable() << " is needed. Please return the extra " << total - (product->qtyNeeded() - product->qtyAvailable()) << " items." << endl;
				total = product->qtyNeeded() - product->qtyAvailable();
				*product += total;
			}

			else {
				*product += total;
			}


			cout << endl << "Updated!" << endl;
		}

	}
	void AmaApp::addProduct(char tag) {
		m_products[m_noOfProducts] = createInstance(tag);
		cin >> *m_products[m_noOfProducts];
		if (!cin.fail()) {

			m_noOfProducts++;


			saveProductRecords();
			cout << endl << "Success!" << endl << endl;
		}
		else {

			cin.clear();
			cin.ignore(2000, '\n');
			cout << endl << *m_products[m_noOfProducts] << endl << endl;

		}

	}

	int AmaApp::run() {
		iProduct *tmp;
		char sku_n[max_length_sku + 1];
		int  keeptrying = 2;
		do {
			
			switch (menu())
			{
			case 1:
				listProducts();
				break;
			case 2:
				cout << "Please enter the product SKU: ";
				cin.getline(sku_n, max_length_sku);
				tmp = find(sku_n);
				if (tmp == nullptr) {
					cout << endl << "No such product!" << endl;
				}
				else {
					cout << endl << *tmp << endl;
				}
				pause();
				break;
			case 3:
				addProduct('N');

				break;
			case 4:
				addProduct('P');

				break;
			case 5:
				cout << "Please enter the product SKU: ";
				cin.getline(sku_n, max_length_sku);
				tmp = find(sku_n);
				if (tmp == nullptr) {
					cout << endl << "No such product!" << endl;
				}
				else {
					addQty(tmp);
				}
				cout << endl;
				break;
			case 0:
				cout << "Goodbye!" << endl;
				return 0;
				break;

			default:
				cout << "~~~Invalid selection, try again!~~~" << endl;
				pause();
				break;

			}


		} while (keeptrying != 0);
			return 0;

	}
}