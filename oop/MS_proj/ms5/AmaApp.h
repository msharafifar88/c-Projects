/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#pragma once
#ifndef AMA_AMAAPP_H
#define AMA_AMAAPP_H

#include <iostream>
#include "Perishable.h"
#include "iProduct.h"
using namespace std;
namespace ama {
	class AmaApp {
		char m_filename[256];
		iProduct * m_products[100];
		int m_noOfProducts;

		AmaApp(const AmaApp&) = delete;
		AmaApp& operator=(const AmaApp&) = delete;
		void pause() const;
		int menu() const;
		void loadProductRecords();
		void saveProductRecords() const;
		void listProducts() const;
		iProduct* find(const char* sku) const;
		void addQty(iProduct* product);
		void addProduct(char tag);
        

	public:
		AmaApp(const char*);
		~AmaApp();
		int run();


	};
}
#endif
