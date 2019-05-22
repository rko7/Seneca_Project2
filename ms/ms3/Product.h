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
/////////////////////////////////////////////////////////////////agma once
#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include "ErrorState.h"
#include <iostream>

namespace ama {
	const int max_length_label = 30;
	const int max_length_sku = 7;
	const int max_length_name = 75;
	const int max_length_unit = 10;
	const int write_condensed = 0;
	const int write_table = 1;
	const int write_human = 2;
	const double tax_rate = 0.13;
	class Product {
		const char productType;
		char productSku[max_length_sku + 1];
		char productUnitDesc[max_length_unit + 1];
		char* productName;
		int qtyOfProduct_H;
		int qtyOfProduct_N;
		double productUnitPrice;
		bool productTaxable;
		ErrorState productErrorState;
	protected:
		void message(const char* pText);
		bool isClear() const;
	public:
		Product(const char productType = 'N');
		Product(const char* pSku, const char* pName, const char* pUnit, double pPrice = 0, int pQtyN = 0, int pQtyH = 0, bool pTaxable = true);
		Product(const Product& );
		~Product();
		Product& operator=(const Product& copyProduct);
		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		bool operator>(const char* sku) const;
		bool operator>(const Product& product) const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		double total_cost() const;
		bool isEmpty() const;
		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;
	};
	
}

#endif // !AMA_PRODUCT_H