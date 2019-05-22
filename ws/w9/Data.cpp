// OOP244 Workshop 9: Function Templates
// File: Data.cpp
// Version: 2.0.1
// Date: 2017/12/17
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the answers and readRow functions
// Chris     2017.12.17 removed answers to Q1
// Studnet Name: Ryeoeul Ko  Student ID: 129035176  Section: OOP244SAA
///////////////////////////////////////////////////


#include <iostream>
#include <cstring>
#include "Data.h"

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	// bool readRow(std::istream& input, const char* name, double* data, int n)
	// bool readRow(std::istream& input, const char* name, int* data, int n)
	//Since both functions contain the same logic, replace them with a single template function of the same name, store that function in Data.h, and remove the original function definitions Data.cpp.
	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int populationChanged = population[n - 1] - population[0];
			std::cout.precision(2);
			std::cout << "Population change from " 
					<< min(year, n) << " to " 
					<< max(year, n) << " is "	
					<< std::fixed << static_cast<double>(populationChanged) / 1000000 
					<< " million" << std::endl;




		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		const char *v_c_t = (violentCrimeRate[1] - violentCrimeRate[0] > 0) ? "up" : "down";
		std::cout << "Violent Crime trend is " << v_c_t << std::endl;





		// Q3 print the GTA number accurate to 0 decimal places
		std::cout << "There are "
			<< std::fixed << average(grandTheftAuto, n) / 1000000
			<< " million Grand Theft Auto incidents on average a year"
			<< std::endl;

	




		// Q4. Print the min and max violentCrime rates
		std::cout << "The Minimum Violent Crime rate was " 
			<< static_cast<int>(min(violentCrimeRate, n)) 
			<< std::endl;
		std::cout << "The Maximum Violent Crime rate was " 
			<< static_cast<int>(max(violentCrimeRate, n)) 
			<< std::endl;

	}

	
}



