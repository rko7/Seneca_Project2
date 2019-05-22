/***********************************************************************
// OOP244 Workshop 2
// Student Name: Ryeoeul Ko
// Section Name: OOP244SAA
// Date 2019/01/24//
/////////////////////////////////////////////////////////////////
***********************************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "CellPhone.h"
using namespace std;
// TODO: the sict namespace
namespace sict{
    // TODO: definition for display(...)   
	void display(const CellPhone& phone){
			cout << "Phone "<< phone.m_model <<" costs $" << phone.m_price << "!" << endl;
	}

	void display(const CellPhone *phones, int noEl) {
	float smP = 10000;
	cout << "------------------------------" << endl;
	cout << "Phones available at the mall:" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < noEl; i++)
		{
			cout << i + 1 << ". ";
			display(phones[i]); 
		if(smP > phones[i].m_price){
			smP = phones[i].m_price;        
		}
	}       
	cout << "------------------------------" << endl;
	cout << "The cheapest phone costs $" << smP <<"."<< endl;
	cout << "------------------------------" << endl;
	
 }
}
