/*
 * Appserver.h
 *
 *  Created on: Sep 6, 2018
 *      Author: psadm2
 */

#ifndef APPSERVER_H_
#define APPSERVER_H_
#include "PSutils.h"


//class Appserver: public PSutils {
class Appserver {
private:
	bool Appserver_status;


public:
	void status(std::string environment, std::string server, std::string action, std::string app_server, std::string app_status);
	void start(std::string environment, std::string server, std::string action, std::string app_server, std::string app_start);
	void stop(std::string environment, std::string server, std::string action, std::string app_server, std::string app_stop);
	void restart(std::string environment, std::string server, std::string action, std::string app_server, std::string app_restart);
	Appserver();
	~Appserver();
};

#endif /* APPSERVER_H_ */
