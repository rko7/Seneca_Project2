/***********************************************************************
// OOP244 Workshop 3
// Student Name: Ryeoeul Ko
// Section Name: OOP244SAA
// Date 2019/01/31
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SICT_BOOK_H
#define SICT_BOOK_H
namespace sict {
	const char max_title_size = 33;
	const char max_name_size = 17;
	const long long min_isbn_value = 1000000000000LL;
	const long long max_isbn_value = 9999999999999LL;

	class Book {
		char a_givenName [max_name_size];
	  	char a_familyName [max_name_size];
		char a_title [max_title_size];
		long long a_isbn;
	   public:        
		void set(const char* givenName, const char* familyName, const char* title, long long isbn);
		bool isEmpty() const;
		void display() const;
	};
}
#endif
