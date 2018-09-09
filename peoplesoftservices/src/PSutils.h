/*
 * PSutils.h
 *
 *  Created on: Sep 6, 2018
 *      Author: psadm2
 */

#ifndef PSUTILS_H_
#define PSUTILS_H_
#include "Appserver.h"

class PSutils {
public:
	int spawn(char* program, char** arg_list);
	PSutils();
	~PSutils();
};

#endif /* PSUTILS_H_ */
