//============================================================================
// Name        : example-readingfromfile_1.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>

int main() {

	std::ifstream inFile;
	inFile.open("/home/psadm2/workspace1/example-readingfromfile_1/list.txt");

	//Check for Error
	if(inFile.fail()) {
		std::cerr << "Error Opening File" << std::endl;
		exit(1);
	}

	std::string item;
	int count = 0;
	//Read a file until you 've reached the endof file
	while(!inFile.eof()) {
		inFile >> item;
		//count++;
		if (item == "orange") {
			count++;
		}
	}

	inFile.close();

	std::cout << "Items found Instances of Orange ::  " << count << std::endl;
	return 0;
}
