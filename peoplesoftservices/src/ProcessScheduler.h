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
	void status(std::string environment, std::string server, std::string action, std::string prcs_server, std::string prcs_status);
	void start(std::string environment, std::string server, std::string action, std::string prcs_server, std::string prcs_start);
	void stop(std::string environment, std::string server, std::string action, std::string prcs_server, std::string prcs_stop);
	void restart(std::string environment, std::string server, std::string action, std::string prcs_server, std::string prcs_restart);
	ProcessScheduler();
	~ProcessScheduler();
};

#endif /* PROCESSSCHEDULER_H_ */
