/***********************************************************************
// OOP244 Workshop 2
// Student Name: Ryeoeul Ko
// Section Name: OOP244SAA
// Date 2019/01/24//
/////////////////////////////////////////////////////////////////
***********************************************************************/


// TODO: header safeguards
#ifndef SICT_CellPhone_H
#define SICT_CellPhone_H

// TODO: sict namespace
namespace sict{
// TODO: define the structure CellPhone in the sict namespace
	struct CellPhone{
		char m_model [32];
		float m_price;
	};
// TODO: declare the function display(...),
//         also in the sict namespace
void display(const CellPhone &phone);
void display(const CellPhone *phones, int noEl);
}
#endif
