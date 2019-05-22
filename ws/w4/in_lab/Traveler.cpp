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
using namespace std;

// TODO: continue your namespace here
namespace sict {
    // TODO: implement the default constructor here
    Traveler::Traveler()
	{
		t_firstName [0] = '\0';
		t_lastName [0] = '\0';
		t_destination [0] = '\0';
	}

    // TODO: implement the constructor with 3 parameters here
    Traveler::Traveler(const char* firstName, const char* lastName,  const char* destination)
	{
		if (firstName == nullptr || lastName == nullptr || destination == nullptr) {
			*this = Traveler();
		}
		else {
			strcpy(t_firstName, firstName);
			strcpy(t_lastName, lastName);
			strcpy(t_destination, destination);
		}
	}

    // TODO: implement isEmpty query here
    bool Traveler::isEmpty() const {
		bool empty;
		if ((t_firstName[0] == '\0') || (t_lastName[0] == '\0')||(t_destination[0] == '\0')) {
			empty = true;
		}
		else {
			empty = false;
		}
		return empty;
	}
    // TODO: implement display query here
	void Traveler::display() const {
		if (isEmpty()) {
		cout << "--> Not a valid traveler! <--" << endl;
		}
		else {
		cout << t_firstName << " " << t_lastName <<" goes to " << t_destination << endl;
		}
	}
}
