/*
 * main.cpp
 *
 *  Created on: Sep 4, 2018
 *      Author: psadm2
 */

#include <iostream>
//#include <string>
//#include <ctime>


int main () {

	int x = 10;

	if(x > 6) 	{
		std::cout << "X is greater than 6" << std::endl;
	}

	if( x > 10)
		std::cout << "X is greater than 10" << std::endl;
	else
		std::cout << "X is Not greater than 10" << std::endl;


	int age;
	std::cout << "Enter person's age: ";
	std::cin >> age;

	if (age >= 18) {
		std::cout << "Person is an adult!" << std::endl;
	} else if (age > 13 ) {
		std::cout << "Person is a teenager" << std::endl;
	} else if (age > 3) {
		std::cout << "Person is a Kid" << std::endl;
	} else {
		std::cout << "It's a BABY" << std::endl;
	}


}
