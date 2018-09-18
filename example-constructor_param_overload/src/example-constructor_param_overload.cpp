//============================================================================
// Name        : example-constructor_param_overload.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Person.h"
using namespace std;

int main() {

	Person person1;
	Person person2("Bob");
	Person person3("Deepak" , 28);

	cout << person1.toString() << endl;
	cout << person2.toString() << endl;
	cout << person3.toString() << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
