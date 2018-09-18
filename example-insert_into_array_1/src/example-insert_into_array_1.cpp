//============================================================================
// Name        : example-insert_into_array_1.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;

int main() {


	/* C++ Program - Insert Element in Array */


	int arr[50], size, insert, i, pos;
	cout<<"Enter Array Size : ";
	cin>>size;
	cout<<"Enter array elements : ";
	for(i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter element to be insert : ";
	cin>>insert;
	cout<<"At which position (Enter index number) ? ";
	cin>>pos;
	// now create a space at the required position
	for(i=size; i>pos; i--)
	{
		arr[i]=arr[i-1];
	}
	arr[pos]=insert;
	cout<<"Element inserted successfully..!!\n";
	cout<<"Now the new array is : \n";
	for(i=0; i<size+1; i++)
	{
		cout<<arr[i]<<" ";
	}

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
