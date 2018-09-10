//============================================================================
// Name        : example-streaming_inout_6.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	char name[20];
	char sport[20];

	cin.getline(name, sizeof(name));
	cin.getline(sport, sizeof(sport));

	cout << name << " loves " << sport << endl;

	cin.get();



	return 0;
}
