// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file tests in_lab section of your workshop
// Student Name: Ryeoeul Ko   Student ID: 129035176  Section: OOP244SAA
///////////////////////////////////////////////////
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {

	class Account : public iAccount {
		double i_balance;

	protected:
		double balance() const;

	public:
		Account(double balance);
		bool credit(double amount);
		bool debit(double amount);
	};
}
#endif