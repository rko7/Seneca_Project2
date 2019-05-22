/***********************************************************************
// OOP244 Workshop 3
// Student Name: Ryeoeul Ko
// Section Name: OOP244SAA
// Student ID: 129035176
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Book.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sict {
	void Book::set(const char* givenName, const char* familyName, const char* title, long long isbn) { // Update the function with 4 parameters that works with new validation logic for the ISBN
			if (min_isbn_value <= isbn && isbn <= max_isbn_value) {
			int digit [13] = {0};
			int sum = 0;
			long long  temp = isbn;
			for (int i = 0; i < 13; i++) {
				 digit [i] = temp % 10;
 				 temp = (temp - digit [i]) / 10;
			}
			for (int i = 1; i < 13; i++) {
				if (i % 2 == 1) {
					sum += 3 * digit[i];
				}
				else {
					sum += digit[i];
				}
			}
			if(((sum + digit[0]) % 10) == 0) {
				a_isbn = isbn;
				strncpy(a_givenName, givenName, max_name_size);
				strncpy(a_familyName, familyName, max_name_size);
				strncpy(a_title, title, max_title_size);
				a_givenName[max_name_size]='\0';
				a_familyName[max_name_size]='\0';
				a_title[max_title_size]='\0';
			}
		}
		else {
			a_isbn = 0LL;
			strcpy(a_givenName, " ");
			strcpy(a_familyName, " ");
			strcpy(a_title, " ");
		}			
	}
	        void Book::set(int year, double price){
                if (!year == 0000 && !price == 00.00) {
                        a_year = year;
                        a_price = price;
                }
                else {}
			}

	bool Book::isEmpty() const { //Set the function returns true when the object is in the safe empty state, otherwise returns false. 
		bool empty;
		if ( a_isbn == 0LL ){
			empty = true;
		}
		else {
			empty = false;
		}
		return empty;
	}

	void Book::display( bool object ) const { //Add Boolean parameter to function with a default value as false. Print the each output that match each cases: empty-false, not_empty-false, empty-true, not_empty-true
		if (object) {
			if (isEmpty()) {
				cout << "|";
				cout.width(92);
				cout.setf(ios::left);
				cout << "The book object is empty!" << "|" << endl;
			}
			else {
				cout << "|";
				cout.width(max_name_size);
				cout.setf(ios::right);
				cout << a_familyName;
				cout << "|";
				cout.width(max_name_size);
				cout.setf(ios::right);
				cout << a_givenName;
				cout.unsetf(ios::right);
				cout << "|";
				cout.width(max_title_size);
				cout.setf(ios::left);
				cout << a_title;
				cout << "|";
				cout.unsetf(ios::left);
				cout.width(13);
				cout.setf(ios::right);
				cout << a_isbn;
				cout << "|";
				cout.width(4);
				cout << a_year;
				cout << "|";
				cout.setf(ios::fixed);
				cout.width(6);
				cout.precision(2);
				cout << a_price << "|" << endl;
			};
		} 
		else {
			if (isEmpty()) {
				cout << "The book object is empty!" << endl;
			}
			else {
				cout << "Author: " << a_familyName << ", " << a_givenName << endl;
				cout << "Title: " << a_title << endl;
				cout << "ISBN-13: " << a_isbn << endl;
				cout << "Publication Year: " << a_year << endl;
				cout << "Price: " << a_price << endl;
			}
		}
	}
}
