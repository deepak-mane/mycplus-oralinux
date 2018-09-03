//============================================================================
// Name        : InteractionWithUser.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//using namespace std;

int main() {

	int number;
	std::cout << "Enter an integer: ";
	std::cin >> number;

	int squared = number * number ;

	std::cout << "Squared value of this integer is : " << squared << std::endl;
	return 0;
}
