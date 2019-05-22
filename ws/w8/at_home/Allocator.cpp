// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_at_home.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file tests at_home section of your workshop
// Student Name: Ryeoeul Ko   Student ID: 129035176  Section: OOP244SAA
///////////////////////////////////////////////////
#include "iAccount.h"
#include "Account.h"
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {
		const double interestRate = 0.05;
		const double transFee = 0.50;
		const double monthlyFee = 2.00;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* cAccount = nullptr;
		if (type[0] == 'S') {
			cAccount = new SavingsAccount(balance, interestRate);
		}
		else if (type[0] == 'C') {
			cAccount = new ChequingAccount(balance, transFee, monthlyFee);
		}
		return cAccount;
	}
}