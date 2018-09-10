//============================================================================
// Name        : example-streaming_inout_8.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	ifstream theFile("/home/psadm2/workspace1/example-streaming_inout_8/players.txt");

	int id;
	string name;
	double money;

	while(theFile >> id >> name >> money) {
		cout << id << "," << name << "," << money << endl;
	}
	return 0;
}
