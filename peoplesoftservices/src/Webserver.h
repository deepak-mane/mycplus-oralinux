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
//	std::string env;
//	std::string server;
//	std::string action;

public:
	void status();
	void start();
	void stop();
	void restart();

};

#endif /* WEBSERVER_H_ */
