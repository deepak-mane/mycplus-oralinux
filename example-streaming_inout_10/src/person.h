/*
 * person.h
 *
 *  Created on: Sep 10, 2018
 *      Author: psadm2
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

class person {
private:
	string strFirstName;
	string strLastName;
	int intAge;
public:
	person(); //default constructor
	person(string, string, int);
	virtual ~person();
	//setting values
	void setFirstName(string);
	void setLastName(string);
	void setAge(int);

	//get values
	string getFirstName() const { return strFirstName; }
	string getLastName() const { return strLastName; }
	int getAge() const { return intAge; }
};

#endif /* PERSON_H_ */
