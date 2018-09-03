/*
 * main.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: psadm2
 */

#include <iostream>
#include <stdio.h>
#include <iomanip>

int main ()
{
	std::cout << "Hellow , Udemy Users!!!!!!!" << std::endl;

	std::cout << std::setw (5) << 2018 << " is today's year." << std::endl;
	std::cout << std::setw (5) << 3 << " is today's month" << std::endl;

   std::cout << sizeof(int) << std::endl;//
   std::cout << sizeof(char)<< std::endl;//	Exactly one byte in size. At least 8 bits.
   //std::cout << sizeof(char16_t)	<< std::endl;//Not smaller than char. At least 16 bits.
   //std::cout << sizeof(char32_t)	<< std::endl;//Not smaller than char16_t. At least 32 bits.
   std::cout << sizeof(wchar_t)	<< std::endl;//Can represent the largest supported character set.std::cout <<
   std::cout << sizeof(signed char)	<< std::endl;//Same size as char. At least 8 bits.
   std::cout << sizeof(signed short int)	<< std::endl;//Not smaller than char. At least 16 bits.
   std::cout << sizeof(signed int)	<< std::endl;//Not smaller than short. At least 16 bits.
   std::cout << sizeof(signed long int)	<< std::endl;//Not smaller than int. At least 32 bits.
   std::cout << sizeof(signed long long int)<< std::endl;//	Not smaller than long. At least 64 bits.
   std::cout << sizeof(unsigned char)	<< std::endl;//(same size as their signed counterparts)
   std::cout << sizeof(unsigned short int) << std::endl;//
   std::cout << sizeof(unsigned int)<< std::endl;//
   std::cout << sizeof(unsigned long int)<< std::endl;//
   std::cout << sizeof(unsigned long long int)<< std::endl;//
   std::cout << sizeof(float)	<< std::endl;//
   std::cout << sizeof(double) << std::endl;//
   std::cout << sizeof(long double) << std::endl;//
   std::cout << sizeof(bool)	<< std::endl;//
   //std::cout << sizeof(void)<< std::endl;//	no storage
   //std::cout << sizeof(nullptr)<< std::endl;//	decltype(nullptr)

 	return 0;
}
