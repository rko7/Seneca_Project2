// Workshop 4 - Constructors 
// Student Name: Ryeoeul Ko
// Section: OOP244SAA
// Student ID: 129035176

// TODO: add file header comments here

// TODO: add your headers here
#define _CRT_SECURE_NO_WARNINGS
#include "Traveler.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

// TODO: continue your namespace here
namespace sict {
    // TODO: implement the default constructor here
    Traveler::Traveler()
	{
		t_firstName [0] = '\0';
		t_lastName [0] = '\0';
		t_destination [0] = '\0';
		t_dyear = 0;
		t_dmonth = 0;
		t_dday = 0;
	}

    // TODO: implement the constructor with 3 parameters here
    Traveler::Traveler(const char* firstName, const char* lastName,  const char* destination)
	{
		if (firstName == nullptr || lastName == nullptr || destination == nullptr) {
			*this = Traveler();
		}
		else {
			strcpy(t_firstName, firstName);
			strcpy(t_lastName, lastName) ;
			strcpy(t_destination, destination);
			t_dyear = 2019;
			t_dmonth = 7;
			t_dday = 1;
		}
	}


   Traveler::Traveler(const char* firstName, const char* lastName, const char* destination, int dyear, int dmonth, int dday) {

		if ((firstName == nullptr) || (lastName == nullptr) || (destination == nullptr) || !(dyear >= 2019 && dyear <= 2022) || !(dmonth >= 1 && dmonth <= 12) || !(dday >= 1 && dday <= 31)||strlen(firstName)== 0|| strlen(lastName)==0|| strlen(destination)==0) {
			*this = Traveler();
		}
		else {
			strcpy(t_firstName, firstName);
			strcpy(t_lastName, lastName);
			strcpy(t_destination, destination);
			t_dyear = dyear;
			t_dmonth = dmonth;
			t_dday = dday;
		}
	}

    // TODO: implement isEmpty query here
    bool Traveler::isEmpty() const {
		bool empty;
		if ((t_firstName[0] == '\0') && (t_lastName[0] == '\0') && (t_destination[0] == '\0') && (t_dyear == 0) && (t_dmonth == 0) && (t_dday == 0)) {
			empty = true;
		}
		else {
			empty = false;
		}
		return empty;
	}

	const char* Traveler::name() const {
		if(isEmpty()){
			return " ";
		}
		else return t_firstName;
	}

	bool Traveler::canTravelWith(const Traveler& traveler) const {
		if (strcmp(t_destination, traveler.t_destination) == 0) {
			if (t_dyear == traveler.t_dyear) {
				if (t_dmonth == traveler.t_dmonth) {
					if (t_dday == traveler.t_dday) {
						return true;
					}
				}
			}
		}
	return false;
	}

    // TODO: implement display query here
	void Traveler::display() const {
		if (isEmpty()) {
		cout << "--> Not a valid traveler! <--" << endl;
		}
		else {
		cout << t_lastName << ", " << t_firstName <<" goes to " << t_destination << " on " << t_dyear << "/" << setfill('0') << setw(2) << t_dmonth << "/" << setfill('0') << setw(2) << t_dday << endl;
		}
	}
}
