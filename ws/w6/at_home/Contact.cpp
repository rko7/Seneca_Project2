// Workshop 6 - Class with a Resource
// Contact.cpp
// Cornel
// 2019/03/02
// Student Name: Ryeoeul Ko   Student Number: 129035176  Section: OOP244SAA

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<iomanip>
#include "Contact.h"

using namespace std;

namespace sict
{
	Contact::Contact() {
		name[0] = '\0';
		phoneNumber = nullptr;
		storedPhoneNumber = 0;

	}

	Contact::Contact(const char * mName, const long long * phoneN, int storedPn)
	{
		int size = 0;
			if (mName != nullptr && mName[0] != '\0') {
				name[0] = '\0';
				strncpy(name, mName, 15);
				name[16] = '\0';
				
				if (storedPn > 0) {
					for (int i = 0; i < storedPn; i++) {
						if (validNum(&phoneN[i])) {
							size++;
						}
					}
					storedPhoneNumber = size;
					phoneNumber = new long long[storedPhoneNumber];

					int j = 0;

					for (int i = 0; i < storedPn; i++) {
						if (validNum(&phoneN[i])){
							phoneNumber[j] = phoneN[i];
							j++;
							}
						}
					}
				else {
					phoneNumber = nullptr;
					storedPhoneNumber = 0;
				}
				
				
			}
			else {
				*this = Contact();
			}
		}

	Contact::Contact(const Contact & con) {
		phoneNumber = nullptr;
		*this = con;
		}

	Contact:: ~Contact() {		
		delete[] phoneNumber;	
	}

	bool Contact::isEmpty() const {
		bool result = false;
		if (name[0] == '\0' )
			result= true;
		else 
			result =false;

		return result;
	}

	bool Contact::validNum(const long long * n) const {
		bool result = false;
		if ( (countryCode(n) < 100) && countryCode(n) != 0 && ((int)areaCode(n) /100 != 0) && ((int)phoneNum(n)/1000000 != 0)){
			result = true;
		}
		return result;
	}

	int Contact::countryCode(const long long *n) const {
		return (int)(*n / 10000000000);
			   	}
	int Contact::areaCode(const long long *n) const{
		return (int)((*n % 10000000000) / 10000000);
	}
	int Contact::phoneNum(const long long *n) const {
		return *n % 10000000; 
	}
	Contact & Contact::operator=(const Contact & con) {
		if (this != &con) {
			strcpy(name, con.name);
			storedPhoneNumber = con.storedPhoneNumber;			

			phoneNumber = new long long[storedPhoneNumber];

			if (con.phoneNumber != nullptr) {
				for (int i = 0; i < storedPhoneNumber; i++) {
					phoneNumber[i] = con.phoneNumber[i];
				}
			}
			else
			{
				phoneNumber = nullptr;
			}
		} return *this;
	}
	Contact & Contact::operator+=(long long pNum) {
		if (validNum(&pNum) && !(isEmpty())) {

			storedPhoneNumber++;

			long long* temp = new long long[storedPhoneNumber];

			for (int i = 0; i < storedPhoneNumber - 1; ++i) {
				temp[i] = phoneNumber[i];
			}

			temp[storedPhoneNumber - 1] = pNum;
			phoneNumber =temp;
		}
		return *this;
	}
	void Contact::display() const {
		
		if (isEmpty()) 
			cout << "Empty contact!" << endl;
		else 
			cout << name << endl;
			for (int i = 0; i < storedPhoneNumber; i++) {
				cout << "(+" << countryCode(&phoneNumber[i]) << ") "<< areaCode(&phoneNumber[i]);
				cout << " " << (int)phoneNum(&phoneNumber[i]) / 10000 << "-";
				cout << setfill('0') << setw(4) << (int)phoneNum(&phoneNumber[i]) % 10000 << endl;
				}
			}
	}
