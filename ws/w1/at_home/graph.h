/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File w1_in_lab.cpp
// Version 1.0
// Date 2016/01/10
// Author       Fardad Soleimanloo
// Description
// This provides some source code in a single file to break
// into modules and compile together
//
// Revision History
// -----------------------------------------------------------
// Name Ryeoeul Ko    Date 2019/01/17     Reason
// 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SICT_GRAPH_H
#define SICT_GRAPH_H

namespace sict {
#define MAX_NO_OF_SAMPLES 20
void getSamples(int samples[], int noOfSamples);
int findMax(int samples[], int noOfSamples);
void printBar(int val, int max);
void printGraph(int samples[], int noOfSamples);
}
#endif
