// Workshop 7 - Derived Classes
// File w7_athome.cpp
// Version 2.0
// Date 2017/01/12
// Author       Hasan Murtaza, Chris Szalwinski
// Description
//       This file demonstrates the client module of w7
// Student Name: Ryeoeul Ko  Student ID: 129035176  Section: OOP244SAA
/////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"
#define _CRT_SECURE_NO_WARNINGS 
namespace sict {
	Hero::Hero() {
		heroName[0] = '\0';
		heroHealth = 0;
		heroStrength = 0;
	}
	Hero::Hero(const char * name, int health, int strength) {
		if (name[0] != '\0' && health > 0 && strength > 0) {
			strcpy(heroName, name);
			heroHealth = health;
			heroStrength = strength;
		}
		else {
			*this = Hero();
		}
	}
	void Hero::operator-=(int attack) {
		if (attack > 0 && heroHealth > 0) {
			heroHealth -= attack;
			if (heroHealth < 0)	heroHealth = 0;
		}
	}
	bool Hero::isAlive() const {
			bool result;
			if (heroHealth > 0) result = true;
			else result = false;
			return result;
	}
	bool Hero::isEmpty() const {
		bool result;
		if (heroName[0] == '\0' && heroHealth == 0 && heroStrength == 0) result = true;
		else result = false;
		return result;
	}
	int Hero::attackStrength() const {
		int result;
		if (isEmpty()) result = 0;
		else result = heroStrength;
		return result;
	}
	std::ostream & operator<<(std::ostream & os, const Hero & hero) {
		if (!(hero.isEmpty())) os << hero.heroName;
		else os << "No hero";
		return os;
	}
	const Hero & operator*(const Hero & first, const Hero & second) {
		bool winner = true;
		int round;
		Hero hero1 = first;
		Hero hero2 = second;
		for (round = 0; round < max_rounds; round++) {
			hero1 -= hero2.attackStrength();
			hero2 -= hero1.attackStrength();
			if (!hero2.isAlive()) break;
			else if (!hero1.isAlive()) {
				winner = false; 
				break; 
			}
		}
		std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
		if (winner) std::cout << first;
		else std::cout << second;
		std::cout << " in " << round + 1 << " rounds." << std::endl;
		if (winner) return first;
		else return second;
	}
}