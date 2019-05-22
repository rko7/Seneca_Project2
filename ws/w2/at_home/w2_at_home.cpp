/***********************************************************************
// OOP244 Workshop 2
// Student Name: Ryeoeul Ko
// Section Name: OOP244SAA
// Date 2019/01/24//
/////////////////////////////////////////////////////////////////
***********************************************************************/

// Workshop 2 - Dynamic Memory
// Version 1.0
// Date: 31/08/2018
// Author: Cornel

// TODO: include headers
#include <iostream>
#include "CellPhone.h"

using namespace std;
using namespace sict;

void read(sict::CellPhone& phone);

int main()
{
	int count = 0;
	// TODO: declare the pPhones pointer here (don't forget to initialize it)

	CellPhone *pPhones = nullptr;
	cout << "==========" << endl
	     << "Input data" << endl
	     << "==========" << endl
	     << "Enter the number of phones: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	// TODO: allocate dynamic memory here for the pPhones pointer
	pPhones = new CellPhone[count];

	for (int i = 0; i < count; ++i) {
		cout << "Phone #" << i + 1 << ": " << endl;
		// TODO: add code to accept user input for Phone i
		read(pPhones[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
	     << "The 1st phone entered is" << endl
	     << "------------------------------" << endl;
	sict::display(pPhones[0]);
	cout << "------------------------------" << endl << endl;

	// expand the array of Phones by 1 element
	{
		// TODO: allocate dynamic memory for count + 1 Phones
		
		CellPhone *nPhones = nullptr;
		nPhones = new CellPhone[count+1];
		// TODO: copy elements from original array into this newly allocated array
		for(int i = 0; i < count; i++) {
		nPhones[i] = pPhones[i];        
		}
		
		
			
		// TODO: deallocate the dynamic memory for the original array
		delete[] pPhones;
		pPhones = nullptr;

		// TODO: copy the address of the newly allocated array into pPhones pointer
		pPhones = nPhones;
	}

	// add the new Phone
	cout << "==========\n"
	     << "Input data\n"
	     << "==========\n"
	     << "Phone #" << count + 1 << ": " << endl;
	// TODO: accept input for the new element in the array
	read(pPhones[count]);
	count++;
	cout << "==========\n" << endl;

	// testing that the overload of "display(...)" works
	sict::display(pPhones, count);
	cout << endl;

	// TODO: deallocate the dynamic memory here
	delete[] pPhones;
	pPhones = nullptr;
	return 0;
}


// read accepts data for a Phone from standard input
void read(CellPhone& phone)
{
	cout << "Enter the model of the Phone: ";
	cin.get(phone.m_model, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the price for phone " << phone.m_model << ": ";
	cin >> phone.m_price;
	cin.ignore(2000, '\n');
}
