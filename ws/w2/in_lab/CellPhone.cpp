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
			cout << "Phone " << phone.m_model << " costs $" << phone.m_price << "!" << endl;
	}
 }

