//============================================================================
// Name        : example-streaming_inout_5.cpp
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
//	ifstream inFile;
//	inFile.open("/home/psadm2/workspace1/example-streaming_inout_4/Debug/list.txt");
//
//	//Check For Error;
//	if(inFile.fail()) {
//		cerr << "Error Opening File!!!" << endl;
//		exit(1);
//	}
//
//	string item;
//	int count = 0;
//	//Read through file until you reached the end;
//	while(!inFile.eof()) {
//		inFile >> item;
//		if(item == "orange") {
//			count++;
//		}
//	}
//
//	cout << count << " Instances of Fruit items found..."<<  endl;

	ofstream outFile;
	outFile.open("sample.txt");

	outFile << "First Number: " << 5 << endl;
	outFile.close();

	return 0;
}
