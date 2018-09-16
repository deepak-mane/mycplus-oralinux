/*
 * PSutils.h
 *
 *  Created on: Sep 6, 2018
 *      Author: psadm2
 */

#ifndef PSUTILS_H_
#define PSUTILS_H_
#include <fstream>
#include "Appserver.h"

class PSutils {
public:
	static std::ofstream& GetStream()
	{
		static std::ofstream myfile_output("peoplesoftservices.out");
		return myfile_output;
	}

	void buildarg(std::string flag1, std::string flag2, std::string flag3);
	void wrapper(std::string term1, std::string term2, std::string term3);
	int spawn(char* program, char** arg_list);
	PSutils();
	~PSutils();
};

#endif /* PSUTILS_H_ */
