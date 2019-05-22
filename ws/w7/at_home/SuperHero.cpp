// Workshop 7 - Derived Classes
// File w7_athome.cpp
// Version 2.0
// Date 2017/01/12
// Author       Hasan Murtaza, Chris Szalwinski
// Description
//       This file demonstrates the client module of w7
// Student Name : Ryeoeul Ko  Student ID : 129035176  Section : OOP244SAA
/////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "SuperHero.h"

namespace sict {
	SuperHero::SuperHero() {
		super_bonus = 0;
		super_defend = 0;
	}

	SuperHero::SuperHero(const char * name, int health, int strength, int bonus, int defend) : Hero(name, health, strength) {
		if (bonus > 0 && defend > 0) {
			super_bonus = bonus;
			super_defend = defend;
		}
		else {
			super_bonus = 0;
			super_defend = 0;
		}
	}

	bool SuperHero::isEmpty() const {
		return (Hero::isEmpty() && super_bonus == 0 && super_defend == 0);
	}

	int SuperHero::attackStrength() const {
		if (isEmpty()) return 0;
		else return super_bonus + Hero::attackStrength();
	}

	int SuperHero::defend() const {
		int result;
		if (isEmpty()) result = 0;
		else result = super_defend;
		return result;
	}

	const SuperHero & operator*(const SuperHero & first, const SuperHero & second) {
		bool winner = true;
		int round;
		SuperHero hero1 = first;
		SuperHero hero2 = second;
		for (round = 0; round < max_rounds; round++) {
			hero1 -= (hero2.attackStrength() - hero1.defend());
			hero2 -= (hero1.attackStrength() - hero2.defend());
				if (!hero2.isAlive()) break;
				else if (!hero1.isAlive()) {
					winner = false;
					break;
			}
		}
		std::cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
		if (winner) std::cout << first;
		else std::cout << second;
		std::cout << " in " << round + 1 << " rounds." << std::endl;
		if (winner) return first;
		else return second;
	}

}