// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_at_home.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file tests at_home section of your workshop
// Student Name: Ryeoeul Ko   Student ID: 129035176  Section: OOP244SAA
///////////////////////////////////////////////////
#include "Account.h"

namespace sict {
	double Account::balance() const {
		return i_balance;
	}

	//public function
	Account::Account(double bal) {
		if (bal < 0)
			i_balance = 0.0f;
		else
			i_balance = bal;
	}

	bool Account::credit(double amount) {
		bool valid = (amount > 0);
		if (valid)
			i_balance = i_balance + amount;
		return valid;
	}

	bool  Account::debit(double amount) {
		bool valid = (amount > 0 && amount <= i_balance);
		if (valid) i_balance -= amount;
		return valid;
	}
}