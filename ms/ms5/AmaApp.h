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

#ifndef AMA_AMAAPP_H
#define AMA_AMAAPP_H
#include "iProduct.h"


namespace ama {
	class AmaApp {
		char m_filename[256];
		iProduct* m_products[100];
		int m_noOfProducts;
		void pause() const;
		int menu() const;
		void loadProductRecords();
		void saveProductRecords() const;
		void listProducts() const;
		iProduct* find(const char* sku) const;
		void addQty(iProduct* product);
		void addProduct(char tag);

	public:
		AmaApp(const char *filename);
		~AmaApp();
		int run();

	};
}

#endif // !AMA_AMAAPP_H