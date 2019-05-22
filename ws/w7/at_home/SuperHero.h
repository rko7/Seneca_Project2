// Workshop 7 - Derived Classes
// File w7_athome.cpp
// Version 2.0
// Date 2017/01/12
// Author       Hasan Murtaza, Chris Szalwinski
// Description
//       This file demonstrates the client module of w7
// Student Name: Ryeoeul Ko  Student ID: 129035176  Section: OOP244SAA
/////////////////////////////////////////////////////ragma once
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {
	class SuperHero : public Hero {
		int super_bonus;
		int super_defend;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int strength, int bonus, int defend);
		bool isEmpty() const;
		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif // !SICT_HERO_H