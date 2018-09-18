//============================================================================
// Name        : example-writing_file_6.cpp
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
	// Open File and initialize if

	std::ifstream dataFile("/home/psadm2/workspace1/example-writing_file_6/src/sample.txt");

	if(dataFile.fail()) {
		std::cerr << "Unable to open data file.txt" << std::endl;
		exit(1);
	}

	//Read all values summing them up
	double value = 0;
	double sum = 0;
	while(dataFile >> value) {
		sum += value;
		std::cout << "Read: " << value << std::endl;
	}

	dataFile.close();

	// Print sum
	std::cout << "Sum of all values: " << sum << std::endl;
	return 0;
}
