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
	//Open the output file;
	std::ofstream fileOut("data.txt");
	if(fileOut.fail()) {
		std::cerr << "Error opening output file" << std::endl;
		exit(1);
	}

	//Ask user for values and write them to file
	bool done = false;
	while(!done) {
		double value = 0;
		std::cout << "Enter a value (-1 to end): ";
		std::cin >> value;

		if (value == -1) {
			done = true;
		} else {
			fileOut << value <<  "\n";//std::endl;
		}

	//Close the file to flush the output
	fileOut.close();

	}






	return 0;
}
