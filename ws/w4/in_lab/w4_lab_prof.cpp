// Workshop 4 - Constructors - Test Main
// w4_in_lab.cpp
// Cornel
// 02/02/2019

#include <iostream>
#include "Traveler.h"
#include "Traveler.h" // this is intentional

using namespace std;
using namespace sict;

int main() {
	Traveler travelers[] = {
		Traveler(nullptr, nullptr, "Toronto"),
		Traveler(nullptr, "",      "Toronto"),
		Traveler(nullptr, "Smith", "Toronto"),

		Traveler("",      nullptr, "Toronto"),
		Traveler("",      "",      "Toronto"),
		Traveler("",      "Smith", "Toronto"),

		Traveler("John",  nullptr, "Toronto"),
		Traveler("John",  "",      "Toronto"),
		Traveler("John",  "Smith", "Toronto"), // valid

		Traveler("John",  "Smith", nullptr),
		Traveler("John",  "Smith", ""),
		Traveler(nullptr, nullptr, nullptr),
		Traveler("",      "",      ""),
		Traveler()
	};
	cout << "----------------------------------------" << endl;
	cout << "Testing the validation logic" << endl;
	cout << "(only traveler 9 should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 14; ++i)
	{
		cout << "Traveler " << i + 1 << ": " << (travelers[i].isEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	sict::Traveler vanessa("Vanessa", "Williams", "Paris"),
		            mike("Mike",       "Jones",    "Tokyo"),
		            alice("Alice",     "Miller",   "Rome");

	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	vanessa.display();
	mike.display();
	alice.display();
	travelers[0].display(); // not valid
	travelers[8].display();
	travelers[13].display(); // not valid
	cout << "----------------------------------------" << endl << endl;

	return 0;
}
