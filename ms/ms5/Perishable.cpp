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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Perishable.h"
#include "iProduct.h"
#include "Date.h"
namespace ama {

	Perishable::Perishable() : Product('P') {}

	std::istream & Perishable::read(std::istream & in, bool interractive) {

		Product::read(in, interractive);
		if (interractive == true) {
			Date d;
			std::cout << std::setw(max_length_label) << std::right << "Expiry date (YYYY/MM/DD): ";
					d.read(in);
				if (d.status() == no_error) expiryDate = d;

				else {
					in.setstate(std::ios::failbit);

					if (d.status() == error_input) message("Invalid Date Entry\n");		
					else if (d.status() == error_year) message("Invalid Year in Date Entry\n");
					else if (d.status() == error_mon) message("Invalid Month in Date Entry\n");	
					else if (d.status() == error_day) message("Invalid Day in Date Entry\n");
					
				}
				


		}
		else {
		//	fflush(stdin);
			in.get();
			expiryDate.read(in);
			//std::cin.ignore(20000,'\n');
			fflush(stdin);
		}

		return in;
	}

	std::ostream & Perishable::write(std::ostream & out, int writeMode) const {

		Product::write(out, writeMode);
		if (isClear() && !isEmpty()) {
			if (writeMode == write_human) {
				out << std::right << std::setw(max_length_label) << "Expiry Date: ";
				expiryDate.write(out) << std::endl;
			}
			else if (writeMode == write_table) {
				out << " ";
				expiryDate.write(out) << " |";
			}
			else if (writeMode == write_condensed) {
				out << ",";
				expiryDate.write(out);
			}

		}
		return out;

	}

}