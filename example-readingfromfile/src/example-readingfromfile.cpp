//============================================================================
// Name        : example-readingfromfile.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ofstream>
#include <fstream>
#include <cstring>


int main() {
	std::ifstream file_("/home/psadm2/workspace1/example-readingfromfile/myfile.txt");

	int id;
	std::string name;
	int age;

	if(file_.is_open()) {
		while(file_ >> id >> name >> age) {
			std::cout << id << " :ID " << name << " :name " << age << " :age " << std::endl;
		}
		file_.close();
	} else {
		std::cout << "File failed to open..." << std::endl;
	}




	return 0;
}
