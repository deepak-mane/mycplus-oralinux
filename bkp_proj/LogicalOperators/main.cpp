/*
 * main.cpp
 *
 *  Created on: Sep 4, 2018
 *      Author: psadm2
 */

#include <iostream>

int main () {

	bool A = true,
			 B = true,
			 C = false,
			 D = true;

	bool E = A && B;
	bool F = A && B && C && D;

	std::cout << E << std::endl;
	std::cout << F << std::endl;







	return 0;

}

