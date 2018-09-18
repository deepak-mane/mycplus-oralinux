//============================================================================
// Name        : WrittingTextFiles.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	string outputFileName = "text.txt";

	//  ofstream outFile;
	//	outFile.open(outputFileName);

	fstream outFile;
	outFile.open(outputFileName, ios::out);


	if(outFile.is_open()) {
		outFile << "Hello there" << endl;
		outFile << 12345 << endl;
		outFile.close();
 	}
	else {
		cout << "Could not create file: " << outputFileName << endl;
	}

	return 0;
}
