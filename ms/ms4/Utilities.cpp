// Final Project Milestone 4 - ErrorState Class
// Version 3.4
// ms4_tester_prof.cpp
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
// Cornel             2019-03-19           Winter term update
// Studnet Name: Ryeoeul Ko  Student ID: 129035176  Section: OOP244SAA
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "iProduct.h"

namespace ama {
	double& operator+=(double& total, const iProduct& prod) {
		total += (prod.total_cost() * prod.qtyAvailable());
		return total;
	}
	std::ostream& operator<<(std::ostream& out, const iProduct& prod) {
		prod.write(out, write_human);
		return out;
	}
	std::istream& operator>>(std::istream& in, iProduct& prod) {
		prod.read(in, true);
		return in;
	}
	iProduct* createInstance(char tag) {
		if (tag == 'N' || tag == 'n') {
			Product* c_i = nullptr;
			c_i = new Product();
			return c_i;
		}
		return nullptr;
	}
}