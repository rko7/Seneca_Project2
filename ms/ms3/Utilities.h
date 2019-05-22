// Final Project Milestone 3 - ErrorState Class
// Version 3.4
// ms2_tester_prof.cpp
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
// Cornel             2019-03-15           Winter term update
// Student Name: Ryeoeul Ko   Student Number: 129035176  Section: OOP244SAA
/////////////////////////////////////////////////////////////////#pragma once
#ifndef AMA_MY_PRODUCT_H
#define AMA_MY_PRODUCT_H
#include "Product.h"

namespace ama {
	double operator+=(double& total, const Product& prod);
	std::ostream& operator<<(std::ostream& out, const Product& prod);
	std::istream& operator>>(std::istream& in, Product& prod);
}
#endif