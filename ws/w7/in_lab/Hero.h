// Workshop 7 - Derived Classes
// File w7_athome.cpp
// Version 2.0
// Date 2017/01/12
// Author       Hasan Murtaza, Chris Szalwinski
// Description
//       This file demonstrates the client module of w7
// Student Name: Ryeoeul Ko  Student ID: 129035176  Section: OOP244SAA
/////////////////////////////////////////////////////
#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

namespace sict {
	int const max_rounds = 100;
	class Hero {
		char heroName[41];
		int heroHealth;
		int heroStrength;
	public:
		Hero();
		Hero(const char* name, int health, int strength);
		void operator-=(int attack);
		bool isAlive() const;
		bool isEmpty() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !SICT_HERO_H