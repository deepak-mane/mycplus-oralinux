/*
 * Cat.cpp
 *
 *  Created on: Sep 8, 2018
 *      Author: psadm2
 */
#include <iostream>
#include "Cat.h"

using namespace std;

void Cat::speak() {
	if(happy) {
		cout << "Meaow!!!" << endl;
	}
	else {
		cout << "Ssssss!!!" << endl;
	}
}

void Cat::makeHappy() {
	happy = true;
}

void Cat::makeSad() {
	happy = false;
}
