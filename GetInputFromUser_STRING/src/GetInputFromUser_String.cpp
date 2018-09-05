//============================================================================
// Name        : GetInputFromUser.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<iostream>
#include<sstream>

using namespace std;

//bool isNumber(string s) {
//    char* p;
//    strtol(s.c_str(), &p, 10);
//    return *p == 0;
//}
//
//int getNumber(string s) {
//    char* p;
//    return strtol(s.c_str(), &p, 10);
//}

int main() {
	 string strInput;
	 int str[3];
	 int cnt;
	 string arr[] = {"APPDOM", "sstatus", "-c"};

	 do
	 {
	  cnt = 0;
	  cout << "Input 3 values: ";
	  getline(cin, strInput, '\n');

	  stringstream ss(strInput);
	  string s;

		 for (int i = 0; i < strInput.length(); i++)
		 {
		     if (strInput == arr[i])
		     {
		         cout << strInput << " is in the array at position " << i << endl;
		     }
		     else
		     {
		         cout << strInput << " is not in the array at position " << i << endl;
		     }
		 }

		  if(cnt!=3) {
			  cout<<"Invalid number of inputs!\n";
		  }
	 }	while(cnt!=3);

	 int i;
	 cout<<"The 3 numbers input by the user are: ";
	 for(i = 0; i < 2; i++)  {
		 cout<<str[i]<<" ";
	 }
	 cout<<endl;
}
