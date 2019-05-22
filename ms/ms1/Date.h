// Final Project - Milestone 1
// Version 3.4
// Date 2018/03/11
// Authors:     Chris Szalwinski, Fardad Soleimanloo
// Student Name: Ryeoeul Ko   Student ID: 129035176   Section: OOP244SAA
// Date: 2019/03/09
#include <iostream>

#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace ama {
	int const min_year = 2019;
	int const max_year = 2028;
	int const no_error = 0;
	int const error_year = 1;
	int const error_mon = 2;
	int const error_day = 3;
	int const error_invalid_operation = 4;
	int const error_input = 5;

	class Date {
		int _year;
		int _month;
		int _day;
		int _status;
		void status(int newStatus);
		int mdays(int year, int mon)const;

	public:
		Date();
		Date(int year, int month, int day);
		int status(void);
		void clearError(void);
		bool isGood(void);
		Date& operator+=(int days);
		Date& operator++(void);
		Date operator++(int);
		Date operator+(int days);
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os) const;
	};

	std::ostream& operator<< (std::ostream& os, const Date&);
	std::istream& operator>> (std::istream& is, Date&);
}
#endif