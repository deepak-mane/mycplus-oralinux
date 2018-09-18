/*
 * Person.h
 *
 *  Created on: Sep 12, 2018
 *      Author: psadm2
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

class Person {
private:
	string name;
	int age;

public:
	Person();
	Person(string newName) { name  = newName; age = 0; };
	Person(string newName, int newAge);
	string toString();
};

#endif /* PERSON_H_ */
