//============================================================================
// Name        : example-streaming_inout_13.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	char filename[] = "/home/psadm2/workspace1/example-streaming_inout_13/samples.txt";
	char ch; //To hold character
	ifstream infile(filename); //To open samples.txt
	// to make sure open was successful
	if (infile.fail()) {
		cout << "Unable to Open file "<< filename << endl;
		return 1;
	}

	while(!infile.eof()) {
		infile.get(ch);
		cout << ch;
	}
	infile.close();

//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
