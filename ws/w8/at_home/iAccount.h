// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_at_home.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file tests at_home section of your workshop
// Student Name: Ryeoeul Ko   Student ID: 129035176  Section: OOP244SAA
///////////////////////////////////////////////////
#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__
#include <iostream>

namespace sict {
		class iAccount {

	public:
		virtual ~iAccount() {};
		virtual bool credit(double amount) = 0;
		virtual bool debit(double amount) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
	};

		iAccount* CreateAccount(const char* type, double balance);
}
#endif
