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
#include <cstring>
#include <iostream>
#include "ErrorState.h"

namespace ama {
	ErrorState::ErrorState(const char* errorMessage) {
		address = nullptr;
		if (errorMessage == nullptr || errorMessage[0] == '\0') errorMessage = nullptr;
		else message(errorMessage);
	}
	ErrorState::~ErrorState() {
		delete[] address;
	}
	ErrorState::operator bool() const {
		return (message() != nullptr) ? true : false;
	}
	ErrorState & ErrorState::operator=(const char * pText) {
		if (pText == nullptr)
			address = nullptr;
		else if (pText[0] == '\0')
			address = nullptr;
		else {
			address = new char[strlen(pText) + 1];
			strcpy(address, pText);
		}
		return *this;
	}
	void ErrorState::message(const char* pText) {
		operator=(pText);
	}
	const char* ErrorState::message() const {
		return address;
	}
	std::ostream& operator<< (std::ostream& os, const ErrorState& es) {
		if (es.message() == nullptr) os << "";
		else os << es.message();
		return os;
	}
}