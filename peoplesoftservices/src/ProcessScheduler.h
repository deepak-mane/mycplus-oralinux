/*
 * ProcessScheduler.h
 *
 *  Created on: Sep 6, 2018
 *      Author: psadm2
 */

#ifndef PROCESSSCHEDULER_H_
#define PROCESSSCHEDULER_H_

#include "PSutils.h"

class ProcessScheduler {
private:
//	std::string env;
//	std::string server;
//	std::string action;

public:
	void status();
	void start();
	void stop();
	void restart();

};

#endif /* PROCESSSCHEDULER_H_ */
