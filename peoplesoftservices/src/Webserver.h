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
	void status();
	void start();
	void stop();
	void restart();
	Webserver();
	~Webserver();
};

#endif /* WEBSERVER_H_ */
