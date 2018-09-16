/*
 * Webserver.h
 *
 *  Created on: Sep 6, 2018
 *      Author: psadm2
 */

#ifndef WEBSERVER_H_
#define WEBSERVER_H_

//#include "PSutils.h"

class Webserver {
private:
	bool Webserver_status;

public:
	void status(std::string environment, std::string server, std::string action, std::string web_server, std::string web_status);
	void start(std::string environment, std::string server, std::string action, std::string web_server, std::string web_start);
	void stop(std::string environment, std::string server, std::string action, std::string web_server, std::string web_stop);
	void restart(std::string environment, std::string server, std::string action, std::string web_server, std::string web_restart);
	Webserver();
	~Webserver();
};

#endif /* WEBSERVER_H_ */
