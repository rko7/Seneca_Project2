// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_at_home.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file tests at_home section of your workshop
// Student Name: Ryeoeul Ko   Student ID: 129035176  Section: OOP244SAA
///////////////////////////////////////////////////
#include <iomanip>
#include "SavingsAccount.h"

namespace sict {
	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account::Account(balance) {
	//	if (interestRate > 0) interest = interestRate;
	//	else interest = 0.0;
		(interestRate > 0) ? interest = interestRate : interest = 0.0;
	}

	void SavingsAccount::monthEnd() {
		double s_interest = (Account::balance()*interest);
		credit(s_interest);
	}

	void SavingsAccount::display(std::ostream& out) const {
		out << "Account type: Savings" << std::endl;
		out.setf(out.fixed, out.floatfield);
		out.precision(2);
		out << "Balance: $" << Account::balance() << std::endl;
		out << "Interest Rate (%): " << interest * 100 << std::endl;
	}

}