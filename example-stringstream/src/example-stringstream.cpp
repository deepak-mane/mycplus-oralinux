//============================================================================
// Name        : example-stringstream.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
using namespace std;

int main() {


	string name = "Bob";
	int age = 28;

	stringstream ss;

	ss << "Name is: ";
	ss << name;
	ss << "; Age is : ";
	ss << age;

	string info = ss.str();
	cout << info << endl;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
