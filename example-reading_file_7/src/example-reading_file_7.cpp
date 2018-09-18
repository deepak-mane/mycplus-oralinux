//============================================================================
// Name        : example-reading_file_7.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

//Convert a string to upper case
std::string toUpperCase(const std::string &str) {
	std::string upperCase;
	for(int i = 0; i < str.size(); i++) {
		upperCase.push_back(toupper(str[i]));
	}
	return upperCase;
}

int main() {
	//Open file
	std::ifstream playInputFile("romeo.txt");
	if(playInputFile.fail()) {
		std::cerr << "Unable to open data file"<< std::endl;
		exit(1);
	}

	//Read file line by line
	std::string nextLine;
	int loveCount = 0;
	while(getline(playInputFile, nextLine)) {
		std::string upperCase = toUpperCase(nextLine);
		if(upperCase.find("LOVE") != std::string::npos) {
			loveCount++;
			std::cout << std::setw(4) << loveCount << ": " << nextLine << std::endl;
		}
	}
	playInputFile.close();

	std::cout << std::endl << std::endl;
	std::cout << "File has " << loveCount << " references to love.\n";



	return 0;
}
