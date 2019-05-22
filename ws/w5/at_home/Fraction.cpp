//Name: Ryeoeul Ko   Student Number: 129035176  Section: OOP244SAA
//Workshop 5
////////////////////////////////////////////////////////////////////

// TODO: insert header files
#include "Fraction.h"
#include <iostream>
// TODO: continue the namespace
using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = 0;
		denominator = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int fNumerator, int fDenominator) {
		if (fNumerator >= 0 && fDenominator > 0) {
			numerator = fNumerator;
			denominator = fDenominator;
			reduce();
		}
		else *this = Fraction();
	}
	// TODO: implement the max query
	int Fraction::max() const {
		int greater;
		if (numerator > denominator) {
			greater = numerator;
		}
		else greater = denominator;
	return greater;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		int lesser;
		if (numerator < denominator) {
			lesser = numerator;
		}
		else lesser = denominator;
	return lesser;
	}
	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
	int mn = min();  // min of numerator and denominator
	int mx = max();  // max of numerator and denominator
	int g_c_d = 1;
	bool found = false;

	for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
	    if (mx % x == 0 && mn % x == 0) {
			found = true;
			g_c_d = x;
	    }
	}
	return g_c_d;
    }

    // TODO: implement the reduce modifier
	void Fraction::reduce() {
		int rGcd = gcd();
		numerator /= rGcd;
		denominator /= rGcd;
	}
    // TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if (denominator == 1) {
			cout << numerator;
		}
		else {
			cout << numerator << "/" << denominator;
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		if (numerator == 0 && denominator == 0) return true;
		else return false;
	}
    // TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		if (!isEmpty() && !rhs.isEmpty()) {
			int oNumerator = (numerator * rhs.denominator) + (denominator * rhs.numerator);
			int oDenominator = (denominator * rhs.denominator);
			Fraction cOr = Fraction(oNumerator, oDenominator);
			cOr.reduce();
			return cOr;
		}
		else return Fraction();
	}
	// TODO: implement the * operator
	Fraction Fraction::operator*(const Fraction& rhs) const {
		if (!isEmpty() && !rhs.isEmpty()) {
			int oNumerator = numerator * rhs.numerator;
			int oDenominator = denominator * rhs.denominator;
			Fraction cOr = Fraction(oNumerator, oDenominator);
			cOr.reduce();
			return cOr;
		}
		else return Fraction();

	}
	// TODO: implement the == operator
	bool Fraction::operator==(const Fraction& rhs) const {
		if ((!isEmpty() && !rhs.isEmpty()) && ((numerator == rhs.numerator) && (denominator == rhs.denominator))) return true;
		else return false;
	}
	// TODO: implement the != operator
	bool Fraction::operator!=(const Fraction& rhs) const {
		if ((!isEmpty() && !rhs.isEmpty()) && (!(numerator == rhs.numerator) || !(denominator == rhs.denominator)) ) return true;
		else return false;
		}
	// TODO: implement the += operator
	Fraction& Fraction::operator+=(const Fraction& rhs) {
		if (isEmpty() || rhs.isEmpty()) {
			this -> numerator = 0;
			this -> denominator = 0;
		}
		else *this = *this + rhs;
		return *this;
	}
}
