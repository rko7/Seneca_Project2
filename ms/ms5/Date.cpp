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

#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "Date.h"

namespace ama {
	void Date::status(int newStatus) {
		_status = newStatus;
	}
	
	int Date::mdays(int year, int mon) const { 
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 }; 
		int month = mon >= 1 && mon <= 12 ? mon : 13; 
		month--; 
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)); }
	
	Date::Date() {
		_year = 0;
		_month = 0;
		_day = 0;
		_status = no_error;
	}

	Date::Date(int year, int month, int day) {
		*this = Date();
		if (year < min_year || year > max_year){
		*this = Date();
		_status=error_year;
		}
		else if (month < 1 || month > 12)  status(error_mon);
		else if (day < 1 || day > mdays(year, month)) status(error_day);
		else status(no_error);

		if (_status == no_error) {
			_year = year;
			_month = month;
			_day = day;
		}
	}

	int Date::status(void) {
		return _status;
	}

	void Date::clearError(void) {
		status(no_error);
	}

	bool Date::isGood(void)	{
		bool result;
		if ((_status == no_error) && (_year != 0) && (_month != 0) && (_day != 0)) result = true;
		else result = false;
		return result;
	}

	Date& Date::operator+=(int days) {
		Date temp = *this;
		temp._day += days;
		if (isGood() && temp._day <= mdays(this->_year, this->_month) && temp._day > 0) this->_day = temp._day;
		else status(error_invalid_operation);
		return *this;
	}


	

	Date& Date::operator++(void) {
		if (isGood() && _day <= mdays(this->_year, this->_month)) this->_day += 1;
		else status(error_invalid_operation);
		return *this;
		}

	Date Date::operator++(int day) {
		Date temp = *this;
		++(*this);
		return temp;
	}

	Date Date::operator+(int days) {
		//Date temp = *this;
		//temp._day += days;
		//if (!(isGood()) || (temp._day > mdays(this->_year, this->_month)) || temp._day) {
		//temp.status(error_invalid_operation);
		//temp._day = this->_day;
		//}
		//return temp;
		Date temp = Date(this->_year, this->_month, this->_day);
		return temp += days;
	}

	bool Date::operator==(const Date & rhs) const {
		bool day = this->_day == rhs._day;
		bool month = this->_month == rhs._month;
		bool year = this->_year == rhs._year;

		return (day && month && year);
	}

	bool Date::operator!=(const Date & rhs) const {
		return !(*this == rhs);
	}

	bool Date::operator<(const Date & rhs) const {
		bool l_yr = this->_year < rhs._year;
		bool l_mth = this->_month < rhs._month;
		bool l_day = this->_day < rhs._day;
		bool result;
		if (l_yr) result = true;
		else if (l_mth) result = true; 
		else if (l_day) result = true;
		else result = false;
		return result;
	}

	bool Date::operator>(const Date & rhs) const{
		return !(*this < rhs) && !(*this==rhs) ;
	}

	bool Date::operator<=(const Date & rhs) const{
		return ((*this < rhs) || (*this == rhs));
	}

	bool Date::operator>=(const Date & rhs) const{
		return ((*this > rhs) || (*this == rhs));
	}

	std::istream & Date::read(std::istream & is){
		char i;
		is.clear();
		clearError();
		is >> _year >> i >> _month >> i >> _day;
		if ((is.fail())) {
			*this = Date();
			status(error_input);
		}
		else if (_year > max_year || _year < min_year) {
				*this = Date();
				status(error_year);
		}

		else if (_month > 12 || _month < 1) {
				*this = Date();
				status(error_mon);
		}

		else if (_day > mdays(_year, _month) || _day < 1) {
				*this = Date();
				status(error_day);
		}
		
		else _status = no_error;
			
	
		
			return is;
	}
		std::ostream & Date::write(std::ostream& os) const {
			if (_year == 0) {
				os << 0 << 0 << 0;
			}
			os << _year << '/';

			if (_month < 10) {
				os << 0;
			}

			os << _month << '/';

			if (_day < 10){
				os << 0;
			}

			os << _day;

			return os;
		}
	
	std::istream& operator >> (std::istream& is, Date& d) {
			return d.read(is);
		}
	std::ostream& operator<<(std::ostream& os, const Date& d) {
		return d.write(os);
	}
}
