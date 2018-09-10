//============================================================================
// Name        : example-streaming_inout_3.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream inFile;
	inFile.open("/home/psadm2/workspace1/example-streaming_inout_3/Debug/list.txt");

	//Check for error
	if(inFile.fail()) {
		cerr << "Error Opening File!!!!!";
		exit(1);
	}

	int x, y;
	inFile >> x >> y;
	cout << "num1: " << x << endl;
	cout << "num2: " << y << endl;

	return 0;
}
