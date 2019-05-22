// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_at_home.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file tests at_home section of your workshop
// Student Name: Ryeoeul Ko   Student ID: 129035176  Section: OOP244SAA
///////////////////////////////////////////////////
#include "ChequingAccount.h"

using namespace std;

namespace sict {

	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) : Account::Account(balance) {
		(transFee > 0) ? transaction = transFee : transaction = 0.0;
		(monthlyFee > 0) ? monthly = monthlyFee : monthly = 0.0;
	}
	bool ChequingAccount::credit(double amount) {
		bool valid = (amount > 0 && Account::balance() >= transaction);
		if (valid) {
			Account::credit(amount);
			Account::debit(transaction);
		}
		return valid;
	
	}
	bool ChequingAccount::debit(double amount) {
		bool valid = (amount > 0 && (amount + transaction) <= Account::balance());
		if (valid)
			Account::debit(amount + transaction);
		return valid;
	}
	void ChequingAccount::monthEnd() {
		Account::debit(monthly);
	}
	void ChequingAccount::display(std::ostream & out) const {
		out << "Account type: Chequing" << std::endl;
		out	<< "Balance: $";
		out.setf(out.fixed, out.floatfield);
		out.precision(2);
		out << Account::balance() << std::endl;
		out<< "Per Transaction Fee: " << transaction << std::endl;
		out<< "Monthly Fee: " << monthly << std::endl;
	}
}






