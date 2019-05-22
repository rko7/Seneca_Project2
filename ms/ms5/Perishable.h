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

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include "Date.h"
#include "Product.h"

namespace ama {
	class Perishable : public Product {
		Date expiryDate;
	public:
		Perishable();
		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;
	};
}

#endif // !AMA_PERISHABLE_H
