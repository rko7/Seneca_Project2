// Workshop 6 - Class with a Resource
// w6_in_lab.cpp
// Cornel
// 2019/03/02

#include <iostream>
#include "Contact.h"

using namespace std;
using namespace sict;

int main()
{
    cout << "----------------------------------------" << endl;
    cout << "Testing the default constructor!" << endl;
    cout << "----------------------------------------" << endl;
    sict::Contact empty; // sict:: intentional
    empty.display();
    cout << "----------------------------------------" << endl << endl;

    cout << "----------------------------------------" << endl;
    cout << "Testing an invalid contact!" << endl;
    cout << "----------------------------------------" << endl;
    Contact bad(nullptr, nullptr, 0);
    bad.display();
    Contact alsoBad("", nullptr, 0);
    alsoBad.display();
    cout << "----------------------------------------" << endl << endl;

    cout << "----------------------------------------" << endl;
    cout << "Testing the constructor with parameters!" << endl;
    cout << "----------------------------------------" << endl;
    Contact temp("A very long name for contact!", nullptr, 0);
    temp.display();
    cout << "----------------------------------------" << endl << endl;

    cout << "----------------------------------------" << endl;
    cout << "Testing a valid contact!" << endl;
    cout << "----------------------------------------" << endl;
	long long phoneNumbers[] = {    1416123456LL, // invalid: no country code
	                               14161234567LL,
                                 1416234567890LL, // invalid: wrong country code
                                   14162345678LL,
		                           10162345678LL, // invalid: wrong area code
		                                    -1LL, // invalid: all components are wrong
		                          124163456789LL,
                                   14160345678LL, // invalid: wrong phone component
		                           14161230002LL
	                           };
	Contact someContact("John Doe", phoneNumbers, 9);
    someContact.display();
    cout << "----------------------------------------" << endl << endl;

    return 0;
}
