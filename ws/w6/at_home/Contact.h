#pragma once
#ifndef CONTACT_H
#define CONTACT_H

namespace sict 
{	
	const int max_name_size = 16;
	class Contact
	{
		char name [max_name_size];
		long long* phoneNumber;
		int storedPhoneNumber;
		int result;
	public:
		Contact();
		Contact(const char*, const long long*, int);
		Contact(const Contact& con);
		~Contact();
		bool isEmpty() const;
		void display() const;
		bool validNum(const long long *) const;
		int countryCode(const long long *) const;
		int areaCode(const long long *) const;
		int phoneNum(const long long *) const;
		Contact& operator=(const Contact& con);
		Contact& operator+=(long long pNum);
	};
}

#endif // !CONTACT_H