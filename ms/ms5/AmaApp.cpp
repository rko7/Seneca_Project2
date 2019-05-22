// Final Project Milestone 5 - ErrorState Class
// Version 3.4
// ms5_tester_prof.cpp
// Date	2019-03-09
// Author	Cornel, Chris Szalwinski, Fardad Soleimanloo
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// CS                 2017-10-11           Fall semester upgrade
// Chris              2018-03-02           Final Draft 20181
// Chris              2018-03-03           Message -> State
// Cornel             2019-03-22           Winter term update
// Studnet Name: Ryeoeul Ko  Student ID: 129035176  Section: OOP244SAA
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "AmaApp.h"
#include "Product.h"
#include "iProduct.h"
#include "Perishable.h"
#include "Utilities.h"

// Only line #1 pause doesn't work at all. Only line #1 skips pause(). So I just add a newline for it.


namespace ama {
	AmaApp::AmaApp( const char *filename) {
		
		strcpy(m_filename, filename);

		for (int i = 0; i < 100; i++) {
			this->m_products[i] = NULL;
		}
		
		this->m_noOfProducts = 0;
		this->loadProductRecords();
		
	}

	AmaApp::~AmaApp() {
		for (int i = 0; i < m_noOfProducts; i++) {
			delete m_products[i];
		}
	}
	int AmaApp::run() {
		std::cin.clear();
		int option = 0;
		do {
			option = menu();

			switch (option){

			case 1:
				listProducts();
				pause();
				std::cout << std::endl;

				break;
			case 2: {
				std::cin.clear();
				std::cin.ignore();
				std::string inputsku;
				std::cout << "Please enter the product SKU: ";
				getline(std::cin, inputsku);
				iProduct* _find = find(inputsku.c_str());
				if (_find) {

					std::cout << std::endl << *_find << std::endl;
				}
				else {
					std::cout << std::endl << "No such product!" << std::endl;
				}
				pause();
				break;
			}
			case 3:
			//	std::cin.clear();
				loadProductRecords();
				addProduct('N');
				break;
			case 4:
			//	std::cin.clear();
				loadProductRecords();
				addProduct('P');
				break;
			case 5: {
				std::cin.clear();
				std::cin.ignore();
				std::string skuinput;
				std::cout << "Please enter the product SKU: ";
				getline(std::cin, skuinput);
				iProduct* _find = find(skuinput.c_str());
				if (_find) addQty(_find);
				else {
					std::cout << std::endl << "No such product!" << std::endl << std::endl;
				}
				break;
			}
			case 6:
				//optional
				break;
			case 7:
				//optional
				break;
			case 0:
				std::cout << "Goodbye!" << std::endl;
				break;
			default:
				std::cout << "~~~Invalid selection, try again!~~~" << std::endl;
				pause();
				break;
			}
		} while (option != 0);
		
		return 0;
	}
	void AmaApp::pause() const {
		std::cin.clear();
		std::cout << "Press Enter to continue...";
		std::cin.ignore(100000, '\n');
		std::cout << std::endl;
		/*std::string enter;

		std::cout << "Press Enter to continue...";
		getline(std::cin, enter);
		std::cout << std::endl;*/
	
	}
	int AmaApp::menu() const {
		std::cin.clear();
		int option;
		std::cout << "Disaster Aid Supply Management Program" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1- List products" << std::endl;
		std::cout << "2- Search product" << std::endl;
		std::cout << "3- Add non-perishable product" << std::endl;
		std::cout << "4- Add perishable product" << std::endl;
		std::cout << "5- Add to product quantity" << std::endl;
		std::cout << "6- Delete product" << std::endl;
		std::cout << "7- Sort products" << std::endl;
		std::cout << "0- Exit program" << std::endl;
		std::cout << "> ";
		std::cin >> option;

		if (std::cin.fail() || !(option >= 0 && option <= 7)) {
			std::cin.clear();
			std::cin.ignore(2000, '\n');
			return option = -1;
		}
		else return option;
		
	}
	void AmaApp::loadProductRecords(){
		iProduct* product = nullptr;
		int index = 0;

		std::ifstream fs;
		fs.open(m_filename, std::ios::in);

		if (fs.is_open()) {
			char tag='\0';
			std::string line;

//			fs >> tag;
			while (!fs.fail()) {
				product = createInstance(tag);
				if (product) {
					m_products[index] = product;
					fs.get();
					product->read(fs, false);
					index++;
				}
				fs >> tag;
			}
			m_noOfProducts = index;
		}
	}
		
	
	void AmaApp::saveProductRecords() const {
			std::fstream fs(m_filename, std::ios::out);
			for (int i = 0; i < m_noOfProducts; i++) {
				m_products[i]->write(fs, write_condensed);
				fs << std::endl;
			}
			fs.close();
		
	}
	void AmaApp::listProducts() const {
		double total_cost = 0;
		std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << std::endl;
		std::cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << std::endl;

		for (int i = 0; i < m_noOfProducts; i++) {
			std::cout << "|" << std::fixed << std::setw(4) << i + 1 << " |";
			m_products[i]-> write(std::cout, write_table);
			std::cout << std::endl;
			total_cost += *m_products[i];
		}
		std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::right << std::setw(83) << "Total cost of support ($): | " << std::fixed << std::setw(10) << std::right << std::setprecision(2) << total_cost<< " |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	}
	iProduct * AmaApp::find(const char * sku) const {
		iProduct* _find = nullptr;
		for (int i = 0; i < m_noOfProducts; i++) {
			if(*m_products[i] == sku) _find = m_products[i];
		}
		return _find;
	}
	void AmaApp::addQty(iProduct* product) {
		int aQty;
		std::cout << std::endl;
		product->write(std::cout, write_human);
		std::cout << std::endl << std::endl;
		std::cout << "Please enter the number of purchased items: ";
		std::cin >> aQty;
		if (!std::cin.fail() && aQty >= 0) {
			std::cin.ignore(2000, '\n');
			int need = 0;
			need = (product->qtyNeeded() - product->qtyAvailable());
			if (aQty >= need) {
				int extra = 0;
				extra = (aQty - need);
				std::cout << "Too many items; only " << need << " is needed. Please return the extra " << extra << " items." << std::endl;
				*product += need;
			}
			else *product += aQty;

			saveProductRecords();
			std::cout << std::endl << "Updated!" << std::endl << std::endl;
		}
		else {
			std::cout << "Invalid quantity value!" << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore(2000, '\n');
		}

	}
	void AmaApp::addProduct(char tag) {
		if (m_noOfProducts < 100) {
			iProduct* product = createInstance(tag);
			if (product) {
				std::cin >> (*product);
				if (std::cin.fail()) {
					std::cout << std::endl << (*product) << std::endl;
					std::cin.clear();
					std::cin.ignore(2000, '\n');
				}
				else {
					std::cin.ignore(2000, '\n');
					m_products[m_noOfProducts++] = product;
					saveProductRecords();
					std::cout << std::endl << "Success!" << std::endl << std::endl;
				}
			}
		}
	}
}