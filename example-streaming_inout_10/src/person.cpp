/*
 * person.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: psadm2
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "person.h"


using namespace std;

person::person() {
	// TODO Auto-generated constructor stub

}

person::person(string firstName, string lastName, int age) {
	//set values using setters * passing user supplied values;
	setFirstName(firstName);
	setLastName(lastName);
	setAge(age);
}

//setters perform a very basic input validation
//if fist name has at least 1 character. conside it a valid input
void person::setFirstName(string fname) {
	if(fname.length() > 0) {
		strFirstName = fname;
	} else {
		cout << "Invalid input for first name\n" << endl;
		exit(EXIT_FAILURE);
	}
}

void person::setLastName(string lname) {
	if(lname.length() > 0) {
		strFirstName = lname;
	} else {
		cout << "Invalid input for last name\n" << endl;
		exit(EXIT_FAILURE);
	}
}

void person::setAge(int age) {
	if(age > 0) {
		intAge = age;
	} else {
		cout << "Invalid input for age\n" << endl;
		exit(EXIT_FAILURE);
	}
}

person::~person() {
	// TODO Auto-generated destructor stub
}

