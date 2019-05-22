// Final Project Milestone 3 - ErrorState Class
// Version 3.4
// ms2_tester_prof.cpp
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
// Cornel             2019-03-15           Winter term update
// Student Name: Ryeoeul Ko   Student Number: 129035176  Section: OOP244SAA
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Product.h"
#include "ErrorState.h"

namespace ama {
	void Product::message(const char* pText) {
		productErrorState.message(pText);
	}
	bool Product::isClear() const {
		return productErrorState ? false : true;
	}

	Product::Product(char pType) : productType(pType) {
		productSku[0] = '\0';
		productName = nullptr;
		productUnitDesc[0] = '\0';
		qtyOfProduct_H = 0;
		qtyOfProduct_N = 0;
		productUnitPrice = 0.0;
		productTaxable = false;
	}
	Product::Product(const char * pSku, const char * pName, const char * pUnit, double pPrice, int pQtyN, int pQtyH, bool pTaxable) :Product(){
		if (pName != nullptr) {
			productName = new char[strlen(pName) + 1];
			strcpy(productName, pName);

			strncpy(productSku, pSku, max_length_sku);
			if (productSku[max_length_sku] != '\0') productSku[max_length_sku] = '\0';

			strncpy(productUnitDesc, pUnit, max_length_unit);
			if (productUnitDesc[max_length_unit] != '\0') productUnitDesc[max_length_unit] = '\0';

			productUnitPrice = pPrice;
			qtyOfProduct_N = pQtyN;
			qtyOfProduct_H = pQtyH;
			productTaxable = pTaxable;
		}
		else {
			*this = Product();
		}

	}

	Product::Product(const Product& copyProduct) : productType('N'){
		productName = nullptr;
		*this = copyProduct;
	}

	Product::~Product() {
		delete[] productName;
	}

	Product& Product::operator=(const Product& copyProduct) {
		if (copyProduct.productName != nullptr) {
			productName = new (std::nothrow) char[strlen(copyProduct.productName) + 1];
			strcpy(productName, copyProduct.productName);

			strncpy(productSku, copyProduct.productSku, max_length_sku);
				if (productSku[max_length_sku] != '\0')
				productSku[max_length_sku] = '\0';

			strncpy(productUnitDesc, copyProduct.productUnitDesc, max_length_unit);
			if (productUnitDesc[max_length_unit] != '\0') 
				productUnitDesc[max_length_unit] = '\0';

			qtyOfProduct_H = copyProduct.qtyOfProduct_H;
			qtyOfProduct_N = copyProduct.qtyOfProduct_N;
			productTaxable = copyProduct.productTaxable;
			productUnitPrice = copyProduct.productUnitPrice;
		}

		else productName = nullptr;

		return *this;
	}

	int Product::operator+=(int cnt) {
		return (cnt > 0) ? (qtyOfProduct_H += cnt) : qtyOfProduct_H;
	}

	bool Product::operator==(const char* sku) const {
		return (strcmp(productSku, sku) == 0) ? true : false;
	}

	bool Product::operator>(const char* sku) const {
		return (strcmp(productSku, sku) > 0) ? true : false;
	}

	bool Product::operator>(const   Product& product) const {
		return (strcmp(productName, product.productName) > 0) ? true : false;
	}

	int Product::qtyAvailable() const {
		return qtyOfProduct_H;;
	}

	int Product::qtyNeeded() const {
		return qtyOfProduct_N;
	}

	double Product::total_cost() const {
		return productTaxable ? (productUnitPrice * (1.00 + tax_rate)) : productUnitPrice;
	}
	bool Product::isEmpty() const {
		return (productName == nullptr) ? true : false;
	}

	std::istream& Product::read(std::istream& in, bool interractive) {

		char sku[max_length_sku] = {'\0'};
		char name[max_length_name] = {'0'};
		char unit[max_length_unit] = {'0'};
		int qtyH = 0;
		int qtyN = 0;
		double price = 0.0;
		char p_tax;
		bool taxable;
		in.clear();
	
		if (interractive) {
			std::cout << std::setfill(' ') << std::setw(max_length_label) << std::right << " Sku: ";
			in >> sku;
			std::cout << std::setw(max_length_label) << " Name (no spaces): ";
			in >> name;
			std::cout << std::setw(max_length_label) << " Unit: ";
			in >> unit;
			std::cout << std::setw(max_length_label) << " Taxed? (y/n): ";
			in >> p_tax;
			if (p_tax != 'y'&& p_tax != 'Y'&& p_tax != 'n'&& p_tax != 'N') {
				in.setstate(std::ios::failbit);
				productErrorState.message("Only (Y)es or (N)o are acceptable!");
			}
			else {
				if (p_tax == 'y' || p_tax == 'Y') taxable = true;
				else if (p_tax == 'n' || p_tax == 'N')taxable = false;
			}
			if (!in.fail()) {
				std::cout << std::setw(max_length_label) << " Price: ";
				in >> price;
				if (in.fail() || price < 0) productErrorState.message("Invalid Price Entry!");
			}
			if (!in.fail()) {
				std::cout << std::setw(max_length_label) << " Quantity on hand: ";
				in >> qtyH;
				if (in.fail() || qtyH < 0) productErrorState.message("Invalid Quantity Available Entry!");
			}
			if (!in.fail()) {
				std::cout << std::setw(max_length_label) << " Quantity needed: ";
				in >> qtyN;
				if (in.fail() || qtyN < 0) productErrorState.message("Invalid Quantity Needed Entry!");
			}
			if (!in.fail()) {
				productName = new (std::nothrow) char[strlen(name) + 1];
				strcpy(productName, name);
				strncpy(productSku, sku, max_length_sku);
				productSku[max_length_sku] = '\0';
				strncpy(productUnitDesc, unit, max_length_unit);
				productUnitDesc[max_length_unit] = '\0';
				productUnitPrice = price;
				qtyOfProduct_N = qtyN;
				qtyOfProduct_H = qtyH;
				productTaxable = taxable;
			}
		}
		else {
			in.getline(sku, max_length_sku, ',');
			in.getline(name, max_length_name, ',');
			in.getline(unit, max_length_unit, ',');
			in >> price;
			in.get();
			in >> taxable;
			in.get();
			in >> qtyH;
			in.get();
			in >> qtyN;
			if (!this->productErrorState)
				*this = Product(sku, name, unit, price, qtyN, qtyH, taxable);
		}
	
		return in;
	
	}

	

	std::ostream& Product::write(std::ostream& out, int writeMode) const {
		if (isClear()) {
			if (!isEmpty()) {
				if (writeMode == write_condensed) {
					out << productType << "," << productSku << "," << productName << "," << productUnitDesc << "," << std::setprecision(2) << productUnitPrice << "," << (int)productTaxable << "," << qtyAvailable() << "," << qtyNeeded();
				}
				else if (writeMode == write_table) {
					out << " " << std::fixed << std::setprecision(2) << std::setw(max_length_sku) << std::right << productSku << " | ";
					if (strlen(productName) > 16) {
						char t_pName[14] = {'\0'};
						strncpy(t_pName, productName, 13);
						out << std::left << std::setw(13) << t_pName << "... | ";
					}
					else out << std::left << std::setw(16) << productName << " | ";
					out << std::left << std::setw(10) << productUnitDesc << " | "
						<< std::right << std::right << std::setw(7) << productUnitPrice << " | ";
					(productTaxable) ? out << std::right << std::setw(3) << "yes | " : out << std::right << std::setw(3) << "no | ";
					out << std::right << std::setw(6) << qtyAvailable() << " | "
						<< std::right << std::setw(6) << qtyNeeded() << " |";
				}
				else if (writeMode == write_human) {
					out << std::fixed << std::setprecision(2) << std::right
						<< std::right << std::setw(max_length_label) << "Sku: " << productSku << std::endl
						<< std::right << std::setw(max_length_label) << "Name: " << productName << std::endl
						<< std::right << std::setw(max_length_label) << "Price: " << productUnitPrice << std::endl;
					out << std::right << std::setw(max_length_label) << "Price after Tax: " << total_cost() << std::endl
						<< std::right << std::setw(max_length_label) << "Quantity Available: " << qtyAvailable() << " " << productUnitDesc << std::endl
						<< std::right << std::setw(max_length_label) << "Quantity Needed: " << qtyNeeded() << " " << productUnitDesc << std::endl;
				}
				
			} 
	
		} else out << productErrorState.message(); 

	return out;
	}

}

