//============================================================================
// Name        : example-streaming_inout_7.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// This program stores employee work hours in an int array.
// It uses one loop to input the hours and other to display them
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	const int NUM_EMPLOYEES = 25;
	int hours[NUM_EMPLOYEES];
	int count;
	int numberOfEmployees;

	ifstream inputFile;
	inputFile.open("/home/psadm2/workspace1/example-streaming_inout_7/Debug/sample.txt");

	if(!inputFile) {
		cout << "Error Opening File" << endl;
		exit(1);
	}
	count = 0;
//	while(!inputFile.eof()) {
//
//		inputFile >> hours[count];
//		count++;
//	} Above is same as below

	while(inputFile >> hours[count]) {
		count++;
	}

	numberOfEmployees = count;

	//Display the contents of the array;
	cout << "the hours you entered are: ";
	for(count = 0; count < numberOfEmployees; count++) {
		cout << " " << hours[count];
	}






	return 0;
}
