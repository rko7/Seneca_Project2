// Workshop 4 - Constructors 
// Student Name: Ryeoeul Ko
// Section: OOP244SAA
// Student ID: 129035176

// TODO: add file header comments here

// TODO: add header file guard here
#ifndef SICT_TRAVLER_H
#define SICT_TRAVLER_H
#define max_destination_size 32
#define max_name_size 16
	// TODO: define the constants here
namespace sict {

    // TODO: define the Traveler class here
	class Traveler
	{
	private:
	char t_firstName [max_name_size + 1];
	char t_lastName [max_name_size + 1];
	char t_destination [max_destination_size + 1];
	
	public:
		Traveler();
		Traveler(const char* firstName, const char* lastName,  const char* destination);
		bool isEmpty() const;
		void display() const;
	};
}
#endif
