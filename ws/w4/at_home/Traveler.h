// Workshop 4 - Constructors 
// Ryeoeul Ko
// OOP244SAA
// 129035176

// TODO: add file header comments here

// TODO: add header file guard here
#ifndef SICT_TRAVLER_H
#define SICT_TRAVLER_H
	// TODO: define the constants here

namespace sict {
	const int max_name_size = 16;
	const int max_destination_size = 32;

    // TODO: define the Traveler class here
	class Traveler
	{
	private:
	char t_firstName [max_name_size];
	char t_lastName [max_name_size];
	char t_destination [max_destination_size];
	int t_dyear;
	int t_dmonth;
	int t_dday;
	
	public:
		Traveler();
		Traveler(const char* firstName, const char* lastName, const char* destination);
		Traveler(const char* firstName, const char* lastName, const char* destination, int dyear, int dmonth, int dday);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Traveler& ) const;
	};
}
#endif
