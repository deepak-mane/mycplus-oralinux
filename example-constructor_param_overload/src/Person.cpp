/*
 * Person.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: psadm2
 */
#include <sstream>
#include "Person.h"


Person::Person() {
	// TODO Auto-generated constructor stub
	name = "undefined";
	age = 0;
}

Person::Person(string newName, int newAge) {
	name = newName;
	age = newAge;
}

string Person::toString() {
	stringstream ss;

	ss << "Name: ";
	ss << name;
	ss << "; Age: ";
	ss << age;

	return ss.str();

}
