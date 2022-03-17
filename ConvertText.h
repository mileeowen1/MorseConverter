#ifndef CONVERT_TEXT_H
#define CONVERT_TEXT_H
/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: January 16, 2020
Programming Assignment: PA1
Description: Create a program that converts English phrases to Morse code and vice versa. It reads in a file, converts it, and outputs it to an output file.
Notes: Referenced https://www.geeksforgeeks.org/list-back-function-in-c-stl/ & http://www.cplusplus.com/reference/sstream/stringstream/ for functions .peek() & .back()
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
// function prototypes
void openinputFile(ifstream&, string);
void openoutputFile(ofstream&, string);
void processFile(ifstream&, ofstream&, string[], bool);
#endif
