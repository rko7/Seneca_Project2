/***********************************************************************
// OOP244 Workshop 3
// Student Name: Ryeoeul Ko
// Section Name: OOP244SAA
// Student Number: 129035176
***********************************************************************/

#ifndef SICT_BOOK_H
#define SICT_BOOK_H
namespace sict {
	const int max_title_size = 32;
	const int max_name_size = 16;
	const long long min_isbn_value = 1000000000000LL;
	const long long max_isbn_value = 9999999999999LL;

	class Book {
	  	char a_familyName [max_name_size + 1];
		char a_givenName [max_name_size + 1];
		char a_title [max_title_size + 1];
		long long a_isbn;
		int a_year;
		double a_price;

	   public:        
		void set(const char* familyName, const char* givenName, const char* title, long long isbn);
		void set(int year, double price);
		bool isEmpty() const;
		void display(bool object = false) const;

	};
}
#endif
