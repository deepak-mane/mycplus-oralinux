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
	bool ProcessScheduler_status;

public:
	void status();
	void start();
	void stop();
	void restart();
	ProcessScheduler();
	~ProcessScheduler();
};

#endif /* PROCESSSCHEDULER_H_ */
