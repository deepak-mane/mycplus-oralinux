//============================================================================
// Name        : example-dynamic_array_1.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const int CAPACITY = 1000;

int main() {

	int *dArray;
	dArray = new int[CAPACITY];

	dArray[0] = 3;
	dArray[1] = 7;
	dArray[2] = 2;
	dArray[3] = 9;


//	char *dArray1;
//	dArray1 = new char[CAPACITY];
//	*dArray1[0] = "hello";
//	*dArray1[1] = "Deepak";
//	*dArray1[2] = "Mane";
//	*dArray1[3] = ".";


	for(int i = 0; i < sizeof(dArray); i++) {
		cout << dArray[i] << " ";
	}

	for(int i = 0; i < sizeof(dArray1); i++) {
		cout << dArray1[i] << " ";
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
