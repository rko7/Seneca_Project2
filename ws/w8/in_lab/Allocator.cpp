// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file tests in_lab section of your workshop
// Student Name: Ryeoeul Ko   Student ID: 129035176  Section: OOP244SAA
///////////////////////////////////////////////////
#include "SavingsAccount.h" 

namespace sict {
		const double interestRate = 0.05;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* cAccount = nullptr;
		if (type[0] == 'S') {
			cAccount = new SavingsAccount(balance, interestRate);
		}
		return cAccount;
	}
}