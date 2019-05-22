// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file tests in_lab section of your workshop
// Student Name: Ryeoeul Ko   Student ID: 129035176  Section: OOP244SAA
///////////////////////////////////////////////////
#include "Account.h"

namespace sict {

	Account::Account(double balance) {
	//	if (balance > 0) i_balance = balance;
	//	else i_balance = 0.0;
		(balance > 0) ? i_balance = balance : i_balance = 0.0;
	}

	bool Account::credit(double amount) {
		bool valid;
		if (amount > 0) {
			i_balance += amount;
			valid = true;
		}
		else valid = false;
		return valid;
	}

	bool Account::debit(double amount) {
		bool valid;
		if (amount > 0) {
			i_balance -= amount;
			valid = true;
		}
		else valid = false;
		return valid;
	}
	
	double Account::balance() const {
		return i_balance;
	}
}