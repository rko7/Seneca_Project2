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
/////////////////////////////////////////////////////////////////#include <iostream>
#include <iostream>
#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

namespace ama {
	class ErrorState {
		char* address;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& other) = delete;
		ErrorState& operator=(const ErrorState& other) = delete;
		virtual ~ErrorState();
		operator bool() const;
		ErrorState& operator=(const char* pText);
		void message(const char* str);
		const char* message() const;
	};
	std::ostream& operator<< (std::ostream& os, const ErrorState& es);
}

#endif // !AMA_ERRORSTATE_H
