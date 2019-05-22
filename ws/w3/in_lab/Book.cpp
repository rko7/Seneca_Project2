/***********************************************************************
// OOP244 Workshop 3
// Student Name: Ryeoeul Ko
// Section Name: OOP244SAA
// Date 2019/01/31
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Book.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sict {
	void Book::set(const char* givenName, const char* familyName, const char* title, long long isbn) {
		if (min_isbn_value <= isbn && isbn <= max_isbn_value) {
			a_isbn = isbn;

			strncpy(a_givenName, givenName, max_name_size);
			strncpy(a_familyName, familyName, max_name_size);
			strncpy(a_title, title, max_title_size);
		}
		else {
			a_isbn = 0LL;
			strcpy(a_givenName, " ");
			strcpy(a_familyName, " ");
			strcpy(a_title, " ");
		}
	}

	bool Book::isEmpty() const {
		bool empty;
		if ( a_isbn == 0LL ){
			empty = true;
		}
		else {
			empty = false;
		}
		return empty;
	}
	void Book::display() const{
		if(isEmpty()){
		cout << "The book object is empty!" << endl;
		}
		else {
		cout << "Author: " << a_familyName << ", " << a_givenName << endl;
		cout << "Title: " << a_title << endl;
		cout << "ISBN-13: " << a_isbn << endl;
		}
	}


}
