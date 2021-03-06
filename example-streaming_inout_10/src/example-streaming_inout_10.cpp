//============================================================================
// Name        : example-streaming_inout_10.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include "person.h"

using namespace std;

//prototypes
void GetData();
double CalculateAvgAge(vector<person> arrOfNames, int);
void displayOutput(vector <person>, double);



int main() {

	GetData();
	return 0;
}


void GetData() {
	//open file for read only
	ifstream inputFile;
	inputFile.open("/home/psadm2/workspace1/example-streaming_inout_10/program.txt", ios::in);

	//verify file opened
	if(inputFile.fail()) {
		cout << "Unable to open/process file" << endl;
		exit(EXIT_FAILURE);
	} else {
		string line;
		vector <person> arrOfNames;
		int counter = 0; // counts number of elements in vector

		while(getline(inputFile, line)) {
			//split string by spaces
			//there are 2 spaces, so we can declare array with 2 indexes
			//that hold the position of each space
			int spacePos[2];
			int posIndex = 0;
			counter++;

			for(int i = 0; line.length(); i++) {
				if(line[i] == ' ') {
					spacePos[posIndex] = i;
					posIndex++;
				}
			}
			//now we have position of the spaces we can delimit line into 3 words
			string firstName = line.substr(0, spacePos[0]); //starts from zero goes to first index in spacePos[]
			// last name starts from first space + 1 , and the length is second space position - 1
			string lastName = line.substr(spacePos[0] + 1, spacePos[1] - spacePos[0] - 1);
			int age = stoi(line.substr(spacePos[1])); // convert to integer
			arrOfNames.push_back(person(firstName, lastName, age));
		}

		inputFile.close();

		double avg = CalculateAvgAge(arrOfNames, counter);

		displayOutput(arrOfNames, avg);
	}
}

double CalculateAvgAge(vector<person> arrOfNames, int counter) {
			double avg = 0;
			int total = 0;

			//loop through the vector with all the names and sum all the ages
			for(int i =0; i<counter; i++) {
				total =+ arrOfNames[i].getAge();
			}

			avg = total * 1.0 / counter;
			return avg;
}

void displayOutput(vector<person> arrOfNames, double avg) {
	//display all names in formatted output
	for(int i = 0; i < arrOfNames.size(); i++) {
		cout << "PERSON # " << i + 1 << endl;
		cout << "FIRST NAME: " << arrOfNames[i].getFirstName() << endl;
		cout << "LAST NAME: " << arrOfNames[i].getLastName() << endl;
		cout << "AGE: " << arrOfNames[i].getAge() << endl;
		cout << "-----------------------------------------------" << endl;
	}

	cout << "\nAVERAGE AGE IS " << setprecision(2) << fixed << avg << " YAERS." << endl;
}
